#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    pair <int,int> a[n];
    for(int i=0;i<n;++i) cin>>a[i].first>>a[i].second;
    double ans=2;
    for(int i=0;i<n;++i)
    {
        double u=(1.0/2.0);
        for(int j=1;j<min(n,(int) 100);++j)
        {
            u/=2.0;
            if(n<=70)
            {
            u=1;
            for(int l=0;l<(n-j-1);++l)
            {
                u*=2;
            }
            u--;
            double z=1;
            for(int l=0;l<n;++l)
            {
                z*=2;
            }
            z-=(n+0.0)*(n-1+0.0)/2;
            z-=n;
            z--;
            u/=z;
            }
            int k=(i+j)%n;
            int g=__gcd(abs(a[i].first-a[k].first),abs(a[i].second-a[k].second));
            int s2=a[i].first*a[k].second-a[i].second*a[k].first;
            //cout<<i<<' '<<k<<endl;
            //cout<<s2<<" s2 "<<endl;
            //cout<<u<<" u "<<endl;
            ans+=u*s2;
            ans-=u*g;
        }
    }
    cout<<fixed<<setprecision(25)<<ans/2.0;
    return 0;
}