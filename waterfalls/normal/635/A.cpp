#include <bits/stdc++.h>
using namespace std;

int r,c,n,k;
int has[13][13];

int main() {
	scanf("%d%d%d%d",&r,&c,&n,&k);
	for (int i=0;i<n;i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		has[x][y] = 1;
	}
	int ans = 0;
	for (int i=1;i<=r;i++) for (int j=i;j<=r;j++) {
		for (int p=1;p<=c;p++) for (int q=p;q<=c;q++) {
			int cur = 0;
			for (int a=i;a<=j;a++) for (int b=p;b<=q;b++) {
				cur+=has[a][b];
			}
			if (cur>=k) ans+=1;
		}
	}
	printf("%d\n",ans);

	return 0;
}