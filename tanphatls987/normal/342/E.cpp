#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("E.inp","r",stdin)
#define OUTPUT freopen("E.out","w",stdout)
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

int n,m,x,y,r[N],f[N],g[N],pos[N],s[N],lv[N],type,p[N<<1][20];
vector <int> v[N];
void build(int par,int x){
    static int c=0;
    pos[x]=++c;
    lv[x]=lv[par]+1;
    p[c][0]=x;
    for(auto y:v[x]) if (y!=par) {
        build(x,y);
        p[++c][0]=x;
    }
}
void DFS1(int par,int x){
    if (r[x]) f[x]=0,g[x]=x;
    else f[x]=inf,g[x]=-1;
    for(auto y:v[x]) if (y!=par){
        DFS1(x,y);
        if (f[y]+1<f[x]) f[x]=f[y]+1,g[x]=g[y];
    }
}
void DFS2(int par,int x){
    for(auto y:v[x]) if (y!=par){
        if (f[x]+1<f[y]) f[y]=f[x]+1,g[y]=g[x];
        DFS2(x,y);
    }
}
int lower(int x,int y){
    return (lv[x]<lv[y])?x:y;
}
int LCA(int x,int y){
    x=pos[x],y=pos[y];
    if (x>y) swap(x,y);
    int bar=int(log2(y-x+1));
    return lower(p[x][bar],p[y-(1<<bar)+1][bar]);
}
int main(){
    scanf("%d%d",&n,&m);
    FOR(i,2,n){
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    build(0,1);
    REP(j,0,18)
        REP(i,1,2*n-(1<<j)) p[i][j+1]=lower(p[i][j],p[i+(1<<j)][j]);
    r[1]=1;
    int m1=int(sqrt(m));
    for(int st=0;st<m;st+=m1){
        int en=min(m,st+m1);
        DFS1(0,1);
        DFS2(0,1);
        int top=0;
        REP(i,st,en){
            scanf("%d%d",&type,&x);
            if (type==1) r[x]=1,s[++top]=x;
            else{
                int ans=f[x];
                FOR(j,1,top) {
                    int z=LCA(s[j],x);
                    ans=min(ans,lv[x]+lv[s[j]]-2*lv[z]);
                }
                printf("%d\n",ans);
            }
        }
    }
}