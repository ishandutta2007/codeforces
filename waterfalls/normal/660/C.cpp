#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define A first
#define B second

int n,k;
int a[300013];

int main() {
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	pair<int,pair<int,int> > ans = MP(-1,MP(0,-1));
	int cur = 0;
	int r = -1;
	for (int l=0;l<n;l++) {
		while (r<n-1 && cur<=k) {
			if (cur==k && a[r+1]==0) break;
			++r;
			cur+=(a[r]==0);
		}
		ans = max(ans,MP(r-l+1,MP(l,r)));
		cur-=(a[l]==0);
	}
	printf("%d\n",ans.A);
	for (int i=0;i<n;i++) {
		if (ans.B.A<=i && i<=ans.B.B) printf("1 ");
		else printf("%d ",a[i]);
	}
	printf("\n");

	return 0;
}