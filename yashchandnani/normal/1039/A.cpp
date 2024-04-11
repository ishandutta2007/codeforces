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
ll a[200009],b[200009],x[200009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	ll t;cin>>t;
	rep(i,n){
		cin>>a[i];
		b[i] = a[i]+t;
	}
	bool fg = 0;
	rep(i,n) {
		cin>>x[i];
		if(x[i]<=i) fg=1;
		if(i>0&&x[i]<x[i-1]) fg=1;
		if(i>0&&x[i-1]>i){
			b[i-1] = a[i]+t;
		}
	}
	
	rep(i,n-1){
		b[i+1] = max(b[i]+1,b[i+1]);
	}
	rep(i,n-1){
		if(x[i]<n){
			if(a[x[i]]+t<=b[x[i]-1]) fg=1;
		}
	}
	if(fg) cout<<"No";
	else{
		cout<<"Yes\n";
	rep(i,n) cout<<b[i]<<' ';
	}
	return 0;
}