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
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    int b[n];
    for(int i=0;i<n;++i) b[i]=((a[i]+k-1)/k)*k-a[i];
    map <int,int> u;
    int ans=(-1);
    for(int i=0;i<n;++i)
    {
        if(b[i]==0) continue;
        if(!u.count(b[i]))
        {
            u[b[i]]=b[i];
        }
        else
        {
            u[b[i]]+=k;
        }
        ans=max(ans,u[b[i]]);
    }
    cout<<ans+1<<endl;
    }
    return 0;
}