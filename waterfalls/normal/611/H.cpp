#include <bits/stdc++.h>
using namespace std;

int n,d;
int inc[6], on[6], has[6];
int edges[6][6];

bool check() {
	for (int i=1;i<(1<<d)-1;i++) {
		int sizes = 1;
		for (int j=0;j<d;j++) if (i&(1<<j)) sizes+=has[j];
		for (int j=0;j<d;j++) if (!(i&(1<<j)) && inc[j]) {
			sizes-=1;
			break;
		}
		for (int j=0;j<d;j++) for (int k=j;k<d;k++) {
			if ((i&(1<<j)) || (i&(1<<k))) sizes-=edges[j][k];
		}
		if (sizes>0) return false;
	}
	return true;
}

int main() {
	scanf("%d",&n);
	d = to_string(n).size();
	char one[10], two[10];
	for (int i=0;i<n-1;i++) {
		scanf(" %s %s",&one,&two);
		if (strlen(one)>strlen(two)) swap(one,two);
		edges[strlen(one)-1][strlen(two)-1]+=1;
	}
	on[0] = 1;
	for (int i=1;i<d;i++) on[i] = on[i-1]*10;
	inc[0] = 1;
	on[0]+=1;
	for (int i=0;i<d;i++) has[i] = on[i+1]-on[i];
	has[d-1] = n-on[d-1]+1;
	if (!check()) return printf("-1\n"), 0;
	for (int r=0;r<n;r++) {
		for (int i=0;i<d;i++) for (int j=0;j<d;j++) {
			int& edge = edges[min(i,j)][max(i,j)];
			if (inc[i] && has[j] && edge) {
				has[j]-=1;
				edge-=1;
				bool add = !inc[j];
				if (add) inc[j] = on[j];
				if (check()) printf("%d %d\n",inc[i],on[j]++);
				else {
					if (add) inc[j] = 0;
					has[j]+=1;
					edge+=1;
				}
			}
		}
	}

	return 0;
}