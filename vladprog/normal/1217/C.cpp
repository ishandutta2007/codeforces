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

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n=s.size();
        s=s+"*";
        int l=0,r=-1,cur=0;
        set<pii> ans;
        while(l<n)
        {
            r++;
            cur=(cur<<1)|(s[r]=='1');
            if(r==n||cur>n)
                l=max(r-25,l+1),
                r=l-1,
                cur=0;
            else if(cur&&r-l+1>=cur)
                ans.insert({r,cur});
        }
//        for(auto p:ans)
//            cout<<p.first<<" "<<p.second<<"\n";
        cout<<ans.size()<<"\n";
    }
}