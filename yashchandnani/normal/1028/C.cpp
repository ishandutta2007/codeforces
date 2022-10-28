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
int x1[200000],x2[200000],yl[200000],y2[200000];
pii x[200000],y[200000];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	vi xs,ys;
	rep(i,n) cin>>x[i].fst>>y[i].fst>>x[i].snd>>y[i].snd,x1[i] = x[i].fst,x2[i] = x[i].snd,yl[i] = y[i].fst, y2[i] = y[i].snd;
	sort(x1,x1+n);
	sort(yl,yl+n);
	sort(x2,x2+n);
	sort(y2,y2+n);
	ys.pb(yl[n-1]);
	ys.pb(yl[n-2]);
	xs.pb(x1[n-1]);
	xs.pb(x1[n-2]);
	ys.pb(y2[0]);
	ys.pb(y2[1]);
	xs.pb(x2[0]);
	xs.pb(x2[1]);
	trav(k,xs) trav(j,ys){
		int cnt=0;
		rep(i,n){
			if(k>=x[i].fst&&k<=x[i].snd&&j>=y[i].fst&&j<=y[i].snd) cnt++;
		}
		if(cnt>=n-1){
			cout<<k<<' '<<j<<'\n';
		return 0;
		}
	}
	return 0;
}