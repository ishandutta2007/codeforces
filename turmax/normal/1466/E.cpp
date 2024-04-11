#pragma GCC target("popcnt")
#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
const int maxn=5e5+5;
vector <int> u[64];
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
        int d[64];
        int x1=0,x2=0;
        for(int i=0;i<64;++i) d[i]=0;
        for(int i=0;i<64;++i)
        {
            u[i].clear();
            u[i].resize((n+60)/60);
            for(int j=0;j<u[i].size();++j) u[i][j]=0;
        }
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<64;++j)
            {
                if(a[i] & (1LL<<j))
                {
                    d[j]++;
                    u[j][i/60]+=(1LL<<(i%60));
                    //cout<<i<<' '<<j<<endl;
                }
            }
        }
        int ans=0;
        for(int i=0;i<60;++i)
        {
            for(int j=0;j<60;++j)
            {
                x1=0;x2=0;
                int h=(((1LL<<i)%p)*((1LL<<j)%p))%p;
                for(int k=0;k<u[i].size();++k)
                {
                    x1+=__builtin_popcountll(u[i][k] & u[j][k]);
                }
                x2=d[i]-x1;
                //cout<<x1<<' '<<x2<<endl;
                int ans1=0;
                ans1=x1*d[i]*n+x2*d[i]*d[j];
                ans1%=p;
                ans+=(ans1*h)%p;
            }
        }
        cout<<(ans%p+p)%p<<endl;
    }
    return 0;
}