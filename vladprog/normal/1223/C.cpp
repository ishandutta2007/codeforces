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

int p[N],s[N];

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
        for(int i=1;i<=n;i++)
            cin>>p[i],
            p[i]/=100;
        sort(p+1,p+n+1,greater<int>());
        for(int i=1;i<=n;i++)
            s[i]=s[i-1]+p[i];
        int x,a,y,b,k;
        cin>>x>>a>>y>>b>>k;
        if(x<y)
            swap(x,y),
            swap(a,b);
        int lcm=a*b/__gcd(a,b);
        int l=0,r=n+1;
        while(r-l>1)
        {
            int m=(l+r)/2;
            int cnt12=m/lcm;
            int cnt1=m/a-cnt12;
            int cnt2=m/b-cnt12;
            int res=s[cnt12]*(x+y)+
                    (s[cnt12+cnt1]-s[cnt12])*x+
                    (s[cnt12+cnt1+cnt2]-s[cnt12+cnt1])*y;
            if(res>=k)
                r=m;
            else
                l=m;
        }
        if(r==n+1)
            cout<<-1<<"\n";
        else
            cout<<r<<"\n";
    }
}