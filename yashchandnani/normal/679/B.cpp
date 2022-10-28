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
typedef pair<ll,ll> pll;
typedef vector<int> vi;
map<ll,pll> fns;
pll f(ll x){
	if(fns.find(x)!=fns.end()) return fns[x];
	if(x==0) return mp(0,0);
	else if(x<8) return mp(x,x);
	ll y = cbrt(x);
	ll z  = y*y*y;
	ll w = x/z -1;
	if(w==0){
		pll ans = f(z-1);
		pll ans2 = f(x-z);
		ans2.fst++;
		ans2.snd+=z;
		if(ans2.fst>=ans.fst) {fns[x] = ans2;return ans2;}
		else {fns[x] = ans;return ans;}
	}
	ll v = w*z;
	pll ans = f(x-v);
	ans.fst+=w;
	ans.snd+=v;
	fns[x] = ans;
	return ans;
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll x;cin>>x;
	pll ans = f(x);
	cout<<ans.fst<<' '<<ans.snd<<endl;
	return 0;
}