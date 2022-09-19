#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
const int maxn=5e3+5;
int dp[maxn][maxn];int pr[maxn][maxn];
int a[maxn];int fact[maxn];int invf[maxn];
int po(int a,int b) {if(b==0) return 1;if(b==1) return a;if(b%2==0) {int u=po(a,b/2);return (u*u)%p;} else {int u=po(a,b-1);return (a*u)%p;}}
int inv(int x) {return po(x,p-2);}
void init()
{
    fact[0]=1;invf[0]=1;for(int i=1;i<maxn;++i) {fact[i]=(fact[i-1]*i)%p;invf[i]=inv(fact[i]);}
}
map<int,int> cnt;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    init();
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;cnt.clear();for(int i=0;i<n;++i) {cin>>a[i];cnt[a[i]]++;}
        if(n==2) {cout<<(a[0]==a[1] ? 0 : 1)<<endl;continue;}
        sort(a,a+n);int ans=1;for(auto [key,val]:cnt) {ans*=invf[val];ans%=p;}
        for(int i=0;i<=n;++i) for(int j=0;j<=n;++j) {dp[i][j]=0;pr[i][j]=0;continue;}
        for(int i=0;i<n;++i)
        {
            int o=lower_bound(a,a+n,a[i])-a;
            dp[i][1]=(o*(o-1))%p;
            if(i!=0) pr[i][1]=(pr[i-1][1]+dp[i][1])%p;
            else pr[i][1]=dp[i][1];
        }
        for(int j=2;j<n;++j)
        {
            for(int i=0;i<n;++i)
            {
                int x=lower_bound(a,a+n,a[i])-a-(2*j-1);
                if(x<=0) {dp[i][j]=0;continue;}
                dp[i][j]=(pr[lower_bound(a,a+n,a[i])-a-1][j-1]*x)%p;
                pr[i][j]=(pr[i-1][j]+dp[i][j])%p;
            }
        }
        if(a[n-2]==a[n-1]) {cout<<0<<endl;continue;}
        cout<<((ans*dp[n-2][(n/2-1)])%p+p)%p<<endl;
    }
    return 0;
}