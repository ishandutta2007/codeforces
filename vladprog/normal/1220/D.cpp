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

vector<int> v[70];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    pair<int,int> ans(0,0);
    for(int _=0;_<n;_++)
    {
        int b;
        cin>>b;
        int t=b;
        int k=0;
        while(t%2==0)
            k++,t/=2;
        v[k].push_back(b);
        if(v[k].size()>ans.first)
            ans={v[k].size(),k};
    }
    cout<<n-ans.first<<"\n";
    for(int i=0;i<70;i++)
        if(i!=ans.second)
            for(int b:v[i])
                cout<<b<<" ";
}