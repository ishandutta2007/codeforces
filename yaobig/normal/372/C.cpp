#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 150000
#define mod 1000000007
#define inf (1ll<<60)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

ll dp[2][maxn+5];
int a[305],b[305],t[305];

int q[maxn+5];

int main()
{
    int n,m,d; scanf("%d%d%d",&n,&m,&d);
    rep(i,1,m) scanf("%d%d%d",&a[i],&b[i],&t[i]);
    rep(i,1,m)
    {
        int front=0,rear=-1,r=0;
        rep(j,1,n)
        {
            ll L=j-1ll*(t[i]-t[i-1])*d;
            ll R=j+1ll*(t[i]-t[i-1])*d;
            while(r<R && r<n)
            {
                r++;
                while(front<=rear && dp[i-1&1][q[rear]]<=dp[i-1&1][r]) rear--;
                q[++rear]=r;
            }
            while(front<=rear && q[front]<L) front++;
            dp[i&1][j]=dp[i-1&1][q[front]]+b[i]-abs(a[i]-j);
        }
    }
    ll ans=-inf;
    rep(i,1,n) ans=max(ans,dp[m&1][i]);
    printf("%I64d\n",ans);
    return 0;
}