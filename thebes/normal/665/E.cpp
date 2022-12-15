#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MN = 1000006;
ll N, K, i, x, n, ans, tot;
int t[30*MN][2], sz[32*MN];
bool bit(ll x, ll p){return(x&(1<<p));}

void insert(ll x){
	ll p = 0;
	for(ll j=31;j>=0;j--){
		if(t[p][bit(x,j)]==0)
			t[p][bit(x,j)] = ++n;
		p = t[p][bit(x,j)]; sz[p]++;
	}
}

ll query(ll x){
	ll p = 0, r = 0;
	for(ll j=31;j>=0;j--){
		ll a = bit(x,j), b = bit(K,j);
		if((a^1)>b) r += sz[t[p][1]];
		if(a>b) r += sz[t[p][0]];
		if(t[p][a^b]==0) return r;
		p = t[p][a^b];
	}
	return r+sz[p];
}

int main(){
	insert(0LL);
	for(scanf("%lld%lld",&N,&K),i=0;i<N;i++){
		scanf("%lld",&x); tot ^= x;
		insert(tot); ans += query(tot);
	}
	printf("%lld\n",ans);
	return 0;
}