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

const int N=1e5+100;

int a[2*N],b[2*N],c[2*N],d[2*N];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    int p=0,m=1e9+100;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]<m)
            m=a[i],p=i;
    }
    for(int i=n;i<2*n;i++)
        a[i]=a[i-n];
    n*=2;
    for(int i=0;i<n;i++)
        b[i]=a[(i+p+1)%n];
//    for(int i=0;i<n;i++)
//        cout<<b[i]<<" ";
//    cout<<"\n";
    vector<pair<int,int>> v;
    for(int i=n-1;i>=0;i--)
    {
        int j=lower_bound(v.begin(),v.end(),mp((b[i]+1)/2,-1ll))-v.begin();
        if(j)
            c[i]=v[j-1].second;
        else
            c[i]=n;
        while(!v.empty()&&v.back().first>=b[i])
            v.pop_back();
        v.push_back(mp(b[i],i));
    }
//    for(int i=0;i<n;i++)
//        cout<<c[i]<<" ";
//    cout<<"\n";
    for(int i=n-2;i>=0;i--)
        c[i]=min(c[i],c[i+1]);
//    for(int i=0;i<n;i++)
//        cout<<c[i]<<" ";
//    cout<<"\n";
    for(int i=0;i<n;i++)
        d[i]=c[i]-i;
//    for(int i=0;i<n;i++)
//        cout<<d[i]<<" ";
//    cout<<"\n";
    n/=2;
    if(d[0]==2*n)
        for(int i=0;i<n;i++)
            cout<<-1<<" ";
    else
        for(int i=0;i<n;i++)
            cout<<d[(i-p-1+2*n)%n]<<" ";
}