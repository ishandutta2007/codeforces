#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("178b2.inp","r",stdin)
#define OUTPUT freopen("178b2.out","w",stdout)
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
const int N=1e5+10;

int g[N],num[N],low[N],lv[N],p[N][18],n,m,k,x,y;
vector <int> a[N],b[N];
stack <int> s;
void DFS(int par,int x){
    static int c=0;
    num[x]=low[x]=++c;
    p[x][0]=par;
    s.push(x);
    for(auto y:a[x]) if (y!=par){
        if (!num[y]){
            DFS(x,y);
            low[x]=min(low[x],low[y]);
        }else low[x]=min(low[x],num[y]);
    }
    if (low[x]==num[x]){
        g[x]=++m;
        while (s.top()!=x){
            g[s.top()]=m;
            s.pop();
        }
        s.pop();
    }
}
void DFS2(int x){
    lv[x]=lv[p[x][0]]+1;
    for(auto y:b[x]) {
        p[y][0]=x;
        DFS2(y);
    }
}
int LCA(int x,int y){
    if (lv[x]<lv[y]) swap(x,y);
    int D=lv[x]-lv[y];
    FOR(i,0,int(log2(m))) if (D&(1<<i)) x=p[x][i];
    if (x==y) return x;
    FORD(i,int(log2(lv[x])),0) if (p[x][i]!=p[y][i])
        x=p[x][i],y=p[y][i];
    return p[x][0];
}
int main(){
    scanf("%d%d",&n,&m);
    while (m--){
        scanf("%d%d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    m=0;
    DFS(0,1);
    FOR(i,1,n) if (low[i]==num[i]) b[g[p[i][0]]].push_back(g[i]);
    p[g[1]][0]=0;
    DFS2(g[1]);
    FOR(i,1,int(log2(m)))
        FOR(j,1,m) p[j][i]=p[p[j][i-1]][i-1];
    scanf("%d",&k);
    while (k--){
        scanf("%d%d",&x,&y);
        x=g[x],y=g[y];
        int z=LCA(x,y);
        printf("%d\n",lv[x]+lv[y]-2*lv[z]);
    }
}