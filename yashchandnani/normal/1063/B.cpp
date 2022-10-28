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
bool valid[2009][2009],vis[2009][2009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n,m;cin>>n>>m;
	int r,c;cin>>r>>c;
	int x,y;cin>>x>>y;
	repA(i,1,n){
		repA(j,1,m){
			char z;cin>>z;
			if(z=='.') valid[i][j]=1;
		}
	}
	priority_queue<pair<pii,pii>> q;
	q.push(mp(mp(0,0),mp(r,c)));
	int ans =0;
	while(!q.empty()){
		pair<pii,pii> z = q.top();
		q.pop();
		int t = z.fst.snd;
		pii xx = z.snd;
		int mv = -z.fst.fst;
		if(vis[xx.fst][xx.snd]) continue;
		
			ans++,vis[xx.fst][xx.snd]=1;
			if(valid[xx.fst-1][xx.snd]&&!vis[xx.fst-1][xx.snd]) {	
				q.push(mp(mp(-mv,t),mp(xx.fst-1,xx.snd)));
			}
			if(valid[xx.fst+1][xx.snd]&&!vis[xx.fst+1][xx.snd]) {
				q.push(mp(mp(-mv,t),mp(xx.fst+1,xx.snd)));
			}
			{
				if(mv+t<x){
					if(valid[xx.fst][xx.snd-1]&&!vis[xx.fst][xx.snd-1]) {
						q.push(mp(mp(-mv-1,t),mp(xx.fst,xx.snd-1)));
					}
				}
			}
			{
				if(-t<y){
					if(valid[xx.fst][xx.snd+1]&&!vis[xx.fst][xx.snd+1]) {
						q.push(mp(mp(-mv-1,t-1),mp(xx.fst,xx.snd+1)));
					}
				}
			}
	}	
	cout<<ans;
	return 0;
}