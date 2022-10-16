#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int a[maxn+5][maxn+5];
int s[maxn+5];
int ans;
int n,m,k;

void check()
{
    int tmp=0;
    rep(i,1,n)
    {
        int dif=0;
        rep(j,1,m) dif+=a[i][j]!=s[j];
        tmp+=min(dif,m-dif);
    }

    ans=min(ans,tmp);
}

void dfs(int dep)
{
    if(dep==0)
    {
        check();
        return;
    }
    s[dep]=0;
    dfs(dep-1);
    s[dep]=1;
    dfs(dep-1);
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    if(n>=m) rep(i,1,n) rep(j,1,m) scanf("%d",&a[i][j]);
    else
    {
        rep(i,1,n) rep(j,1,m) scanf("%d",&a[j][i]);
        swap(n,m);
    }
    ans=inf;
    if(m<=k) dfs(m);
    else
    {
        rep(i,1,n)
        {
            rep(j,1,m) s[j]=a[i][j];
            check();
        }
    }
    printf("%d\n",ans<=k?ans:-1);
    return 0;
}