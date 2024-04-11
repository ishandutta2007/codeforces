#include <bits/stdc++.h>
using namespace std;

int n,k;
int a[500013];
int has[1000013];

int main() {
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	int best = 0;
	pair<int,int> which;
	int cur = 0;
	int r = -1;
	for (int l=0;l<n;l++) {
		while (r<n-1) {
			if (!has[a[r+1]]) cur+=1;
			has[a[r+1]]+=1;
			if (cur<=k) r+=1;
			else {
				has[a[r+1]]-=1;
				if (!has[a[r+1]]) cur-=1;
				break;
			}
		}
		if (r-l+1>best) {
			best = r-l+1;
			which = make_pair(l+1,r+1);
		}
		has[a[l]]-=1;
		if (!has[a[l]]) cur-=1;
	}
	printf("%d %d\n",which.first,which.second);

	return 0;
}