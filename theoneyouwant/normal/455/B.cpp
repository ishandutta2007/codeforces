//By Tushar Gautam
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
const int LIM=1e5+5,MOD=1e9+7;
int t,n,m,k,x,y,w;
const int K = 26;
struct Vertex{
    int next[K];
    bool leaf = false;
    Vertex() {
        fill(begin(next), end(next), -1);
    }
};
vector<Vertex> trie(1);
void add_string(string const& s){
    int v = 0;
    for(char ch : s){
        int c = ch - 'a';
        trie[v].leaf = false;
        if (trie[v].next[c]==-1) {
            trie[v].next[c] = trie.size();
            trie.emplace_back();
        }
        v=trie[v].next[c];
    }
    trie[v].leaf = true;
}
bool s[(int)(26*2e5)];
bool dfs(int v){
	if(trie[v].leaf){
		s[v] = 0;
		return 0;
	}
	bool xo = 1;
	forn(i,K){
		if(trie[v].next[i]!=-1) xo &= dfs(trie[v].next[i]);
	}
	xo^=1;
	s[v] = xo;
	return xo;
}
bool dfs1(int v){
	if(trie[v].leaf){
		s[v] = 1;
		return 1;
	}
	bool xo = 1;
	forn(i,K){
		if(trie[v].next[i]!=-1) xo &= dfs1(trie[v].next[i]);
	}
	xo^=1;
	s[v] = xo;
	return xo;
}
signed main(){
	fastio;
	cin>>n>>k;
	string ss[n];
	forn(i,n) cin>>ss[i];
	sort(ss,ss+n,[&](const string &i,const string &j){
		return i.size() < j.size();
	});
	forn(i,n) add_string(ss[i]);
	dfs(0);
	bool b1 = s[0];
	dfs1(0);
	bool b2 = s[0];
	if(!b1){
		cout<<"Second\n";
		exit(0);
	}else if(k&1){
		cout<<"First\n";
		exit(0);
	}
	if(b1 and b2){
		cout<<"First\n";
	}else cout<<"Second\n";
	return 0;
}