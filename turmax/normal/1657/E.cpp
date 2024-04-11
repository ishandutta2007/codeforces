#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
const int maxn=255;
int c1[maxn][maxn];
int po(int a,int b) {if(b==0) return 1;if(b==1) return a;if(b%2==0) {int u=po(a,b/2);return (u*u)%p;} else {int u=po(a,b-1);return (a*u)%p;}}
int c(int n,int k) {return c1[n][k];}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=0;i<maxn;++i) for(int j=0;j<=i;++j) {if(i==0) c1[0][0]=1; else {c1[i][j]=c1[i-1][j]+c1[i-1][j-1];c1[i][j]%=p;}}
    int n,k;cin>>n>>k;--n;--k;
    int dp[n+1][k+1];for(int i=0;i<=n;++i) for(int j=0;j<=k;++j) dp[i][j]=0;
    dp[0][0]=1;
    for(int i=0;i<=n;++i)
    {
            for(int l=0;l<=k;++l)
            {
                if(l==0) {dp[i][l]=po(k+1,i*(i-1)/2);continue;}
                 for(int j=0;j<=i;++j)
                 {
                dp[i][l]+=((dp[i-j][l-1]*po(k-l+1,(i-j)*j+j*(j-1)/2))%p)*c(i,j);
                dp[i][l]%=p;
                 }
            }
        }
    cout<<(dp[n][k]%p+p)%p;
    return 0;
}