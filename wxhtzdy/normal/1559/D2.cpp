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

int par[100005][2];
vector<int> nodes[2][100005];
oset<int> r[2];

int root(int u,int x)
{
    return par[u][x]==u?u:par[u][x]=root(par[u][x],x);
}

void unite(int u,int v,int x)
{
    u=root(u,x);
    v=root(v,x);
    if(u==v)return;
    if(nodes[x][u].size()<nodes[x][v].size())swap(u,v);
    par[v][x]=u;
    r[x].erase(r[x].find(v));
    for(auto i:nodes[x][v])nodes[x][u].pb(i);
    nodes[x][v].clear();
}

mt19937 rng(time(0));
int nadji()
{
    int tid=rng()%2;
    int rt=rng()%r[tid].size();
    int rrr=*r[tid].find_by_order(rt);
    return nodes[tid][rrr][rng()%nodes[tid][rrr].size()];
}

int main()
{
    FAST;

    int n,m1,m2;
    cin>>n>>m1>>m2;
    fff(i,1,n)
    {
        par[i][0]=i;
        par[i][1]=i;
        nodes[0][i]={i};
        nodes[1][i]={i};
        r[0].insert(i);
        r[1].insert(i);
    }

    ff(i,0,m1)
    {
        int u,v;
        cin>>u>>v;
        unite(u,v,0);
    }
    ff(i,0,m2)
    {
        int u,v;
        cin>>u>>v;
        unite(u,v,1);
    }

    int ans=n-1-max(m1,m2);
    cout<<ans<<"\n";
    while(ans>0)
    {
        int u=nadji();
        int v=nadji();
        if(root(u,0)!=root(v,0) && root(u,1)!=root(v,1))
        {
            cout<<u<<" "<<v<<"\n";
            ans--;
            unite(u,v,0);
            unite(u,v,1);
        }
    }
}

//Note to self: Check for overflow