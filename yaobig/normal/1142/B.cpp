#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 200000
#define mod 1000000007
#define inf 0x3f3f3f3f
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int p[maxn*2+5],pos[maxn+5];
int a[maxn+5],nxt[maxn+5];
int to[20][maxn+5];
int mn[20][maxn+5],lg[maxn+5];

int ask_min(int l,int r)
{
    int k=lg[r-l+1];
    return min(mn[k][l],mn[k][r-(1<<k)+1]);
}

int main()
{
    int n,m,q; scanf("%d%d%d",&n,&m,&q);
    rep(i,1,n) scanf("%d",&p[i]),p[i+n]=p[i],pos[p[i]]=i;
    rep(i,1,m) scanf("%d",&a[i]);
    rep(i,1,n) nxt[i]=m+1;
    to[0][m+1]=m+1;
    per(i,1,m)
    {
        int x=a[i];
        int s=pos[x];
        to[0][i]=nxt[p[s+1]];
        nxt[x]=i;
    }
    rep(i,1,17) rep(j,1,m+1) to[i][j]=to[i-1][to[i-1][j]];
    rep(i,1,m)
    {
        int now=i;
        rep(j,0,17) if((n-1)>>j&1) now=to[j][now];
        mn[0][i]=now;
    }
    rep(i,2,maxn) lg[i]=lg[i>>1]+1;
    rep(i,1,lg[m]) rep(j,1,m-(1<<i)+1) mn[i][j]=min(mn[i-1][j],mn[i-1][j+(1<<(i-1))]);
    while(q--)
    {
        int l,r; scanf("%d%d",&l,&r);
        int res=ask_min(l,r);
        putchar(res<=r?'1':'0');
    }
    puts("");
    return 0;
}