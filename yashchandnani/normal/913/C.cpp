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
typedef pair<ll,ll> pii;
typedef vector<int> vi;
ll c[31];
ll req(ll z){
	if(z<=0) return 0;
	if(z==1) return c[0];
	ll zz = 1;
	int i = 0;
	while(zz<z) zz*=2,i++;
	ll ans = min(c[i],c[i-1]+req(z-zz/2));
	return ans;
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll n,l;cin>>n>>l;
	rep(i,31) c[i] = 1e18+10;
	rep(i,n) cin>>c[i];
	ll mn = c[30];
	repD(i,29,0) c[i] = mn  = min(c[i],mn);
	repA(i,1,30) c[i] = min(c[i],2*c[i-1]);
	cout<<req(l);
	return 0;
}