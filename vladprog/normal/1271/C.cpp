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

    int n,sx,sy;
    cin>>n>>sx>>sy;
    int cntxp=0,cntxm=0,cntyp=0,cntym=0;;
    while(n--)
    {
        int x,y;
        cin>>x>>y;
        if(x>sx)
            cntxp++;
        if(x<sx)
            cntxm++;
        if(y>sy)
            cntyp++;
        if(y<sy)
            cntym++;
    }
    int ans=max({cntxp,cntxm,cntyp,cntym});
    cout<<ans<<"\n";
    if(cntxp==ans)
        cout<<sx+1<<" "<<sy;
    else if(cntxm==ans)
        cout<<sx-1<<" "<<sy;
    else if(cntyp==ans)
        cout<<sx<<" "<<sy+1;
    else if(cntym==ans)
        cout<<sx<<" "<<sy-1;
}