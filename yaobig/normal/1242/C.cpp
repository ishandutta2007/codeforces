#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 5000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;
typedef double db;

int a[20][maxn+5];
vp e[20][maxn+5]; int vis[20][maxn+5];

int n[maxn+5];
ll sum[20];
vp cycle[maxn*15+5]; int N;
vi bit[(1<<15)+5];

pii sta[maxn*15+5]; int top;
int dp[(1<<15)+5];

void dfs(int i,int j)
{
    vis[i][j]=1;
    sta[++top]=mp(i,j);
    if(e[i][j].size())
    {
        assert(e[i][j].size()==1);
        int x=e[i][j][0].FI;
        int y=e[i][j][0].SE;
        if(vis[x][y]==0) dfs(x,y);
        else if(vis[x][y]==1)
        {
            int t=top;
            vp tmp;
            do
            {
                tmp.pb(sta[t]);
            } while(sta[t--]!=mp(x,y));
            int f=1;
            int b[20]={};
            for(auto it: tmp) if(++b[it.FI]>1) f=0;
            if(f) cycle[++N]=tmp;
        }
    }
    top--;
    vis[i][j]=2;
}


int main()
{
    int k; scanf("%d",&k);
    ll S=0;
    rep(i,1,k)
    {
        scanf("%d",&n[i]);
        rep(j,1,n[i])
        {
            scanf("%d",&a[i][j]);
            sum[i]+=a[i][j];
            S+=a[i][j];
        }
        sort(a[i]+1,a[i]+1+n[i]);
    }
    if(S%k!=0) {puts("No"); return 0;}
    S/=k;
    rep(i,1,k)
    {
        ll diff=S-sum[i];
        rep(j,1,n[i])
        {
            ll f=a[i][j]+diff;
            rep(c,1,k)
            {
                if(c==i && diff!=0) continue;
                int id=lower_bound(a[c]+1,a[c]+n[c]+1,f)-a[c];
                if(a[c][id]==f)
                {
                    e[i][j].pb(mp(c,id));
                }
            }
        }
    }
    rep(i,1,k) rep(j,1,n[i]) if(vis[i][j]==0) dfs(i,j);
    rep(i,1,N)
    {
        int b=0;
        for(auto it: cycle[i]) b|=1<<it.FI-1;
        bit[b].pb(i);
    }
    memset(dp,-1,sizeof dp);
    dp[0]=0;
    rep(s,0,(1<<k)-1)
    {
        for(int t=s;t;t=(t-1)&s) if(bit[t].size() && dp[s^t]!=-1) {dp[s]=t; break;}
    }
    if(dp[(1<<k)-1]!=-1)
    {
        vi ans; int s=(1<<k)-1;
        while(s)
        {
            ans.pb(bit[dp[s]][0]);
            s=s^dp[s];
        }
        int id1[20]={},id2[20]={};
        for(auto id: ans)
        {
            int L=cycle[id].size();
            rep(i,0,L-1)
            {
                id1[cycle[id][i].FI]=cycle[id][i].SE;
                id2[cycle[id][i].FI]=cycle[id][(i+1)%L].FI;
            }
        }
        puts("Yes");
        rep(i,1,k) printf("%d %d\n",a[i][id1[i]],id2[i]);
    }
    else puts("No");
    return 0;
}