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
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int a[maxn+5];

int l[500+5],r[500+5],id[maxn+5];
int rt[500+5][100+5],fa[maxn+5];

int getfa(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=getfa(fa[x]);
}

void pd(int bid)
{
    rep(i,l[bid],r[bid]) a[i]=a[getfa(i)];
}

void chg(int bid,int L,int R,int x,int y)
{
    pd(bid);
    //printf("? %d, %d %d:\n",bid,x,y);
    //rep(i,l[bid],r[bid]) printf("$ %d: %d\n",i,a[i]);
    rep(i,l[bid],r[bid]) if(a[i]==x && L<=i && i<=R) a[i]=y;
    //rep(i,l[bid],r[bid]) printf("$ %d: %d\n",i,a[i]);
    rep(j,1,100) rt[bid][j]=-1;
    rep(i,l[bid],r[bid]) 
    {
        int c=a[i];
        if(rt[bid][c]==-1) rt[bid][c]=i,fa[i]=i;
        else fa[i]=rt[bid][c];
    }
}

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    
    int L=sqrt(n);
    rep(i,1,n) id[i]=(i+L-1)/L;
    int N=id[n];
    per(i,1,n) l[id[i]]=i;
    rep(i,1,n) r[id[i]]=i;
    rep(i,1,N) rep(j,1,100) rt[i][j]=-1;
    rep(i,1,n)
    {
        int bid=id[i],c=a[i];
        if(rt[bid][c]==-1) rt[bid][c]=i,fa[i]=i;
        else fa[i]=rt[bid][c];
    }

    int q; scanf("%d",&q);
    while(q--)
    {
        int L,R,x,y; scanf("%d%d%d%d",&L,&R,&x,&y);
        rep(i,1,N) 
        {
            if(i==id[L]) chg(i,L,R,x,y);
            else if(i==id[R]) chg(i,L,R,x,y);
            else if(id[L]<i && i<id[R]) 
            {
                if(x==y || rt[i][x]==-1) continue;
                if(rt[i][y]==-1)
                {
                    a[rt[i][x]]=y;
                    rt[i][y]=rt[i][x];
                    rt[i][x]=-1;
                }
                else
                {
                    fa[rt[i][x]]=rt[i][y];
                    rt[i][x]=-1;   
                }
            }
        }
    }
//rep(i,1,n) printf("%d (%d): %d\n",i,id[i],getfa(i));
//puts("??");
    rep(i,1,N) pd(i);
    rep(i,1,n) printf("%d%c",a[i]," \n"[i==n]);
    return 0;
}