#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

ll a, b, c;

void query(ll v) {
	printf("%lld\n",v);
	fflush(stdout);
	int t;
	scanf("%d",&t);
	if (t==1) a+=v;
	else if (t==2) b+=v;
	else c+=v;
}

int main(){
	scanf("%lld%lld%lld",&a,&b,&c);
	puts("First"); fflush(stdout);
	query(max({a,b,c}));
	ll A = max({a,b,c});
	ll S = a+b+c;
	query(3*A-S);
	query((max({a,b,c})-min({a,b,c}))/2);

	return 0;
}