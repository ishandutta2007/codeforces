#pragma GCC optimize("O3","Ofast","unroll-loops")
#include <bits/stdc++.h>

using namespace std;
#define int long long
int perec(pair <int,int> a1,pair <int,int> a2)
{
    int l=max(a1.first,a2.first);int r=min(a1.second,a2.second);
    if(r>=l) return (r-l+1);
    else return 0;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    int pr[n+1];pr[0]=0;
    for(int i=0;i<n;++i) {cin>>a[i];if(i%2==0) pr[i+1]=pr[i]+a[i]; else pr[i+1]=pr[i]-a[i];}
    int ans=0;
    for(int i=0;i<n;++i)
    {
        for(int j=(i+1);j<n;++j)
        {
            if(i%2==1 || j%2==0) continue;
            int sum=pr[j]-pr[i+1];
            int val1=a[i];int val2=a[j];
            int curr=0;int mi=0;
            for(int k=(i+1);k<j;++k)
            {
                if(k%2==0) curr+=a[k];
                else curr-=a[k];
                mi=min(mi,curr);
            }
            mi*=(-1);
            if(mi==0) mi=1;
            pair <int,int> o1={mi+sum,val1+sum};
            pair <int,int> o2={0,val2};
            ans+=perec(o1,o2);
        }
    }
    cout<<ans;
    return 0;
}