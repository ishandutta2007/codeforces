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

    int n,k;
    cin>>n>>k;
    int l=0,r=n+1;
    while(l<r)
    {
        int m2=(l+r+1)/2;
        int m=m2*2;
        int cnt=0;
        for(int mn=m,mx=m+1;mn<=n;mn=mn*2,mx=mx*2+1)
            cnt+=min(mx,n)-mn+1;
        if(cnt>=k)
            l=m2;
        else
            r=m2-1;
    }
    int ans0=l*2;
    l=0,r=n+1;
    while(l<r)
    {
        int m2=(l+r+1)/2;
        int m=m2*2+1;
        int cnt=0;
        for(int mn=m,mx=m;mn<=n;mn=mn*2,mx=mx*2+1)
            cnt+=min(mx,n)-mn+1;
        if(cnt>=k)
            l=m2;
        else
            r=m2-1;
    }
    int ans1=l*2+1;
    cout<<max(ans0,ans1);
}