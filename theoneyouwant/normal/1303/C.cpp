//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
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
const int LIM=26,MOD=1e9+7;
const ld EPS = 1e-9;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int link[LIM] = {0};
int sz[LIM] = {0};

int find(int x){
	int a = x;
	while(x!=link[x]){
		x = link[x];
	}
	link[a] = x;
	return x;
}

void unite(int a, int b){
	a = find(a);
	b = find(b);
	if(sz[a]<sz[b]) swap(a,b);
	if(a == b) return;
	sz[a]+=sz[b];
	link[b] = a;
}

int main(){
	fastio;
	int tests;
	cin>>tests;
	
	while(tests--){

		forn(i,LIM) link[i] = i;
		forn(i,LIM) sz[i] = 1;

		string s;
		cin>>s;
		bool p = 1;
		set<int> adj[26];
		forn(i,s.length()-1){
			int a, b;
			a = s[i]-'a';
			b = s[i+1]-'a';
			adj[a].insert(b);
			adj[b].insert(a);
			unite(a,b);
		}
		map<int,v32> m;
		forn(i,26){
			m[find(i)].pb(i);
			// cout<<find(i)<<" "<<i<<ln;
		}
		v32 ans;
		int tot = 0;
		forstl(k,m){
			int edges = 0;
			bool p1 = 1;
			forstl(r,k.se){
				edges += adj[r].size();
			}
			// cout<<edges<<ln;
			if(edges != 2*(k.se.size()-1)) p1 = 0;
			// cout<<k.fi<<" "<<p<<endl;
			p &= p1;
			// cout<<k.fi<<" "<<p<<endl;
			if(p == 0) continue;
			int start = k.fi;
			forstl(r,k.se){
				if(adj[r].size() == 1) start = r;
			}
			bool visited[26] = {0};
			visited[start] = 1;
			queue<pair<int,int>> q;
			q.push(mp(start,-1));
			int height[26] = {0};
			int lastheight = -1;
			
			while(!q.empty()){
				auto t = q.front();
				q.pop();
				ans.pb(t.fi);
				if(height[t.fi] != 1+lastheight){
					p1 = 0;
					break;
				}
				lastheight = height[t.fi];
				forstl(r,adj[t.fi]){
					if(r == t.se) continue;
					else if(visited[r]){
						p1 = 0;
						break;
					}else{
						q.push(mp(r,t.fi));
						visited[r] = 1;
						height[r] = 1+height[t.fi];
					}
				}
			}
			if(tot+k.se.size() != ans.size()) p1 = 0;
			tot += k.se.size();
			p &= p1;
		}
		if(p){
			cout<<"YES"<<ln;
			forstl(r,ans){
				cout<<(char)(r+'a');
			}
			cout<<ln;
		}
		else{
			cout<<"NO"<<ln;
		}

	}

	return 0;
}