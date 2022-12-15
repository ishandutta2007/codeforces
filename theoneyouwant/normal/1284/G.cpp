//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define memreset(a) memset(a,0,sizeof(a))
#define testcase(t) int t;cin>>t;while(t--)
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i=0;i<e;++i)
#define forsn(i,s,e) for(int i=s;i<e;++i)
#define rforn(i,s) for(int i=s;i>=0;--i)
#define rforsn(i,s,e) for(int i=s;i>=e;--i)
#define bitcount(a) __builtin_popcount(a) // set bits (add ll)
#define ln '\n'
#define getcurrtime() cerr<<"Time = "<<((double)clock()/CLOCKS_PER_SEC)<<endl
#define dbgarr(v,s,e) cerr<<#v<<" = "; forsn(i,s,e) cerr<<v[i]<<", "; cerr<<endl
#define inputfile freopen("input.txt", "r", stdin)
#define outputfile freopen("output.txt", "w", stdout)
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) { cerr<<endl; }
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << "\t"; err(++it, args...);
}
template<typename T1,typename T2>
ostream& operator <<(ostream& c,pair<T1,T2> &v){
	c<<"("<<v.fi<<","<<v.se<<")"; return c;
}
template <template <class...> class TT, class ...T>
ostream& operator<<(ostream& out,TT<T...>& c){
    out<<"{ ";
    forstl(x,c) out<<x<<" ";
    out<<"}"; return out;
}
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> p64;
typedef pair<int,int> p32;
typedef pair<int,p32> p96;
typedef vector<ll> v64;
typedef vector<int> v32; 
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p32> vp32;
typedef vector<p64> vp64;
typedef vector<vp32> vvp32;
typedef map<int,int> m32;
const int LIM=805,MOD=1e9+7;
const ld EPS = 1e-9;

int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=(xx<<3)+(xx<<1)+ch-'0';ch=getchar();}
    return xx*ff;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct groundset{
	int from;
	int to;
	bool in_ind_set;
	bool in_y1;
	bool in_y2;
	int bfs_par;
	groundset(){
		from = 0;
		to = 0;
		in_ind_set = 0;
		in_y1 = 0;
		in_y2 = 0;
		bfs_par = 0;
	}
};

vector<groundset> v;
v32 ind_set;
int n, m;
int c[21][21];
int cov[21][21];
int link[405];
int sz[405];
int comp[405];
v32 adj[405];
int tin[405], tout[405];
int in_out_t;
bool visited[405];

int find(int x){
	if(x == link[x]) return x;
	return link[x] = find(link[x]);
}
void unite(int a, int b){
	a = find(a);
	b = find(b);
	if(a==b) return;
	if(sz[a]<sz[b]) swap(a,b);
	sz[a]+=sz[b];
	link[b]=a;
}

int conv(int i, int j){
	return i*m + j;
}

p32 revcon(int val){
	p32 ans;
	ans = mp(val/m, val%m);
	return ans;
}

bool is_black(p32 p){
	if((p.fi == 0) && (p.se == 0)) return 0;
	if((p.fi+p.se)%2==0) return 1;
	return 0;
}

void dfs(int node){
	visited[node] = 1;
	tin[node] = in_out_t++;
	forstl(r,adj[node]){
		if(visited[r]) continue;
		unite(r,node);
		dfs(r);
	}
	tout[node] = in_out_t++;
}

void prep_graphic_matroid(){
	forn(i,n*m) adj[i].clear();
	forstl(r,ind_set){
		adj[v[r].from].pb(v[r].to);
		adj[v[r].to].pb(v[r].from);
	}
	forn(i,n*m){
		tin[i] = -1;
		tout[i] = -1;
		link[i] = i;
		sz[i] = 1;
		visited[i] = 0;
		comp[i] = 0;
	}
	in_out_t = 0;
	forn(i,n*m){
		if(!visited[i]) dfs(i);
	}
	forn(i,n*m){
		comp[i] = find(i);
	}
	return;
}

bool can_add_graphic(int id){
	int from = v[id].from;
	int to = v[id].to;
	return (comp[from] != comp[to]);
}

