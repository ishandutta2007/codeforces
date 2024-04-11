#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
int po(int a,int b) {if(b==0) return 1; if(b==1) return a; if(b%2==0) {int u=po(a,b/2);return (u*u)%p;} else {int u=po(a,b-1);return (a*u)%p;}}
int inv(int x) {return po(x,p-2);}
const int maxn=2e5+5;
int dp[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;int a[n];int s=0;int s2=0;for(int i=0;i<n;++i) {cin>>a[i];s+=(1-a[i]);s2+=a[i];}
        int s1=0;for(int i=0;i<s;++i) s1+=a[i];
        for(int i=0;i<=s;++i) dp[i]=0;
        int h=n*(n-1)/2;h%=p;int h1=inv(h);h1%=p;
        for(int i=1;i<=s;++i)
        {
            int o=i*i;o%=p;o*=h1;o%=p;
            dp[i]=((dp[i-1]*o+1)%p)*inv(o);
            dp[i]%=p;
        }
        cout<<(dp[s1]%p+p)%p<<'\n';
    }
    return 0;
}