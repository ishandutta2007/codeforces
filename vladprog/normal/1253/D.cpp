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

const int N=2e5+100;

int p[N];

int dsu(int x)
{
    return p[x]==x?x:p[x]=dsu(p[x]);
}

bool un(int x,int y)
{
    x=dsu(x);
    y=dsu(y);
    if(x==y)
        return false;
    if(rand()%2)
        swap(x,y);
    p[x]=y;
    return true;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        p[i]=i;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        un(a,b);
    }
    vector<int> v;
    set<int> s;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int x=dsu(i);
        while(s.count(x))
            ans+=un(x,v.back()),
            s.erase(v.back()),
            v.pop_back();
        x=dsu(x);
        v.push_back(x);
        s.insert(x);
    }
    cout<<ans;
}