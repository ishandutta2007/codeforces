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

void pre(){


}

void solve(){


}
ll l[100009];
string s;
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	rep(i,n) cin>>l[i];
	cin>>s;
	ll x=0,y=0,z=0,w=0;
	ll st=0;
	ll ans=0;
	rep(i,n){
		if(s[i]=='G'){
			if(st<l[i]){
				ll t = min(x,l[i]-st);
				st+=t;
				x-=t;
				ans+=t;
			}
		}
		else if(s[i]=='L'){
			if(st<l[i]){
				ll t = min(x,l[i]-st);
				x-=t;
				st+=t;
				ans+=t;
			}
			if(st<l[i]){
				ll t = min(y,l[i]-st);
				st+=t;
				y-=t;
				ans+=2*t;
			}
			if(st<l[i]){
				ll t = min(z,l[i]-st);
				st+=t;
				ans+=3*t;
			}
			if(st<l[i]){
				ll t = min(w,l[i]-st);
				st+=t;
				ans+=5*t;
			}
		}
		if(s[i]=='G'){
			w=1e18;
			ll t = min(st,l[i]);
			st-=t;
			y+=2*t;
			ans+=t;
			t = l[i]-t;
			y+=t;
			ans+=3*t;
		}
		else if(s[i]=='W'){
			z = 1e18;
			ll t = min(st,l[i]);
			st-=t;
			x+=2*t;
			ans+=t;
			t = l[i]-t;
			x+=t;
			ans+=2*t;
		}
		else{
			ll t = min(st,l[i]);
			st-=t;
			ans+=t;
		}
	}
	cout<<ans;	
	
	return 0;
}