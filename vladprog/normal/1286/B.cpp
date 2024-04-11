#pragma GCC optimize("O3")
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

const int N=2010;

vector<int> g[N];
int c[N],a[N],k[N];

int calc(int v)
{
    int ans=1;
    for(int to:g[v])
        ans+=calc(to);
    return k[v]=ans;
}

void build(int v,set<int> s)
{
    if(s.size()<c[v]+1)
        cout<<"NO",exit(0);
    auto it=s.begin();
    while(c[v]--)
        it++;
    a[v]=*it;
    s.erase(it);
    it=s.begin();
    for(int to:g[v])
    {
        set<int> t;
        while(k[to]--)
            t.insert(*(it++));
        build(to,t);
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    int root;
    for(int i=1;i<=n;i++)
    {
        int p;
        cin>>p>>c[i];
        if(p==0)
            root=i;
        else
            g[p].push_back(i);
    }
    calc(root);
    set<int> s;
    for(int i=1;i<=n;i++)
        s.insert(i);
    build(root,s);
    cout<<"YES\n";
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
}