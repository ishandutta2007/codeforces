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
int n,l,w;
bool chk(int xa,int xb){
	if(xa>xb) return 0;
	if(1ll*w*(xb-xa)+2ll*w*l>xa+xb) return 1;
	return 0;
}
ll solve(vi& a,vi& b){
	sort(all(a));
	sort(all(b));
	ll ans = 0;
	int j =0;
	trav(i,b){
		while(j<sz(a)&&chk(a[j],i)) j++;
		ans+=j;
	}
	return ans;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	cin>>n>>l>>w;
	ll ans = 0;
	vi v1,v2,v3,v4;
	rep(i,n){
		int x,v;cin>>x>>v;
		if(v==1) x+=l;
		if(v==1&&x>=0) v1.pb(x);
		else if(v==1&&x<0) v2.pb(-x);
		else if(x>=0) v3.pb(x);
		else v4.pb(-x);
	}
	ans+=1ll*sz(v2)*sz(v3);
	ans+=solve(v1,v3);
	ans+=solve(v4,v2);
	cout<<ans;
	return 0;
}