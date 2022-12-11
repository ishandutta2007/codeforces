#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("bubble.inp","r",stdin)
#define OUTPUT freopen("bubble.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e5+10,M=20;

int v[N][2],n,m,p[N][M],q[N],t[N],tr[N],lv[N],b[1000005],g[2][N];
vector <int> e[N];
ll power(ll x,int y){
    ll ans=1;
    while (y){
        if (y&1) ans=ans*x%MOD;
        x=x*x%MOD;
        y>>=1;
    }
    return ans;
}
void BFS(){
    int top=1,bot=1;
    q[1]=1;
    lv[1]=1;
    while (top<=bot){
        int x=q[top++];
        for(auto i:e[x]){
            int y=v[i][0]+v[i][1]-x;
            if (lv[y]) continue;
            lv[y]=lv[x]+1;
            p[y][0]=x;
            tr[y]=i;
            q[++bot]=y;
        }
    }
}
int LCA(int x,int y){
    if (lv[x]<lv[y]) swap(x,y);
    for(int i=0,j=lv[x]-lv[y];j;i++,j>>=1)
        if (j&1) x=p[x][i];
    if (x==y) return x;
    FORD(i,int(log2(lv[x])),0) if (p[x][i]!=p[y][i])
        x=p[x][i],y=p[y][i];
    return p[x][0];
}
void prepare(){
    scanf("%d",&n);
    int x,y;
    FOR(i,1,n-1){
        scanf("%d%d%d",&x,&y,t+i);
        v[i][0]=x;v[i][1]=y;
        e[x].push_back(i);
        e[y].push_back(i);
    }
    BFS();
    REP(lv,1,M)
        FOR(i,1,n) p[i][lv]=p[p[i][lv-1]][lv-1];
    scanf("%d",&m);
    FOR(i,1,m) scanf("%d",b+i);
}
ll solve(){
    FOR(i,1,m){
        int z=LCA(b[i-1],b[i]);
        g[1][b[i-1]]++;g[1][z]--;
        g[0][b[i]]++;g[0][z]--;
    }
    FORD(i,n,1){
        int x=q[i];
        FOR(j,0,1) g[j][p[x][0]]+=g[j][x];
    }
    ll ans=0;
    FOR(i,2,n) if (t[tr[i]]){
        int idx=tr[i];
        ans=(ans+power(2,g[i==v[idx][1]][i])-1)%MOD;
    }
    return (ans+MOD)%MOD;
}
int main(){
    prepare();
    cout<<solve();
}