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

int n;
int dep[300005];
li ans[300005];
vector<int> g[300005];
vector<pii> qq[300005];

li st[1200005];
void Upd(int node,int l,int r,int ll,int rr,int x)
{
    if(l>r||l>rr||r<ll)return;
    if(ll<=l&&r<=rr){st[node]+=x;return;}
    int mid=(l+r)/2;
    Upd(node*2,l,mid,ll,rr,x),Upd(node*2+1,mid+1,r,ll,rr,x);
}

li Get(int node,int l,int r,int x)
{
    if(l==r)return st[node];
    int mid=(l+r)/2;
    if(x<=mid)return st[node]+Get(node*2,l,mid,x);
    else return st[node]+Get(node*2+1,mid+1,r,x);
}

void dfs(int u,int p)
{
    dep[u]=dep[p]+1;
    for(auto x:qq[u]) Upd(1,1,n,dep[u],min(n,dep[u]+x.xx),x.yy);
    ans[u]=Get(1,1,n,dep[u]);
    for(int v:g[u])
        if(v!=p) dfs(v,u);
    for(auto x:qq[u]) Upd(1,1,n,dep[u],min(n,dep[u]+x.xx),-x.yy);
}

int main()
{
    FAST;

    cin>>n;
    ff(i,0,n-1)
    {
        int u,v;
        cin>>u>>v;
        g[u].pb(v),g[v].pb(u);
    }

    int m;
    cin>>m;
    ff(i,0,m)
    {
        int v,d,x;
        cin>>v>>d>>x;
        qq[v].pb(mp(d,x));
    }

    dfs(1,0);

    fff(i,1,n)cout<<ans[i]<<" ";
}

//Note to self: Check for overflow