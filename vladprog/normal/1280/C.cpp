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

const int K=1e5+100,N=2*K;

vector<pair<int,int>> g[N];
int sub[N];

pair<int,int> good(int v,int p)
{
    int ans=0,cnt=1;
    for(auto to:g[v])
    {
        int u=to.first,d=to.second;
        if(u==p)
            continue;
        auto res=good(u,v);
        int to_ans=res.first,to_cnt=res.second;
        ans+=abs(to_ans);
        if(to_cnt%2)
            ans+=d;
        cnt+=to_cnt;
    }
    sub[v]=cnt;
    return {ans,cnt};
}

int centroid(int v,int p,int k)
{
    if(sub[v]<=k)
        return 0;
    for(auto to:g[v])
        if(to.first!=p)
        {
            int res=centroid(to.first,v,k);
            if(res)
                return res;
        }
    return v;
}

int bad(int v,int p,int h)
{
    int ans=h;
    for(auto to:g[v])
        if(to.first!=p)
            ans+=bad(to.first,v,h+to.second);
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        int n=2*k;
        for(int i=1;i<=n;i++)
            g[i].clear();
        for(int _=1;_<=n-1;_++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            g[a].push_back({b,c});
            g[b].push_back({a,c});
        }
        cout<<good(1,0).first<<" ";
        int v=centroid(1,0,k);
//        cout<<v<<" ";
        cout<<bad(v,0,0)<<"\n";
    }
}