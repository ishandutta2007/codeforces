#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
int po(int a,int b) {if(b==0) return 1; if(b==1) return a; if(b%2==0) {int u=po(a,b/2);return (u*u)%p;} else {int u=po(a,b-1);return (a*u)%p;}}
int inv(int x) {return po(x,p-2);}
const int maxn=2005;
int fact[maxn];int invf[maxn];
int32_t dp[maxn][maxn][11];int32_t dp2[maxn][maxn][11];
int c(int n,int k)
{
    int ans=fact[n];ans*=invf[k];ans%=p;ans*=invf[n-k];ans%=p;return ans;
}
int f(int x,int y)
{
    if(y==0 && x==0) return 1;
    else if(y==0) return 0;
    int ans=fact[x+y-1];ans*=invf[y-1];ans%=p;return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    fact[0]=1;for(int i=1;i<maxn;++i) {fact[i]=(fact[i-1]*i)%p;} for(int i=0;i<maxn;++i) invf[i]=inv(fact[i]);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;int a[n];vector<int> v0,v1;for(int i=0;i<n;++i) {cin>>a[i];int len=to_string(a[i]).size();if(len%2==0) v0.push_back(a[i]%11); else v1.push_back(a[i]%11);}
        for(int i=0;i<=v1.size();++i) for(int j=0;j<=v1.size();++j) for(int k=0;k<11;++k) dp[i][j][k]=0;
        for(int i=0;i<=v0.size();++i) for(int j=0;j<=v0.size();++j) for(int k=0;k<11;++k) dp2[i][j][k]=0;
        dp[0][0][0]=1;dp2[0][0][0]=1;
        for(int i=0;i<v1.size();++i)
        {
            for(int j=0;j<v1.size();++j)
            {
                for(int k=0;k<11;++k)
                {
                    if(!dp[i][j][k]) continue;
                    int x=v1[i]%11;
                    dp[i+1][j+1][(k+x)%11]+=dp[i][j][k];if(dp[i+1][j+1][(k+x)%11]>=p) dp[i+1][j+1][(k+x)%11]-=p;
                    dp[i+1][j][((k-x)%11+11)%11]+=dp[i][j][k];if(dp[i+1][j][((k-x)%11+11)%11]>=p) dp[i+1][j][((k-x)%11+11)%11]-=p;
                }
            }
        }
        for(int i=0;i<v0.size();++i)
        {
            for(int j=0;j<v0.size();++j)
            {
                for(int k=0;k<11;++k)
                {
                    if(!dp2[i][j][k]) continue;
                    int x=v0[i]%11;
                    dp2[i+1][j+1][(k+x)%11]+=dp2[i][j][k];dp2[i+1][j+1][k]%=p;
                    dp2[i+1][j][((k-x)%11+11)%11]+=dp2[i][j][k];dp2[i+1][j][((k-x)%11+11)%11]%=p;
                }
            }
        }
        int res[11]={0};int o=fact[v1.size()/2]*fact[(v1.size()+1)/2];o%=p;
        for(int i=0;i<11;++i) res[i]=dp[v1.size()][(v1.size()+1)/2][i];
        int answ=0;
        for(int k=0;k<=v0.size();++k)
        {
            int l=v0.size()-k;
            int k1=(v1.size()+2)/2;int l1=(v1.size()+1)/2;
            int o2=f(k,k1)*f(l,l1);o2%=p;
            for(int j=0;j<11;++j)
            {
                int ans1=o*o2;ans1%=p;
                ans1*=res[(11-j)%11];ans1%=p;
                ans1*=dp2[v0.size()][k][j];ans1%=p;
                answ+=ans1;answ%=p;
            }
        }
        cout<<answ<<'\n';
    }
    return 0;
}