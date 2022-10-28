#include <bits/stdc++.h>
using namespace std;

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
ll prs[1000009],req[1000009];
ll gcd(ll a, ll b) { return __gcd(a, b); }

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (b) { ll d = euclid(b, a % b, y, x);
		return y -= a/b * x, d; }
	return x = 1, y = 0, a;
}
ll modInverse(ll a,ll p){
	if(a==1) return  1ll;
	ll x,y;
	euclid(a,p,x,y);
	return ((x%p+p)%p);
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int a,b,p;ll x;cin>>a>>b>>p>>x;
	ll z = a;int pr = 1;
	prs[1] = a;
	req[1] = 1ll*modInverse(z,p)*b%p;
	while(z!=1){
		z*=a;z%=p;pr++;
		prs[pr] = z;
		req[pr] = 1ll*modInverse(z,p)*b%p;
	}
	ll fns = 0;
	ll zz = modInverse(pr,p);
	repA(i,1,pr){
		ll tot = x/pr;
		if(x%pr>=i) tot++;
		tot--;
		req[i]-=i;
		req[i]=(req[i]%p+p)%p;
		req[i]=req[i]*zz;
		req[i]=(req[i]%p+p)%p;
		fns+=tot/p;
		if(tot%p>=req[i]) fns++;
	}
	cout<<fns;

	
	return 0;
}