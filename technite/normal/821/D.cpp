//#ifndef _SUBLIME
//#pragma GCC optimize ("Ofast")
//#pragma GCC target ("avx,avx2")
//#endif
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define endl "\n"
#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
// #define int long long
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef vector<pii> vpi;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define d0(x) cout<<(x)<<" "
#define d1(x) cout<<(x)<<endl
#define d2(x,y) cout<<(x)<<" "<<(y)<<endl
#define d3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl
#define d4(a,b,c,d) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<endl
#define d5(a,b,c,d,e) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<" "<<(e)<<endl
#define d6(a,b,c,d,e,f) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<" "<<(e)<<" "<<(f)<<endl
//2d grids
int mv_x[]={1,-1,0,0};
int mv_y[]={0,0,1,-1};
char dir[]={'D','U','R','L'};
bool desc_sort(const int & lhs,const int & rhs)
{
    return lhs>rhs;
}
bool desc_pii_sort(const pii & lhs , const pii & rhs)
{
    return lhs>rhs;
}
bool second_sort(const pii & lhs , const pii & rhs)
{
    pii a,b;
    a.F = lhs.S;
    a.S = lhs.F;
    b.F = rhs.S;
    b.S = rhs.F;
    return a<b;
}
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ ";
    for(auto v : V) os << v << " ";
    return os << "]";
}
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") ";
    return os<<"}";
}
#define TRACE
#ifdef TRACE
    #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " : " << arg1 << endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ',');
        cerr.write(names, comma - names) << " : " << arg1<<" | ";
        __f(comma+1, args...);
    }
#else
    #define trace(...)
#endif


// #define int long long
#define modd 998244353


template <typename K, typename V, typename Comp = std::less<K>>
using order_statistic_map = __gnu_pbds::tree<
    K, V, Comp,
    __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update
>;

template <typename K, typename Comp = std::less<K>>
using order_statistic_set = order_statistic_map<K, __gnu_pbds::null_type, Comp>;

// Supports
//  auto iterator = order_statistic_set().find_by_order(idx); // (0-indexed)
//  int num_strictly_smaller = order_statistic_set().order_of_key(key);

inline ll fast_expo(ll base,ll power,ll modulo=modd){
    base%=modulo;
    if (base<0LL) base+=modulo;
    ll x=base,cnt=power,ans=1LL;
    while(cnt){
        if (cnt&1LL) ans=(ans*x)%modulo;
        x=(x*x)%modulo;
        cnt>>=1LL;
    }
    // int tmp=ans;
    return ans;
}
inline ll inv(ll base,ll modulo=modd){
    return fast_expo(base,modulo-2LL,modulo);
}

const int MAXN = 1e5 + 10;
 
int n, m, k, x[MAXN], y[MAXN], q[MAXN], lv[MAXN];
bool mark[MAXN];
vector<pii> adj[MAXN];

signed main()
{
    #ifdef _SUBLIME
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    #endif
    fio;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++){
        cin >> x[i] >> y[i], x[i]--, y[i]--;
        adj[i].push_back({k+x[i], 1});
        adj[k+x[i]].push_back({i, 0});
        adj[i].push_back({k+n+y[i], 1});
        adj[k+n+y[i]].push_back({i, 0});
        if (x[i]){
            adj[k+x[i]-1].push_back({i, 0});
            adj[i].push_back({k+x[i]-1, 1});
        }
        if (x[i] < n-1){
            adj[k+x[i]+1].push_back({i, 0});
            adj[i].push_back({k+x[i]+1, 1});
        }
        if (y[i]){
            adj[k+n+y[i]-1].push_back({i, 0});
            adj[i].push_back({k+n+y[i]-1, 1});
        }
        if (y[i] < m-1){
            adj[k+n+y[i]+1].push_back({i, 0});
            adj[i].push_back({k+n+y[i]+1, 1});
        }
    }
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
            if (i^j && abs(x[i]-x[j]) + abs(y[i]-y[j]) == 1)
                adj[i].push_back({j, 0});
 
    int source = -1;
    for (int i = 0; i < k; i++)
        if (x[i]+y[i] == 0) source = i;
 
    memset(lv, 63, sizeof(lv));
    deque<int> q;
    q.push_back(source); lv[source] = 0;
    while (q.size()){
        int v = q.front(); q.pop_front();
        if (mark[v]) continue;
        mark[v] = 1;
 
        for (auto e:adj[v])
            if (lv[e.F] > lv[v]+e.S){
                lv[e.F] = lv[v]+e.S;
                if (e.S)
                    q.push_back(e.F);
                else
                    q.push_front(e.F);
            }
    }
    
    int ans = 1e9;
    for (int i = 0; i < k; i++)
        if (x[i] == n-1 && y[i] == m-1) ans = lv[i];
    ans = min(ans, lv[k+n-1]);
    ans = min(ans, lv[k+n+m-1]);
 
    if (ans > 1e8) ans = -1;
    cout << ans << "\n";
    return 0;


}