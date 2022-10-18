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

int a[N],last[N],cnt[N];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int t=0;t<=q;t++)
    {
        if(t)
        {
            int i,x;
            cin>>i>>x;
            a[i]=x;
        }
        for(int i=1;i<=n;i++)
            last[a[i]]=i;
        for(int i=1;i<=n;i++)
            cnt[a[i]]=0;
        for(int i=1;i<=n;i++)
            cnt[a[i]]++;
        int ans=0;
        for(int i=1,l=1,r=0,mx=0;i<=n;i++)
        {
            r=max(r,last[a[i]]);
            mx=max(mx,cnt[a[i]]);
            if(i==r)
            {
//                cout<<i<<" "<<l<<" "<<r<<" "<<mx<<"\n";
                ans+=r-l+1-mx;
                l=i+1;
                mx=0;
            }
        }
        cout<<ans<<"\n";
    }
}