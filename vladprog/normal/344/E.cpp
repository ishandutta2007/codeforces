#pragma GCC optimize("O3")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

#define DEBUG
#ifdef DEBUG
    #define IFD(...) __VA_ARGS__
    #define IFN(...)
    #define L cout<<__LINE__<<"\n";
    #define PRINT(...) __VA_ARGS__ cout<<__LINE__<" : "<<#__VA_ARGS__<<"\n"
    #define PRT(x) cout<<__LINE__<<" : "<<#x<<" = "<<x<<"\n"
#else // DEBUG
    #define IFD(...)
    #define IFN(...) __VA_ARGS__
    #define L
    #define PRINT(...) __VA_ARGS__
    #define PRT(x)
#endif // DEBUG

#define it iterator
#define rit reverse_iterator
#define mp make_pair
#define mems(a,b) memset(a,b,sizeof(a))
#define mem0(a) mems(a,0)
#define mem1(a) mems(a,1)
#define mem255(a) mems(a,255)
#define halt exit(0)
#define all(c) (c).begin() , (c).end()
#define sz(c) ((long long)((c).size()))
#define phb push_back
#define ppb pop_back
#define phf push_front
#define ppf pop_front
#define fort0(i,a,b) for(ll i=a,i##_TO=b;i<i##_TO;i++)
#define for0(i,n) fort0(i,0,n)
#define fort1(i,a,b) for(ll i=a,i##_TO=b;i<=i##_TO;i++)
#define for1(i,n) fort1(i,1,n)
#define ford(i,a,b) for(ll i=a,i##_TO=b;i>=i##_TO;i--)

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

int a[N],b[N];

signed main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>b[i];
    int l=0,r=1e11;
    while(l<r)
    {
        int t=(l+r)/2;
        int i=n-1,j=m-1;
        //cout<<t<<" :\n";
        while(i>=0&&j>=0)
        {
            int j1=j;
            {
                int k=t,x=a[i],y=a[i],p=a[i];
                while(j1>=0)
                    if(x<=b[j1]&&b[j1]<=y)
                        j1--;
                    else if(abs(p-b[j1])<=k)
                        k-=abs(p-b[j1]),
                        p=b[j1],
                        j1--,
                        x=min(x,p),
                        y=max(y,p);
                    else
                        break;
            }
            int j2=j;
            {
                int k=t,x=a[i],y=a[i];
                while(j2>=0)
                    if(x<=b[j2]&&b[j2]<=y)
                        j2--;
                    else if(b[j2]>=y&&b[j2]-y<=k)
                        k-=b[j2]-y,
                        y=b[j2],
                        j2--;
                    else if(b[j2]<=x&&(x-b[j2])*2<=k)
                        k-=(x-b[j2])*2,
                        x=b[j2],
                        j2--;
                    else
                        break;
            }
            //cout<<i<<" , "<<j<<" -> "<<j1<<" , "<<j2<<"\n";
            j=min(j1,j2);
            i--;
        }
        if(j<0)
            r=t;
        else
            l=t+1;
    }
    cout<<l;
}