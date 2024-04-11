#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second


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
vi g[64],gg[64];
int dx[8] = { 1,2,2,1,-1,-2,-2,-1};
int dy[8] = { 2,1,-1,-2,-2,-1,1,2};
bool vis[64],used[64],don[64];
void pre(){
	rep(i,64){
		int x = i/8,y = i%8;
		rep(j,8){
			int xx = x+dx[j],yy = y+dy[j];
			int k = -1;
			if(xx>=0&&xx<8&&yy>=0&&yy<8) k = xx*8+yy;
			if(k!=-1){
				g[i].pb(k);
				g[k].pb(i);
			}
		}
	}
}

vector<pair<pair<char,int>, pair<char,int> > > fin;
void pr(int u,int v){
	fin.pb(mp(mp(char((u%8)+'a'), (u/8+1)), mp(char((v%8)+'a'), (v/8+1))));
	//cout<<char((u%8)+'a')<<(u/8+1)<<'-'<<char((v%8)+'a')<<(v/8+1)<<'\n';
}
vector<pii> ans;
bool solve(int v){
	vis[v] = 1;
	if(used[v]&&!don[v]) {
		used[v] = 0;
		return true;
	}
	trav(i,gg[v]){
			if(solve(i)){
			    ans.pb(mp(i,v));
				if(!don[v]){
					while(sz(ans)){
						pr(ans.back().fst,ans.back().snd);
						ans.pop_back();
					}
				}
				return true;
			}
	}
	return 0;
}
void bfs(int v){
	queue<int> q;
	vis[v] = 1;
	q.push(v);
	while(!q.empty()){
		int z = q.front();
		q.pop();
		trav(i,g[z]){
			if(!vis[i]){
				gg[z].pb(i);
				vis[i] = 1;
				q.push(i);
			}
		}
	}
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	rep(i,n){
		char c;int z;
		cin>>c>>z;
		int pos= int(c-'a')+(z-1)*8;
		used[pos] = 1;
	}
	rep(i,n){
		fill(vis);
		rep(i,64) gg[i].clear();
		bfs(i);
		solve(i);
		don[i] = 1;
	}
	cout<<fin.size()<<endl;
	rep(i,fin.size()){
		cout<<fin[i].X.X<<fin[i].X.Y<<"-"<<fin[i].Y.X<<fin[i].Y.Y<<endl;
	}
	return 0;
}