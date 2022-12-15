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
#define forn(i,e) for(int i = 0; i < e;++i)
#define forsn(i,s,e) for(int i = s; i < e;++i)
#define rforn(i,s) for(int i = s; i >= 0;--i)
#define rforsn(i,s,e) for(int i = s; i >= e;--i)
#define bitcount(a) __builtin_popcount(a) // set bits (add ll)
#define ln '\n'
#define getcurrtime ((double)clock()/CLOCKS_PER_SEC)
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

const int LIM=2e5+5, MOD=1e9+7;
const ld EPS = 1e-9;
// int t,n,m,k,x,y,w;
int n;
vp32 adj[LIM];
ll dp[LIM][2];
ll dpu[LIM][2];
int visited[LIM];

void bfsdown(int node){
    visited[node]=1;
    // cout<<node<<ln;
    forstl(r,adj[node]){
        if(visited[r.fi]) continue;
        bfsdown(r.fi);
        if(adj[r.fi].size()==1 && r.fi!=0){
            dp[node][r.se]++;
            continue;
        }
        if(r.se==1){
            dp[node][1]+=1+dp[r.fi][1];
        }
        else if(r.se==0){  
            dp[node][0]+=1+dp[r.fi][1]+dp[r.fi][0];
            // dp[node][0]+=1+dp[r.fi][1];
            // dp[node][0]+=1+dp[r.fi][0];
        }
    }
}

void bfsup(int node, int p, bool c){

    visited[node] = 1;
        if(c==0){
            dpu[node][0] += (dpu[p][0]+dpu[p][1]+dp[p][0]+dp[p][1]-dp[node][0]-dp[node][1]);
        }
        else{
            dpu[node][1] += (dpu[p][1]+dp[p][1]-dp[node][1]);
        }
    forstl(r,adj[node]){
        if(visited[r.fi]) continue;
        bfsup(r.fi,node,r.se);
    }

}

signed main(){
    fastio;
    
    
    cin>>n;
    
    forn(i,n-1){
        int x,y,c;
        cin>>x>>y>>c;
        x--;y--;
        adj[x].pb(mp(y,c));
        adj[y].pb(mp(x,c));
    }
    forn(i,n){
        forn(j,2) dp[i][j]=0;
    }

    bfsdown(0);
    forn(i,n) visited[i]=0;
    visited[0] = 1;
    forstl(r,adj[0]){
        bfsup(r.fi,0,r.se);
    }
    ll ans=0;
    forn(i,n){
        forn(j,2){
            // cout<<i<<" "<<j<<" "<<dp[i][j]<<" "<<dpu[i][j]<<ln;
            ans+=dp[i][j];
            ans+=dpu[i][j];
        }
    }
    cout<<ans<<ln;

    return 0;
}