#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
const int maxn=2e6+5;
int ans1[maxn];
int ans2[maxn];
int u[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ans1[1]=0;ans1[2]=0;ans1[3]=0;
    ans2[1]=0;ans2[2]=0;ans2[3]=4;
    u[1]=0;u[2]=0;u[3]=4;
    for(int i=4;i<maxn;++i)
    {
        ans1[i]=2*ans2[i-2]+ans2[i-1];
        ans1[i]%=p;
        u[i]=max(4-2*u[i-2]-u[i-1],0LL);
        ans2[i]=ans1[i]+u[i];
        ans2[i]%=p;
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<ans2[n]<<endl;
    }
    return 0;
}