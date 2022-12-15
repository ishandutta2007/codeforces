#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MN = 1e5+5, MP = 1e5;
ll n, m, i, sz[MN], pre[MN], t[MN], s[MN], lo, hi, x;

int main(){
	for(scanf("%lld",&m),i=1;i<=m;i++){
		scanf("%d",&t[i]);
		if(t[i] == 1){
			scanf("%lld",&s[i]);
			sz[i] = sz[i-1]+1;
			if(sz[i]<=MP) pre[sz[i]]=s[i];
		}
		else{
			scanf("%lld%lld",&s[i],&x);
			sz[i] = sz[i-1]+s[i]*x;
			for(ll j=sz[i-1]+1;j<=min(MP,sz[i]);j++)
				pre[j] = pre[(j-sz[i-1]-1)%s[i]+1];
		}
	}
	for(scanf("%lld",&n),i=0;i<n;i++){
		scanf("%lld",&x);
		ll p = lower_bound(sz+1, sz+m+1, x)-sz;
		if(t[p] == 1) printf("%lld ",s[p]);
		else printf("%lld ",pre[(x-sz[p-1]-1)%s[p]+1]);
	}
	return 0;
}