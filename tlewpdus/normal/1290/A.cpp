#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n, m, k;
int arr[5010];
int getv(int s, int e, int l) {
	int ans = 1e9+10;
	for (int i=0;i<=l;i++) {
		ans = min(ans,max(arr[s+i],arr[e-l+i]));
	}
	return ans;
}

int main() {
	int tt;

	scanf("%d",&tt);
	while(tt--) {
		scanf("%d%d%d",&n,&m,&k);
		for (int i=0;i<n;i++) scanf("%d",&arr[i]);
		k = min(k,m-1);
		int ans = 0;
		for (int i=0;i<=k;i++) {
			ans = max(ans,getv(i,n-k-1+i,m-1-k));
		}
		printf("%d\n",ans);
	}

	return 0;
}