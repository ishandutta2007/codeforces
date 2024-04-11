#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define Foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define rof(i,a,b) for(int (i)=(a);(i) > (b); --(i))
#define rep(i, c) for(auto &(i) : (c))
#define x first
#define y second
#define pb push_back
#define PB pop_back()
#define iOS ios_base::sync_with_stdio(false)
#define sqr(a) (((a) * (a)))
#define all(a) a.begin() , a.end()
#define error(x) cerr << #x << " = " << (x) <<endl
#define Error(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
#define errop(a) cerr<<#a<<" = ( "<<((a).x)<<" , "<<((a).y)<<" )\n";
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
#define L(x) ((x)<<1)
#define R(x) (((x)<<1)+1)
#define umap unordered_map
#define double long double
typedef long long ll;
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef complex<double> point;
template <typename T> using os =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>  inline void smax(T &x,T y){ x = max((x), (y));}
template <class T>  inline void smin(T &x,T y){ x = min((x), (y));}
const int maxn = 2e5 + 10;
vi adj[maxn * 2];
int x[maxn * 2];
map <pii, int> mp;
map <pii, bool> del;
vector<int> eu;
set<int> d[2];
int deg[maxn * 2];
vector<pii> edges;
inline void euler(int v){
    while(!adj[v].empty()){
        int u = adj[v].back();
        adj[v].PB;
        if(!del[{v, u}]){
            del[{v, u}] = del[{u, v}] = true;
            euler(u);
        }
    }
    eu.pb(v);
}
inline void deledge(int v,int u){
    del[{v, u}] = true;
    del[{u, v}] = true;
    d[deg[v]].erase(v);
    deg[v] = !deg[v];
    d[deg[v]].insert(v);
    d[deg[u]].erase(u);
    deg[u] = !deg[u];
    d[deg[u]].insert(u);
}
inline void solve(){
    if(d[1].empty()){
        For(i,0,maxn * 2){
            eu.clear();
            euler(i);
            For(j,1,eu.size())
                mp[{eu[j], eu[j-1]}] = mp[{eu[j-1], eu[j]}] = j % 2;
        }
    }
    else{
        set <int>::iterator itr;
        itr = d[1].end();
        itr--;
        if (itr != d[1].begin())
            itr--;
        int v = *itr;
        while(!adj[v].empty() && del[{v, adj[v].back()}])
            adj[v].PB;
        int u = adj[v].back();
        deledge(v, u);
        solve();
        
        //cout << v << " " << u << endl;
        int c = 0;
        if(x[u] > 0)
            c = 1;
        if(c == 1)
            x[u] --, x[v] --;
        else
            x[u] ++, x[v] ++;
        mp[{v, u}] = mp[{u, v}] = c;
    }
}
int n;
string s = "rb";
int main(){
    scanf("%d", &n);
    For(i,0,n){
        int x, y;
        scanf("%d %d", &x, &y);
        -- x, -- y;
        x = 2 * x + 1;
        y = 2 * y;
        edges.pb({x, y});
        adj[x].pb(y);
        adj[y].pb(x);
    }
    For(i,0,2*maxn)
        d[(int)adj[i].size() % 2].insert(i), deg[i] = adj[i].size() % 2;
    solve();
    rep(e, edges)
        printf("%c", (char)s[mp[{e.x, e.y}]]);
    puts("");
}