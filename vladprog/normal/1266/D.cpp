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

const int N=1e5+100;

int s[N];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int u,v,d;
        cin>>u>>v>>d;
        s[u]+=d;
        s[v]-=d;
    }
    vector<pair<int,int>> give,take;
    for(int i=1;i<=n;i++)
        if(s[i]>0)
            give.push_back({i,s[i]});
        else if(s[i]<0)
            take.push_back({i,-s[i]});
    vector<array<int,3>> ans;
    for(int i=0,j=0;i<give.size()&&j<take.size();i+=!give[i].second,j+=!take[j].second)
    {
        int d=min(give[i].second,take[j].second);
        give[i].second-=d;
        take[j].second-=d;
        ans.push_back({give[i].first,take[j].first,d});
    }
    cout<<ans.size()<<"\n";
    for(auto arr:ans)
        cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<"\n";
}