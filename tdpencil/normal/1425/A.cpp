#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
typedef vector<ll> vl;
#define REP(i, a, b) for (int i = 0; i <= int(b); i++)
#define TRvi(c, it) for(vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) for(vii:iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) for(msi::iterator it = (c).begin(); it != (c).end(); it++)
#define INF 2000000000
#define MEMSET_INF 127
#define MEMSET_HALF 63
#define PB push_back
int _;
ll n;
ll solve(ll x){
	ll res=0;
	if (!x) return 0;
	while (x>4)
	if (x%4){
		res+=x/2;
		x=x/2-1;
	}
	else res++,x-=2;
	res+=x-1;
	return res;
}
int main(){
	for (scanf("%d",&_);_;_--){
		scanf("%lld",&n);
		printf("%lld\n",n&1?n-solve(n-1):solve(n));
	}
	return 0;
}