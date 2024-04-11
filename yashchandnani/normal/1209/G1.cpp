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
vi v[200009];
vector<pair<pii,int>> u;
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	int q;cin>>q;	
	rep(i,n){
		int x;cin>>x;
		v[x].pb(i);
	}
	repA(i,0,200000){
		if(sz(v[i])){
			u.pb(mp(mp(v[i][0],v[i].back()),sz(v[i])));
		}
	}
	sort(all(u));
	int ans = 0;
	rep(i,sz(u)){
		int j = i+1;
		int mx = u[i].fst.snd;
		int cx = u[i].snd;
		while(j<sz(u)&&u[j].fst.fst<=mx){
			mx=max(mx,u[j].fst.snd);
			cx=max(cx,u[j].snd);
			j++;
		}
		ans+=mx-u[i].fst.fst+1-cx;
		i=j-1;
	}
	cout<<ans;
	return 0;
}