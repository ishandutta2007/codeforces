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

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	vector<pii> v(3),ans;
	rep(i,3) cin>>v[i].fst>>v[i].snd;
	sort(all(v));
	repA(i,v[0].fst,v[1].fst-1) ans.pb(mp(i,v[0].snd));
	repD(i,v[2].fst,v[1].fst+1) ans.pb(mp(i,v[2].snd));
	repA(i,min(min(v[0].snd,v[1].snd),v[2].snd),max(max(v[0].snd,v[1].snd),v[2].snd)){
		ans.pb(mp(v[1].fst,i));
	}
	sort(all(ans));
	cout<<sz(ans)<<'\n';
	trav(i,ans) cout<<i.fst<<' '<<i.snd<<'\n';
	return 0;
}