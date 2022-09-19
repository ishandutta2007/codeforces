#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
int po(int a,int b) {if(b==0) return 1;if(b==1) return a;if(b%2==0) {int u=po(a,b/2);return (u*u)%p;} else {int u=po(a,b-1);return (a*u)%p;}}
int inv(int x) {return po(x,p-2);}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    sort(a,a+n);reverse(a,a+n);
    int pr[n+1];pr[0]=0;
    for(int i=0;i<n;++i) pr[i+1]=pr[i]+a[i];
    for(int k=1;k<=n;++k)
    {
        int ans=0;
        for(int l=k;l<=n;l+=k)
        {
            ans+=(pr[l]-pr[((l-1)/k)*k])*((l-1)/k);
            ans%=p;
            if(l>(n-k) && l<n) l=(n-k);
        }
        ans*=inv(n);ans%=p;ans+=p;ans%=p;
        cout<<ans<<' ';
    }
    return 0;
}