bool is_anc(int node1, int node2){
	// is node1 ancestor of node2 
	// assumed that they are in the same component
	if(tin[node2]>=tin[node1] && tout[node2]<=tout[node1]) return 1;
	return 0;
}

bool can_exchange_graphic(int id1, int id2){
	int f1 = v[id1].from, t1 = v[id1].to;
	int f2 = v[id2].from, t2 = v[id2].to;

	assert(comp[f2] == comp[t2]);
	
	if(comp[f1] != comp[t1]) return 1;
	if(comp[f1] != comp[f2]) return 0;
	// we know f1, t1, f2, t2 are in the same component
	int num_anc_1 = 0;
	if(is_anc(f2,t2)) swap(f2,t2);
	// make f2 descendant of t2
	if(is_anc(f2,f1)) num_anc_1++;
	if(is_anc(f2,t1)) num_anc_1++;
	if(num_anc_1 == 1) return 1;
	return 0;
}

void prep_uniform_matroid(){
	forn(i,n){
		forn(j,m){
			cov[i][j] = 0;
		}
	}
	forstl(r,ind_set){
		// v[r] is the element here
		p32 from = revcon(v[r].from);
		p32 to = revcon(v[r].to);
		if(is_black(from)) cov[from.fi][from.se]++;
		if(is_black(to)) cov[to.fi][to.se]++;
	}
	return;
}

bool can_add_uniform(int id){
	// can we add v[id] to ind set
	p32 from = revcon(v[id].from);
	p32 to = revcon(v[id].to);
	p32 blk = from;
	if(!is_black(from)) blk = to;
	if(!is_black(to) && !is_black(from)) return 0;
	if(cov[blk.fi][blk.se]<2) return 1;
	return 0;
}

bool can_exchange_uniform(int id1, int id2){
	// can we use id1 instead of id2
	p32 f1 = revcon(v[id1].from), t1 = revcon(v[id1].to);
	p32 f2 = revcon(v[id2].from), t2 = revcon(v[id2].to);
	p32 act1 = f1, act2 = f2;
	if(!is_black(f1)) act1 = t1;
	if((!is_black(t1)) && !is_black(f1)) return 0;
	if(cov[act1.fi][act1.se]<2) return 1;
	if(!is_black(f2)) act2 = t2;
	return (act1 == act2);
}

void print(int id){
	p32 from = revcon(v[id].from);
	p32 to = revcon(v[id].to);
	cout<<" "<<from.fi<<" "<<from.se<<" "<<to.fi<<" "<<to.se<<" ";
}

bool augment(){

	// reset everything, in_y1, in_y2 to 0
	// put stuff in ind_set
	// prepare matroids
	// run augment
	// check if there was a path

	int start = -3;
	int endpt = -2;
	int not_vis = -1;
	ind_set.clear();

	forn(i,v.size()){
		v[i].in_y1 = 0;
		v[i].in_y2 = 0;
		v[i].bfs_par = not_vis;
		if(v[i].in_ind_set) ind_set.pb(i);
	}

	prep_uniform_matroid();
	prep_graphic_matroid();

	queue<int> q;

	forn(i,v.size()){
		if(v[i].in_ind_set) continue;
		if(can_add_uniform(i)){
			v[i].bfs_par = start;
			v[i].in_y1 = 1;
			q.push(i);
		}
		if(can_add_graphic(i)){
			v[i].in_y2 = 1;
		}
	}

	int end = endpt;

	while(!q.empty()){
		int t = q.front();
		q.pop();

		// cout<<t<<" "<<v[t].from<<" "<<v[t].to<<ln;
		if(v[t].in_ind_set){
			// it is in independent set
			// we must check for swapping of colours
			forn(i,v.size()){
				if(v[i].bfs_par != not_vis) continue; // already visited
				if(v[i].in_ind_set) continue; // no use
				if(!can_exchange_uniform(i,t)) continue;
				// now, we can exchange & not in ind set
				// if(run == 28){
				// 	cout<<"from ";
				// 	print(t);
				// 	cout<<ln;
				// 	cout<<"we visit ";
				// 	print(i);
				// 	cout<<ln;
				// }
				q.push(i); 
				v[i].bfs_par = t;
			}
		}
		else{
			// it is not in independent set
			// if in y2, just immediately break
			if(v[t].in_y2){
				end = t;
				break;
			}
			// else, take things in ind set
			forn(i,v.size()){
				if(v[i].bfs_par != not_vis) continue;
				if(!v[i].in_ind_set) continue;
				if(!can_exchange_graphic(t,i)) continue;
				// if(run == 28){
				// 	cout<<"from ";
				// 	print(t);
				// 	cout<<ln;
				// 	cout<<"we visit ";
				// 	print(i);
				// 	cout<<ln;
				// }
				q.push(i);
				v[i].bfs_par = t;
			}
		}
	}

	if(end == endpt) return 0;
	while(true){
		v[end].in_ind_set ^= 1;
		end = v[end].bfs_par;
		if(end == start) break;
	}
	return 1;
}

