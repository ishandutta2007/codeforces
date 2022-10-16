#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define maxn 20
#define mod 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

ll a[maxn+5][maxn+5];
map<ll,ll> M1[maxn+5][maxn+5],M2[maxn+5][maxn+5];
int n,m;
void dfs1(int x,int y,ll now,int step)
{
    if(step==0)
    {
        M1[x][y][now]++;
        return;
    }
    if(x<n) dfs1(x+1,y,now^a[x+1][y],step-1);
    if(y<m) dfs1(x,y+1,now^a[x][y+1],step-1);
}
void dfs2(int x,int y,ll now,int step)
{
    if(step==0)
    {
        M2[x][y][now]++;
        return;
    }
    if(x>1) dfs2(x-1,y,now^a[x-1][y],step-1);
    if(y>1) dfs2(x,y-1,now^a[x][y-1],step-1);
}

int main()
{
    ll k;
    scanf("%d%d%I64d",&n,&m,&k);
    rep(i,1,n) rep(j,1,m) scanf("%I64d",&a[i][j]);
    int s1=(n+m-2)>>1,s2=(n+m-2)-s1;
    dfs1(1,1,a[1][1],s1);
    dfs2(n,m,a[n][m],s2);
    ll ans=0;
    rep(i,1,n) rep(j,1,m) if(!M1[i][j].empty())
    {
        for(auto it: M1[i][j])
        {
            ll x=it.first^a[i][j]^k,cnt=it.second;
            ans+=cnt*M2[i][j][x];
        }
    }
    printf("%I64d\n",ans);
    return 0;
}