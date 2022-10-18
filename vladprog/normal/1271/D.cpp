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

const int N=5010;

int a[N],b[N],c[N],last[N];
vector<int> g[N];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i]>>c[i],
        last[i]=i;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        last[v]=max(last[v],u);
    }
    for(int i=1;i<=n;i++)
        g[last[i]].push_back(c[i]);
    multiset<int> s;
    for(int i=1;i<=n;i++)
    {
        while(k<a[i]&&!s.empty())
            k++,
            s.erase(s.begin());
        if(k<a[i])
            cout<<-1,exit(0);
        k+=b[i];
        for(int x:g[i])
            k--,
            s.insert(x);
        while(k<0)
            k++,
            s.erase(s.begin());
    }
    cout<<accumulate(s.begin(),s.end(),0ll);
}