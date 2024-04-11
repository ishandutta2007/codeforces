#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 1000000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int p[maxn+5];
vi e[maxn+5];
bool sel[maxn+5];
bool vis[maxn+5],mark[maxn+5];

int main()
{
    int n; scanf("%d",&n);
    if(n&1)
    {
        puts("Second");
        fflush(stdout);
        rep(i,1,n*2) scanf("%d",&p[i]);
        rep(i,1,n*2) e[p[i]].pb(i);
        rep(i,1,n) if(vis[i]==0)
        {
            int now=i;
            while(vis[now]==0)
            {
                vis[now]=1;
                int v=-1;
                if(mark[p[now]]==0) v=now;
                else v=now+n;
                sel[v]=1;
                mark[p[v]]=1;
                int g=p[v];
                int u=v^e[g][0]^e[g][1];
                now=u<=n?u:u-n;
            }
        }
        int s=0;
        rep(i,1,n*2) if(sel[i]) s=(s+i)%(n*2);
        vi ans;
        if(s==0) {rep(i,1,n*2) if(sel[i]) ans.pb(i);}
        else if(s==n) {rep(i,1,n*2) if(sel[i]==0) ans.pb(i);}
        else assert(0);
        rep(i,1,n) printf("%d%c",ans[i-1]," \n"[i==n]);
        fflush(stdout);
    }
    else
    {
        puts("First");
        rep(i,1,n*2) printf("%d%c",i<=n?i:i-n," \n"[i==n*2]);
        fflush(stdout);
    }
    return 0;
}