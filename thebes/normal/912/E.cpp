#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> a[2], arr, b[2];
ll n, i, x;

void rec(ll d, ll p, ll id){
	if(d ==a[id].size())
		b[id].push_back(p);
	else{
		ll prod=1;
		while(prod <= 1e18/p && prod > 0){
			rec(d+1, p*prod, id);
			prod *= a[id][d];
		}
	}
}

bool check(ll x, ll m){
	ll cnt = 0, l = b[0].size()-1, r = 0;
	for(;r<b[1].size();r++){
		while(b[0][l]>(ll)(x/b[1][r])) l--;
		if(cnt >= m-l) return 0;
		cnt += l;
	}
	return 1;
}

int main(){
	for(scanf("%lld",&n),i=0;i<n;i++){
		scanf("%lld",&x);
		a[i%2].push_back(x);
	}
	scanf("%lld",&x);
	rec(0, 1, 0); rec(0, 1, 1);
	b[0].push_back(0);
	sort(begin(b[0]), end(b[0]));
	sort(begin(b[1]), end(b[1]));
	ll lo = 1, hi = 1e18;
	while(lo < hi){
		ll m = (lo+hi)/2;
		if(check(m,x)) lo=m+1;
		else hi=m;
	}
	printf("%lld\n",hi);
	return 0;
}