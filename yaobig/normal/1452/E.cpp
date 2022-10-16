#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 2000
#define mod 998244353
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

pii seg[maxn+5];
int its[maxn+5][maxn+5],ps[maxn+5][maxn+5];

int main()
{
    int n,m,k; scanf("%d%d%d",&n,&m,&k);
    rep(i,1,m) scanf("%d%d",&seg[i].FI,&seg[i].SE);
    sort(seg+1,seg+m+1,[](pii x,pii y){return x.FI+x.SE<y.FI+y.SE;});

    rep(x,1,n-k+1)
    {
        rep(i,1,m)
        {
            int L=max(x,seg[i].FI),R=min(x+k-1,seg[i].SE);
            its[x][i]=L<=R?R-L+1:0;
            ps[x][i]=ps[x][i-1]+its[x][i];
        }
    }

    int ans=0;
    rep(x,1,n-k+1)
    {
        int ptr=1,R=x+k-1;
        rep(y,x,n-k+1)
        {
            while(ptr<=m && y>seg[ptr].FI+seg[ptr].SE-R) ptr++;
            ans=max(ans,ps[x][ptr-1]+ps[y][m]-ps[y][ptr-1]);
        }
    }
    printf("%d\n",ans);
    return 0;
}