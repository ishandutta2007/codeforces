#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 1000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

db dp[maxn+5];
db a[maxn+5],b[maxn+5],c[maxn+5],d[maxn+5];

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    int sx,sy; scanf("%d%d",&sx,&sy);
    per(r,sx,n-1)
    {
        rep(i,1,m)
        {
            int mov=2+(i>1)+(i<m);
            a[i]=-1,b[i]=mov-1,c[i]=-1,d[i]=dp[i]+mov;
        }
        rep(i,2,m)
        {
            db f=a[i]/b[i-1];
            a[i]=0;
            b[i]-=c[i-1]*f;
            d[i]-=d[i-1]*f;
        }
        dp[m]=d[m]/b[m];
        per(i,1,m-1) dp[i]=(d[i]-dp[i+1]*c[i])/b[i];
    }
    printf("%.10f\n",dp[sy]);
    return 0;
}