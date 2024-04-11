//#pragma GCC optimize("O3")
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

const int N=3e5+100;

int a[N],l[N],r[N];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        for(int i=0;i<=n+1;i++)
            l[i]=n+1,r[i]=0;
        for(int i=1;i<=n;i++)
            cin>>a[i],
            l[a[i]]=min(l[a[i]],i),
            r[a[i]]=max(r[a[i]],i);
        int ans=0;
        for(int i=0,j=0,cur_r=0,res=0;i<=n;res-=bool(r[i]),i++)
        {
            if(res==0)
                cur_r=0;
            while(j+1<=n&&l[j+1]>cur_r)
                j++,res+=bool(r[j]),cur_r=max(cur_r,r[j]);
            ans=max(ans,res);
        }
        for(int i=1;i<=n;i++)
            ans-=bool(r[i]);
        cout<<-ans<<"\n";
    }
}