#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 500000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

db dp[maxn+5][55];
int cnt,fa[maxn+5];

int newnode()
{
    cnt++;
    rep(i,0,50) dp[cnt][i]=1;
    return cnt;
}

int main()
{
    int Q; scanf("%d",&Q);
    newnode();
    while(Q--)
    {
        int op,v; scanf("%d%d",&op,&v);
        if(op==1)
        {
            int now=newnode(); fa[now]=v;
            db o1=1,n1=0;
            for(int i=0,now=v;now && i<=50;i++,now=fa[now])
            {
                db o2=dp[now][i];
                dp[now][i]*=(n1+1)/(o1+1);
                o1=o2,n1=dp[now][i];
            }
        }
        else
        {
            db ans=0;
            rep(i,1,50) ans+=i*(dp[v][i]-dp[v][i-1]);
            printf("%.10f\n",ans);
        }
    }
    return 0;
}