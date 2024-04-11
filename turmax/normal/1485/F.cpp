#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
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
        int h[n];
        for(int i=0;i<n;++i) cin>>a[i];
        map <int,int> u;
        int pr[n+1];pr[0]=0;u[0]=0;
        for(int i=0;i<n;++i)
        {
            pr[i+1]=pr[i]+a[i];
            if(u.count(pr[i+1]))
            {
                h[i]=u[pr[i+1]];
            }
            else
            {
                h[i]=(-1);
            }
            u[pr[i+1]]=(i+1);
        }
        int t[n+1];int t0[n+1];
        t[0]=1;t0[0]=1;
        for(int i=1;i<=n;++i)
        {
            t[i]=2*t[i-1]-t0[i-1];
            t[i]%=p;t[i]+=p;t[i]%=p;
            int z=h[i-1];
            if(z!=(-1))
            {
                t0[i]=t[z];
            }
            else
            {
                t0[i]=0;
            }
        }
        cout<<t[n]<<endl;
    }
    return 0;
}