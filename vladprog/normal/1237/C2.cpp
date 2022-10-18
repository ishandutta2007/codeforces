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

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    map<pair<int,int>,vector<pair<int,int>>> m;
    for(int i=1;i<=n;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        m[{x,y}].push_back({z,i});
    }
    map<int,vector<pair<int,int>>> m2;
    for(auto p:m)
    {
        int x=p.first.first;
        int y=p.first.second;
        auto v=p.second;
        sort(v.begin(),v.end());
        for(int i=0;i+1<v.size();i+=2)
            cout<<v[i].second<<" "<<v[i+1].second<<"\n";
        if(v.size()%2)
            m2[x].push_back({y,v.back().second});
    }
    vector<pair<int,int>> m3;
    for(auto p:m2)
    {
        int x=p.first;
        auto v=p.second;
        sort(v.begin(),v.end());
        for(int i=0;i+1<v.size();i+=2)
            cout<<v[i].second<<" "<<v[i+1].second<<"\n";
        if(v.size()%2)
            m3.push_back({x,v.back().second});
    }
    sort(m3.begin(),m3.end());
    for(int i=0;i+1<m3.size();i+=2)
        cout<<m3[i].second<<" "<<m3[i+1].second<<"\n";
}