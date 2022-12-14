#include <bits/stdc++.h>
#define x first
#define y second
#define mid (l+r>>1)
#define lo (o<<1)
#define ro (o<<1|1)
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;
struct tri{int x,y,z;};
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int N=1e5+10;
const ll mod=1e9+7;
const double PI=acos(0)*2;
int n;
int a1,a0,b[100];
int dp[85][85][85*85];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
//    freopen("in.txt","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;cin>>a;
        if(a)b[++a1]=i;
    }
    a0=n-a1;
    b[a1+1]=n+1;
    int M=n*(n-1)/2;
    for(int i=0;i<=n+1;i++)
    {
        for(int j=0;j<=a1;j++)if(j<=i)
        {
            for(int k=0;k<=M;k++)
            {
                if(k)dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]);
                for(int l=i+1;l<=n+1;l++)if(j!=a1||l==n+1)
                {
                    dp[l][j+1][k+abs(b[j+1]-l)]=\
                    max(dp[i][j][k]+(l-i-1)*(a0-(l-j-1)),\
                    dp[l][j+1][k+abs(b[j+1]-l)]);
                }
            }
        }
    }
    for(int i=0;i<=M;i++)
        cout<<dp[n+1][a1+1][i]<<' ';
    return 0;
}