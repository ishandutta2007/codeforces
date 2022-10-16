#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 1000000
#define mod 1000000007
#define inf (1ll<<60)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int n;
int anc[maxn+5][19],dep[maxn+5];
int D,v1,v2;

int swim(int x,int h)
{
    int i=0;
    while(h)
    {
        if(h&1) x=anc[x][i];
        i++;
        h>>=1;
    }
    return x;
}
int lca(int x,int y)
{
    if(dep[x]<dep[y]) swap(x,y);
    x=swim(x,dep[x]-dep[y]);
    if(x==y) return x;
    per(i,0,18) if(anc[x][i]!=anc[y][i]) x=anc[x][i],y=anc[y][i];
    return anc[x][0];
}

int caldis(int x,int y)
{
    return dep[x]+dep[y]-2*dep[lca(x,y)];
}

void addv(int x,int fa)
{
    dep[x]=dep[fa]+1;
    anc[x][0]=fa;
    rep(i,1,18) anc[x][i]=anc[anc[x][i-1]][i-1];
    int d1=caldis(x,v1);
    int d2=caldis(x,v2);
    if(d1>D) D=d1,v2=x;
    if(d2>D) D=d2,v1=x;
}

int main()
{
    int q; scanf("%d",&q);
    n=1;
    v1=v2=1;
    rep(i,1,3) addv(++n,1);
    rep(i,1,q)
    {
        int x; scanf("%d",&x);
        addv(++n,x);
        addv(++n,x);
        printf("%d\n",D);
    }
    return 0;
}