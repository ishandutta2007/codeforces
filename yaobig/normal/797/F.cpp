#include "bits/stdc++.h"
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
typedef double db;

ll DP[2][maxn+5],ps[maxn+5];
int x[maxn+5],p[maxn+5],c[maxn+5];
pii pc[maxn+5];

pair<int,ll> q[maxn+5];
int front,rear;
void push(pair<int,ll> t)
{
    while(front<=rear && q[rear].SE>=t.SE) rear--;
    q[++rear]=t;
}
void pop(int idx)
{
    while(front<=rear && q[front].FI<idx) front++;
}


int main()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,n) scanf("%d",&x[i]);
    rep(i,1,m) scanf("%d%d",&pc[i].FI,&pc[i].SE);
    sort(x+1,x+n+1);
    sort(pc+1,pc+m+1);
    rep(i,1,m) p[i]=pc[i].FI,c[i]=pc[i].SE;
    rep(i,1,n) ps[i]=ps[i-1]+x[i];
    memset(DP,63,sizeof DP);

    #define dp(i,j) DP[(i)&1][j]
    dp(0,0)=0;
    int thr=1;
    rep(i,1,m)
    {
        while(thr<=n && x[thr]<p[i]) thr++;
        front=0,rear=-1;
        dp(i,0)=0;
        push({0,dp(i-1,0)});
        rep(j,1,n)
        {
            if(j<thr) push({j,dp(i-1,j)+ps[j]-1ll*j*p[i]});
            pop(j-c[i]);
            if(j<thr+c[i]-1)
            {
                ll t=q[front].SE;
                if(j<thr) t+=1ll*j*p[i]-ps[j];
                else t+=1ll*(thr-1)*p[i]-ps[thr-1]+ps[j]-ps[thr-1]-1ll*(j-thr+1)*p[i];
                dp(i,j)=t;
            }
            else dp(i,j)=dp(i-1,j-c[i])+ps[j]-ps[j-c[i]]-1ll*c[i]*p[i];
        }
        //printf("? %d: %d\n",i,thr);
        //rep(j,0,n) printf("%lld%c",dp(i,j)," \n"[j==n]);
    }
    if(dp(m,n)>1ll<<60) puts("-1");
    else printf("%lld\n",dp(m,n));
    return 0;
}