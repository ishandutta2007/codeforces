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
typedef long double ld;
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	ll k,d,t;cin>>k>>d>>t;
	if(k%d==0) cout<<t;
	else{
	ld tt = k+1.0*(d-k%d)/2;
	ll x = k+(d-k%d);
	ll y = 1.0*t/tt;
	ld ans = x*y;
	ld tem = t - tt*y;
	if(tem<=k) ans+=tem;
	else ans+=k,ans+=2*(tem-k);
	printf("%.12Lf\n", ans);}
	//cout<<setprecision(20)<<ans;}
	return 0;
}