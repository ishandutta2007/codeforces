//#pragma GCC optimize("O3")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

#define mp make_pair
#define all(c) (c).begin() , (c).end()
#define sz(c) ((long long)((c).size()))
#define phb push_back
#define ppb pop_back
#define phf push_front
#define ppf pop_front

using namespace __gnu_pbds;
using namespace std;

#define int ll

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template
<
    class key,
    class val=null_type,
    class comp=less<key>
>
using ord_set=tree
<
    key,
    val,
    comp,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

const int N=1e5+100;

set<int> g[N];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        g[a].insert(b);
        g[b].insert(a);
    }
    set<int> s;
    for(int i=1;i<=n;i++)
        s.insert(i);
    int ans=-1;
    while(!s.empty())
    {
        int v=*s.begin();
        if(g[v].size()==s.size()-1)
        {
//            cout<<"("<<v<<")\n";
            ans++;
            s.erase(v);
            for(int to:g[v])
                g[to].erase(v);
            continue;
        }
        int u=-1;
        for(int x:s)
            if(x!=v&&!g[v].count(x))
            {
                u=x;
                break;
            }
        for(int to:g[v])
            g[to].erase(v);
        for(auto it=g[u].begin();it!=g[u].end();)
            if(g[v].count(*it))
                it++;
            else
                g[*it].erase(u),
                g[u].erase(it++);
        s.erase(v);
//        cout<<v<<" -> "<<u<<"\n";
    }
    cout<<ans;
}