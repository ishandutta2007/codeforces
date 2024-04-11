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
const int MOD = 1e9+7;
ll get(int x){
	if(x==0) return 1;
	ll ans =1;
	if(x%2) ans =2;
	ll z = get(x>>1);
	z*=z;
	z%=MOD;
	return ans*z%MOD;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int a,b;cin>>a>>b;
	if(b%a!=0) {cout<<0;return 0;}
	b/=a;
	if(b==1) {cout<<1;return 0;}
	int zz = sqrt(b);
	vector<int> p,p2;

	int pw[10]={0};
	repA(i,2,zz){
		if(b%i==0){
			p.pb(i);
			ll aise = 1;
			while(b%i==0){
				pw[sz(p)-1]++;
				b/=i;
				aise*=i;
			}
			p2.pb(aise/i);
		}
	}
	if(b!=1) {p.pb(b);p2.pb(1);pw[sz(p)-1]++;}
	int z = (1<<sz(p));
	ll fns = 0;
	while(z){
		z--;
		int tk[sz(p)]={0},cnt=0;
		ll tt = 1;	
		rep(i,sz(p)) {
			if(z&(1<<i)) {cnt++;tt*=p2[i];}
			else {tt*=p2[i]*p[i];}
			
		}
		ll ans = get(tt-1);
		if(cnt%2) fns-=ans;
		else fns+=ans;
		fns%=MOD;
	}
	cout<<(fns+MOD)%MOD;
	return 0;
}