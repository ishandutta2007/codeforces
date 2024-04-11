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

#define M_PI		3.14159265358979323846
#define M_PI_2		1.57079632679489661923

ld ang(int x,int y)
{
    if(x>0&&y==0)
        return 0;
    if(x==0&&y>0)
        return M_PI_2;
    if(x<0&&y==0)
        return M_PI;
    if(x==0&&y<0)
        return 3*M_PI_2;
    ld t=ld(y)/ld(x);
    ld a=atan(t);
    if(x<0)
        a+=M_PI;
    if(a<0)
        a+=2*M_PI;
//    cout<<x<<" "<<y<<" -> "<<a/(2*M_PI)<<"\n";
    return a;
}

const int N=2510;

int x[N],y[N];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>x[i]>>y[i];
    int ans=n*(n-1)*(n-2)*(n-3)*(n-4)/24;
    for(int c=1;c<=n;c++)
    {
        vector<ld> a;
        for(int p=1;p<=n;p++)
            if(c!=p)
                a.push_back(ang(x[p]-x[c],y[p]-y[c]));
        sort(a.begin(),a.end());
        for(int i=0;i<n-1;i++)
            a.push_back(a[i]+2*M_PI);
        for(int i=0;i<n-1;i++)
            a.push_back(a[i]+4*M_PI);
        for(int i=0,j=0;i<n-1;i++)
        {
            while(a[j+1]-a[i]<M_PI)
                j++;
            int k=j-i;
//            cout<<c<<" -> "<<k<<"\n";
            ans-=k*(k-1)*(k-2)/6;
        }
    }
    cout<<ans;
}