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
ld dist(pair<ld,ld> a,pair<ld,ld> b){
	return sqrt((a.fst-b.fst)*(a.fst-b.fst)+(a.snd-b.snd)*(a.snd-b.snd));
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int a,b,c;cin>>a>>b>>c;
	int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
	ld ans = 1.0*abs(x1-x2)+1.0*abs(y1-y2);
	vector<pair<ld,pair<ld,ld>>> v,u;
	if(a!=0){
		v.pb(mp(abs(x1-(-1.0*b*y1-c)/a),mp((-1.0*b*y1-c)/a,y1)));
		u.pb(mp(abs(x2-(-1.0*b*y2-c)/a),mp((-1.0*b*y2-c)/a,y2)));
	}
	if(b!=0){
		v.pb(mp(abs(y1-(-1.0*a*x1-c)/b),mp(x1,(-1.0*a*x1-c)/b)));
		u.pb(mp(abs(y2-(-1.0*a*x2-c)/b),mp(x2,(-1.0*a*x2-c)/b)));
	}
	trav(i,v){
		trav(j,u){
			ans = min(ans,i.fst+j.fst+dist(i.snd,j.snd));
		}
	}
	cout<<setprecision(20)<<ans;
	return 0;
}