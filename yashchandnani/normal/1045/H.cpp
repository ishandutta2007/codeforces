#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;


#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

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
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll mod = 1e9+7;
ll f[400009],inv[400009];
ll gcd(ll a, ll b) { return __gcd(a, b); }

ll euclid(ll a, ll b, ll &x, ll &y) {
		if (b) { ll d = euclid(b, a % b, y, x);
					return y -= a/b * x, d; }
			return x = 1, y = 0, a;
}
ll modInverse(ll a,ll p){
		ll x,y;
			euclid(a,p,x,y);
				return ((x%p+p)%p);
}
void pre(){
	f[0]=f[1]=inv[0]=inv[1] = 1;
	repA(i,2,400000){
		f[i] = f[i-1]*i%mod;
		inv[i] = inv[i-1]*modInverse(i,mod)%mod;
	}
}
ll C(int n,int r){
	if(n==r) return 1;
	if(r<0||r>n) return  0;
	return f[n]*inv[r]%mod*inv[n-r]%mod;
}
int solve(string s,int a,int b,int c,int d){
	if(c!=b&&c!=b+1) return 0;
	if(sz(s)>a+b+c+d+1){
		ll ans = C(a+c-1,c-1)*C(d+b,b)%mod;
		return ans%mod;
	}
	if(sz(s)<a+b+c+d+1) return 0;
	int ix = 0;
	vi al(b+c+1,0);
	int l = 0;
	while(ix<sz(s)&&l<b+c+1){
		while(ix+1<sz(s)&&s[ix+1]==s[ix]) al[l]++,ix++;
		l++;ix++;
	}
	ll ans = 0;
	int t = b+c+1;
	rep(i,t){
		int ch = 1-(i%2);
		if(ch){
			ans+=1ll*C(a+c-1,c-1)*((C(d+b,b)-C(d-al[i]+b,b)+mod)%mod)%mod;
			ans%=mod;
			d-=al[i];
			c--;
		}
		else{
			ans+=1ll*C(d+b-1,b-1)*((C(a-al[i]-1+c,c)))%mod;
			ans%=mod;
			a-=al[i];
			b--;
		}
		if(d<0||a<0) break;
	}
	if(d==0&&a==0) ans++;
	return ans%mod;
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	string s,t;cin>>s>>t;
	swap(s,t);
	int a,b,c,d;cin>>a>>b>>c>>d;
	ll ans = solve(s,a,b,c,d);
	int lix = sz(t);
	repD(i,sz(t)-1,0){
		if(t[i]=='1') {lix = i;break;}
	}
	{
		t[lix] = '0';
		repA(i,lix+1,sz(t)-1){
			t[i] = '1';
		}
		if(t[0] == '0' ) t = t.substr(1,sz(t)-1);
		ans-= solve(t,a,b,c,d);
		ans = (ans+mod)%mod;
		cout<<ans;
	}
	return 0;
}