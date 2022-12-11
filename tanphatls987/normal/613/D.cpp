#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("613.inp","r",stdin)
#define OUTPUT freopen("613.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e5+10,M=20;

int tin[N],tout[N],pa[N][M],h[N],lv[N];
int n,n1,a[N<<1],s[N];
ll f[N][2];
vector <int> v[N],v2[N];
bool ispar(int x,int y){
    return tin[x]<=tin[y]&&tout[y]<=tout[x];
}
bool comp(int x,int y){
    return tin[x]<tin[y];
}
int LCA(int x,int y){
    if (lv[x]<lv[y]) swap(x,y);
    for(int v=lv[x]-lv[y],i=0;v;i++,v>>=1) if (v&1) x=pa[x][i];
    if (x==y) return x;
    FORD(i,int(log2(lv[x])),0) if (pa[x][i]!=pa[y][i])
        x=pa[x][i],y=pa[y][i];
    return pa[x][0];
}
void DFS(int x){
    static int ti=0;
    tin[x]=++ti;
    for(auto y:v[x]) if (y!=pa[x][0]){
        pa[y][0]=x;
        lv[y]=lv[x]+1;
        DFS(y);
    }
    tout[x]=ti;
}
void DFS2(int x){
    f[x][0]=inf*h[x],f[x][1]=0;
    ll maup=inf;
    for(auto y:v2[x]) {
        DFS2(y);
        if (h[x]) f[x][1]+=min(f[y][0],f[y][1]+1);
        else{
            f[x][0]+=min(f[y][1],f[y][0]);
            f[x][1]+=f[y][0];
            maup=min(maup,f[y][1]-f[y][0]);
        }
    }
    if (!h[x]) {
        f[x][0]=min(f[x][0]+1,f[x][1]);
        f[x][1]+=min(maup,0LL);
    }
}
void prepare(){
    scanf("%d",&n);
    REP(i,1,n){
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    DFS(1);
    REP(lay,1,M)
        FOR(i,1,n) pa[i][lay]=pa[pa[i][lay-1]][lay-1];
}
int solve(){
    ///check adjacent
    FOR(i,1,n1) h[a[i]]=1;
    FOR(i,1,n1) if (h[pa[a[i]][0]]) return -1;
    ///add some nodes
    sort(a+1,a+n1+1,comp);
    FORD(i,n1,2) a[++n1]=LCA(a[i],a[i-1]);
//    FOR(i,1,n1) cout<<a[i]<<" \n"[i==n1];
    sort(a+1,a+n1+1,comp);
    n1=unique(a+1,a+n1+1)-a-1;
//    FOR(i,1,n1) cout<<a[i]<<" \n"[i==n1];
    ///build tree
    FOR(i,1,n1) v2[a[i]].clear();
    int top=1;
    s[1]=a[1];
    FOR(i,2,n1){
        while (!ispar(s[top],a[i])) top--;
        v2[s[top]].push_back(a[i]);
        s[++top]=a[i];
    }
//    FOR(i,1,n) cout<<h[i]<<" \n"[i==n];
    DFS2(a[1]);
    return min(f[a[1]][0],f[a[1]][1]);
}
int main(){
    prepare();
    int test;
    scanf("%d",&test);
    while (test--){
        scanf("%d",&n1);
        FOR(i,1,n1) scanf("%d",a+i);
        printf("%d\n",solve());
        FOR(i,1,n1) h[a[i]]=0;
    }
}