int main(){
	fastio;
	int tests = 1;
	cin>>tests;
	
	while(tests--){

		// groundset of edges
		// (i,j) spawns two edges: to right and down
		// edges are numbered 2*conv(i,j), 2*conv(i,j)+1

		v.clear();

		cin>>n>>m;
		int curr = 0;
		forn(i,n){
			forn(j,m){
				char x; cin>>x;
				if(x == 'O'){
					c[i][j] = 1;
				}
				else{
					c[i][j] = 0;
				}
			}
		}
		forn(i,n){
			forn(j,m){
				if(c[i][j] == 0) continue;
				if(i+1<n && c[i+1][j] == 1){
					v.emplace_back();
					v.back().from = conv(i,j);
					v.back().to = conv(i+1,j);
				}
				if(j+1<m && c[i][j+1] == 1){
					v.emplace_back();
					v.back().from = conv(i,j);
					v.back().to = conv(i,j+1);
				}
			}
		}

		while(augment());


		bool pos = 1;
		forn(i,n){
			forn(j,m){
				if((i+j)%2 == 1) continue;
				if((i==0) && (j==0)) continue;
				if(c[i][j] == 0) continue;
				// cout<<i<<" "<<j<<" "<<cov[i][j]<<ln;
				if(cov[i][j]!=2) pos = 0;
			}
		}

		if(!pos){
			cout<<"NO"<<ln;
			continue;
		}
		cout<<"YES"<<ln;

		forn(i,n*m){
			link[i] = i;
			sz[i] = 1;
		}
		forstl(r,ind_set){
			int from = v[r].from;
			int to = v[r].to;
			assert(find(from)!=find(to));
			unite(from,to);
		}

		char outp[2*n+1][2*m+1];
		forn(i,2*n+1){
			forn(j,2*m+1){
				outp[i][j] = ' ';
			}
		}
		forn(i,n){
			forn(j,m){
				if(c[i][j]) outp[2*i+1][2*j+1] = 'O';
				else outp[2*i+1][2*j+1] = 'X';
			}
		}
		forn(i,n){
			forn(j,m){
				if(c[i][j]==0) continue;
				if(i+1<n && c[i+1][j]==1){
					if(find(conv(i,j)) != find(conv(i+1,j))){
						unite(conv(i,j),conv(i+1,j));
						outp[2*i+2][2*j+1] = 'A';
					}
				}
				if(j+1<m && c[i][j+1]==1){
					if(find(conv(i,j)) != find(conv(i,j+1))){
						unite(conv(i,j),conv(i,j+1));
						outp[2*i+1][2*j+2] = 'A';
					}
				}
			}
		}
		forstl(r,ind_set){
			p32 from = revcon(v[r].from);
			p32 to = revcon(v[r].to);
			// cout<<from<<" "<<to<<ln;
			if(to.se == from.se+1){
				outp[2*from.fi+1][2*from.se+2] = 'A';
			}
			else if(to.fi == from.fi+1){
				outp[2*from.fi+2][2*from.se+1] = 'A';
			}
		}

		forsn(i,1,2*n){
			forsn(j,1,2*m){
				cout<<outp[i][j];
			}
			cout<<ln;
		}

	}

	return 0;
}