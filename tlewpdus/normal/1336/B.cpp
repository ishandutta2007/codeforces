#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n[3];
ll arr[3][100100];

ll getv(int a, int i, int b, int bi, int c, int ci) {
	return (arr[a][i]-arr[b][bi])*(arr[a][i]-arr[b][bi])+
		   (arr[a][i]-arr[c][ci])*(arr[a][i]-arr[c][ci])+
		   (arr[c][ci]-arr[b][bi])*(arr[c][ci]-arr[b][bi]);
}

int main() {
	int t;

	scanf("%d",&t);
	while(t--) {
		ll ans = 4e18;
		for (int i=0;i<3;i++) scanf("%d",&n[i]);
		for (int i=0;i<3;i++) {
			for (int j=0;j<n[i];j++) scanf("%lld",&arr[i][j]);
			sort(arr[i],arr[i]+n[i]);
		}
		int perm[3] = {0,1,2};
		do {
			int a = perm[0], b = perm[1], c = perm[2];
			for (int i=0;i<n[a];i++) {
				int ci = lower_bound(arr[c],arr[c]+n[c],arr[a][i])-arr[c];
				if (ci>=n[c]) continue;
				int bi = lower_bound(arr[b],arr[b]+n[b],(arr[a][i]+arr[c][ci]+1)/2)-arr[b];
				if (bi<n[b]) ans = min(ans,getv(a,i,b,bi,c,ci));
				bi = upper_bound(arr[b],arr[b]+n[b],(arr[a][i]+arr[c][ci])/2)-arr[b]-1;
				if (bi>=0) ans = min(ans,getv(a,i,b,bi,c,ci));
			}
		} while(next_permutation(perm,perm+3));
		printf("%lld\n",ans);
	}

	return 0;
}