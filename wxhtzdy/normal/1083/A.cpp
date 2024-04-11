#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cerr.tie(0)
#define mp make_pair
#define xx first
#define yy second
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define all(x) (x).begin(),(x).end()
#define inv(n) power((n), mod - 2)
#define ff(i,a,b) for (int (i) = (a); (i) < (b); (i)++)
#define fff(i,a,b) for (int (i) = (a); (i) <= b; (i)++)
#define bff(i,a,b) for (int (i) = (b)-1; (i) >= (a); (i)--)
#define bfff(i,a,b) for (int (i) = (b); (i) >= (a); (i)--)
#define sum_overflow(a,b) __builtin_add_overflow_p (a, b, (__typeof__ ((a) + (b))) 0)
#define mul_overflow(a,b) __builtin_mul_overflow_p (a, b, (__typeof__ ((a) + (b))) 0)

using namespace std;
long double typedef ld;
unsigned int typedef ui;
long long int typedef li;
pair<int,int> typedef pii;
pair<li,li> typedef pli;
pair<ld,ld> typedef pld;
vector<vector<int>> typedef graph;
unsigned long long int typedef ull;
//const int mod = 998244353;
const int mod = 1000000007;

using namespace __gnu_pbds;
template <class T> using oset = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
template <class T> using omset = tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;







//Note to self: Check for overflow

int a[300005];
li dp[300005][2];
vector<vector<pii>> g(300005);
li ans;

void dfs(int u,int p)
{
    vector<li> paths;
    for (auto it : g[u])
    {
        if (it.xx==p) continue;
        dfs(it.xx,u);
        paths.pb(dp[it.xx][0]-it.yy);
    }
    sort(all(paths));
    reverse(all(paths));
    if (paths.empty())dp[u][0]=dp[u][1]=a[u];
    else if (paths.size()==1)dp[u][0]=dp[u][1]=a[u]+max(0LL,paths[0]);
    else dp[u][1]=a[u]+max(0LL,paths[0])+max(0LL,paths[1]),dp[u][0]=a[u]+max(0LL,paths[0]);
    ans=max(ans,dp[u][1]);
}

int main()
{
    FAST;

    int n;
    cin>>n;
    ff(i,0,n)cin>>a[i];
    ff(i,0,n-1)
    {
        int u,v,w;
        cin>>u>>v>>w;
        --u,--v;
        g[u].pb(mp(v,w)),g[v].pb(mp(u,w));
    }
    dfs(0,0);
    cout<<ans<<"\n";
}

//Note to self: Check for overflow