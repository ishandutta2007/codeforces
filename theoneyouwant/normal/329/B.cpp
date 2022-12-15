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
const int LIM=1e6+5,MOD=1e9+7;
const ld EPS = 1e-9;

int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=(xx<<3)+(xx<<1)+ch-'0';ch=getchar();}
    return xx*ff;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int r,c;
v32 adj[LIM];
int val[LIM];
int h[LIM];

int s,t;

int calc(int i, int j){
    return i*c+j;
}

int main(){
	fastio;


	cin>>r>>c;
    char mat[r][c];



    forn(i,r){
        forn(j,c){
            cin>>mat[i][j];
            if(mat[i][j] >= '0' && mat[i][j] <= '9'){
                val[calc(i,j)] = (int)(mat[i][j]-'0');
            }
            if(mat[i][j] == 'S'){
                s = calc(i,j);
            }
            if(mat[i][j] == 'E'){
                t = calc(i,j);
            }
        }
    }

    forn(i,r){
        forn(j,c){
            if(mat[i][j] == 'T') continue;
            if(i+1<r && mat[i+1][j] != 'T'){
                adj[calc(i,j)].pb(calc(i+1,j));
                adj[calc(i+1,j)].pb(calc(i,j));
            }
            if(j+1<c && mat[i][j+1] != 'T'){
                adj[calc(i,j)].pb(calc(i,j+1));
                adj[calc(i,j+1)].pb(calc(i,j));
            }
        }
    }

    queue<int> q;
    q.push(t);

    forn(i,r*c) h[i] = MOD;

    h[t] = 0;
    bool visited[r*c] = {0};
    visited[t] = 1;

    while(!q.empty()){
        int t = q.front();
        q.pop();
        forstl(r, adj[t]){
            if(visited[r]) continue;
            visited[r] = 1;
            h[r] = h[t]+1;
            q.push(r);
        }
    }

    ll ans = 0;
    forn(i,r*c){
        if(h[i]<=h[s]) ans += val[i];
    }

    cout<<ans<<ln;
	return 0;
}