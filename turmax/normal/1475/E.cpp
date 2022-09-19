#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
int po(int a,int b)
{
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0)
    {
        int u=po(a,b/2);
        return (u*u)%p;
    }
    else
    {
        int u=po(a,b-1);
        return (a*u)%p;
    }
}
int inv(int x) {return po(x,p-2);}
int c(int n,int k)
{
    int ans=1;
    for(int i=1;i<=n;++i) {ans*=i;ans%=p;}
    for(int i=1;i<=k;++i) {ans*=inv(i);ans%=p;}
    for(int i=1;i<=(n-k);++i) {ans*=inv(i);ans%=p;}
    return ans;
}
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
        sort(a,a+n);reverse(a,a+n);
        int o=0;
        int l=1e18;
        for(int i=0;i<n;++i)
        {
            if(a[i]==a[k-1])
            {
                l=min(l,i);
                ++o;
            }
        }
        cout<<c(o,k-l)<<endl;
    }
    return 0;
}