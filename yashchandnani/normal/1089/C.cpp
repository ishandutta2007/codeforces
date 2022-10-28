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

bitset<500> b[500][500];
vi g[509];
int d[509][509];
bool vis[509];
void solve(int i){
	fill(vis);
	queue<int> q;
	q.push(i);vis[i] = 1;
	while(!q.empty()){
		int z= q.front();
		q.pop();
		trav(j,g[z]){
			if(!vis[j]){
				d[i][j] = d[i][z]+1;
				vis[j]=1;
				q.push(j);
			}
		}
	}
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n,m;cin>>n>>m;
	rep(i,m){
		int k;cin>>k;
		int u;cin>>u;u--;
		rep(j,k-1){
			int v;cin>>v;v--;
			g[u].pb(v);
			g[v].pb(u);
			u = v;
		}
	}
	rep(i,n) solve(i);	
	rep(i,n){
		trav(j,g[i]){
			rep(k,n){
				if(d[i][k]<d[j][k]) b[j][i][k]=1;
				else if(d[j][k]<d[i][k]) b[i][j][k]=1;
			}
		}
	}
	rep(i,n){
		bitset<500> bb;
		rep(i,n) bb[i] = 1;
		int cnt = n;
		while(cnt){
			if(cnt==1){
				rep(i,n){
					if(!bb[i]) continue;
					cout<<i+1<<endl;
					string s;cin>>s;
					cnt--;
					break;
				}
			}
			else{
				vi poss;
				rep(i,n) if(bb[i]) poss.pb(i);
				int q = -1;
				trav(j,poss){
					bool fg = 0;
					trav(k,g[j]){
						if(!bb[k]) continue;
						int cur = 0;
						trav(l,poss){
							if(b[j][k][l]) cur++;
						}
						if(cur>cnt/2) {
							fg=1;
							break;
						}
					}
					if(!fg){
						q = j+1;
						break;
					}
				}
				assert(q>0);
				cout<<q<<endl;
				string s;cin>>s;
				if(s=="FOUND"){
					break;
				}
				else{
					int x;cin>>x;
					bb=bb&b[q-1][x-1];
					cnt = 0;
					rep(i,n) if(bb[i]) cnt++;
				}
			}
		}
	}
	
	return 0;
}