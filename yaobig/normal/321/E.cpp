#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 4000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int read()
{
    int x=0,sgn=1;
    char ch=getchar();
    while(ch<'0' || ch>'9')
    {
        if(ch=='-') sgn=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*sgn;
}

int a[maxn+5][maxn+5];
int dp[805][maxn+5];

void solve(int dep,int l,int r,int L,int R)
{
    if(l>r) return;
    int mid=(l+r)>>1,dec=L;
    dp[dep][mid]=inf;
    rep(i,L,min(mid-1,R))
    {
        int tmp=dp[dep-1][i]+a[mid][mid]-a[mid][i]-a[i][mid]+a[i][i];
        if(tmp<dp[dep][mid]) dp[dep][mid]=tmp,dec=i;
    }
    solve(dep,l,mid-1,L,dec);
    solve(dep,mid+1,r,dec,R);
}

int main()
{
    int n=read(),k=read();
    rep(i,1,n) rep(j,1,n) a[i][j]=read();
    rep(i,1,n) rep(j,1,n) a[i][j]+=a[i][j-1]+a[i-1][j]-a[i-1][j-1];
    rep(i,1,n) dp[0][i]=inf;
    rep(i,1,k) solve(i,0,n,0,n);
    printf("%d\n",dp[k][n]/2);
    return 0;
}