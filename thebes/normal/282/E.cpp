#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MN = 1e5+5;
int t[41*MN][2]; ll N, i, x, y, ans, arr[MN], nxt;

void add(ll x){
	ll n = 0;
	for(int p=41;p>=0;p--){
		ll b = ((1LL<<p)&x)?1:0;
		if(!t[n][b]) t[n][b]=++nxt;
		n = t[n][b];
	}
}

ll qu(ll x){
	ll ret = 0, n=0;
	for(int p=41;p>=0;p--){
		ll b = ((1LL<<p)&x)?1:0;
		if(t[n][!b]) ret+=(1LL<<p);
		if(t[n][!b]) n=t[n][!b];
		else n=t[n][b];
	}
	return ret;
}

int main(){
	for(scanf("%lld",&N),i=1;i<=N;i++)
		scanf("%lld",&arr[i]),x^=arr[i];
	add(0); ans=x;
	for(i=N;i>=1;i--){
		x ^= arr[i]; y ^= arr[i];
		add(y); ans=max(ans,qu(x));
	}
	printf("%lld\n",ans);
	return 0;
}