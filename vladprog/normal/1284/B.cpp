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
    vector<int> mns,mxs;
    int good=0;
    for(int i=1;i<=n;i++)
    {
        int l;
        cin>>l;
        int mn=1e9,mx=-1e9;
        bool ok=false;
        while(l--)
        {
            int s;
            cin>>s;
            if(s>mn)
                ok=true;
            mn=min(mn,s);
            mx=max(mx,s);
        }
        if(ok)
            good++;
        else
            mns.push_back(mn),
            mxs.push_back(mx);
    }
    int ans=good*good+2*good*(n-good);
    sort(mns.begin(),mns.end());
    for(int mx:mxs)
        ans+=lower_bound(mns.begin(),mns.end(),mx)-mns.begin();
    cout<<ans;
}