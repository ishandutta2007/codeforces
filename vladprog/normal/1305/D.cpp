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

const int N=1010;

vector<int> g[N];

pii farest(int v,int p)
{
    pii res(-1,v);
    for(int to:g[v])
        if(to!=p)
            res=max(res,farest(to,v));
    res.first++;
    return res;
}

int q;

int query(int x,int y)
{
    if(!q)
        return -1;
    q--;
    cout<<"? "<<x<<" "<<y<<endl;
    int res;
    cin>>res;
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    q=n/2;
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int a=farest(1,0).second;
    int b=farest(a,0).second;
    int v=query(a,b);
    set<int> bad{-1,a,b};
    while(true)
    {
        bad.insert(v);
        vector<int> to;
        for(int x:g[v])
            if(!bad.count(x))
                to.push_back(x);
        random_shuffle(to.begin(),to.end());
        if(to.size()%2)
            to.push_back(v);
        int res=-1;
        for(int i=1;i<to.size();i+=2)
        {
            int cur=query(to[i-1],to[i]);
            if(!bad.count(cur))
            {
                res=cur;
                break;
            }
        }
        if(res==-1)
            break;
        v=res;
    }
    cout<<"! "<<v;
}