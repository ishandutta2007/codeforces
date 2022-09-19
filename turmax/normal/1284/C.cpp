#include <bits/stdc++.h>

using namespace std;
#define int long long
int p;
int po(int a,int b)
{
    if(b==0)
    {
        return 1;
    }
    if(b==1)
    {
        return a;
    }
    if(b%2==0)
    {
        int u=po(a,b/2);
        return (u*u)%p;
    }
    return (a*po(a,b-1))%p;
}
int inv(int x)
{
    return po(x,p-2);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n>>p;
    int a[n+1];
    int b[n+1];
    a[0]=1;
    b[0]=1;
    for(int i=0;i<n;++i)
    {
        a[i+1]=(a[i]*(i+1));
        a[i+1]%=p;
        b[i+1]=(b[i]*(n-i));
        b[i+1]%=p;
    }
    int ans=0;
    for(int i=0;i<n;++i)
    {
        ans+=((((a[i+1]*inv(b[i+1]))%p)*(n-i))%p)*(n-i);
        ans%=p;
    }
    ans*=a[n];
    ans%=p;
    cout<<ans;
    return 0;
}