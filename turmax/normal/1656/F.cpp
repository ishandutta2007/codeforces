#pragma GCC optimize("O3","Ofast","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;++i) cin>>a[i];
        sort(a,a+n);
        int pr[n+1]={0};for(int i=0;i<n;++i) pr[i+1]=pr[i]+a[i];
        int ans=(-1e18);
        int sum1=0,sum2=0;
        for(int i=1;i<n;++i) {sum1+=a[0];sum1+=a[i];}
        for(int i=0;i<n-1;++i) {sum2+=a[n-1];sum2+=a[i];}
        if(sum1<=0 && sum2>=0)
        {
        for(int i=0;i<n;++i) {int t=a[i];int sum1=(pr[i]-t*i);int sum2=(pr[n]-pr[i]-t*(n-i));int mi=a[0]-a[i];int ma=a[n-1]-a[i];int ans1=(sum1*ma+sum2*mi-ma*mi-a[i]*a[i]*(n-1));ans=max(ans,ans1);}
        cout<<ans<<'\n';
        }
        else
        {
            cout<<"INF"<<'\n';
        }
    }
    return 0;
}