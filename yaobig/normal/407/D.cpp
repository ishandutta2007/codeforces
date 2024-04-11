#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 400
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

inline void chmax(int &x,int y) {if(x<y) x=y;}
inline void chmin(int &x,int y) {if(x>y) x=y;}

int a[maxn+5][maxn+5],l[maxn+5][maxn+5],r[maxn+5][maxn+5],L[maxn+5],pos[maxn*maxn+5];


int main()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,n) rep(j,1,m) scanf("%d",&a[i][j]);

    int ans=0;
    memset(r,63,sizeof r);
    per(up,1,n)
    {
        memset(pos,0,sizeof pos);
        rep(c,1,m)
        {
            chmax(l[up][c],pos[a[up][c]]);
            pos[a[up][c]]=c;
            rep(u,up+1,n) chmax(l[u][c],pos[a[u][c]]);
        }
        memset(pos,63,sizeof pos);
        per(c,1,m)
        {
            chmin(r[up][c],pos[a[up][c]]);
            pos[a[up][c]]=c;
            rep(u,up+1,n) chmin(r[u][c],pos[a[u][c]]);
        }
        memset(L,0,sizeof L);
        rep(d,up,n)
        {
            rep(c,1,m) 
            {
                chmax(L[c],l[d][c]);
                if(r[d][c]!=inf) chmax(L[r[d][c]],c);
            }
            int tmp=0;
            rep(c,1,m)
            {
                chmax(tmp,L[c]);
                chmax(ans,(c-tmp)*(d-up+1));
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}