#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("c.inp","r",stdin)
#define OUTPUT freopen("c.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=3e2+10;

vector <iii> ans;
int q[N],s[N],w[2][N],h[N],n,m,V,T[N],x,y;
vector <int> a[N],b[N];
iii edge(int x,int y,int w){
    return iii(ii(x,y),w);
}
int DFS1(int root,int par,int x){
    int get=min(w[0][x],w[1][root]-w[0][root]);
    w[0][root]+=get;
    w[0][x]-=get;
    if (w[0][root]<w[1][root])
        for(auto y:b[x]) if (!h[y]&&y!=par) get+=DFS1(root,x,y);
    if (get&&par) ans.push_back(edge(x,par,get));
    return get;
}
int DFS2(int root,int par,int x){
    int get=0;
    if (w[0][x]<V){
        get=min(V-w[0][x],w[0][root]-w[1][root]);
        w[0][root]-=get;
        w[0][x]+=get;
    }
    if (w[0][root]>w[1][root])
        for(auto y:b[x]) if (!h[y]&&y!=par) get+=DFS2(root,x,y);
    if (get&&par) ans.push_back(edge(par,x,get));
    return get;
}
bool BFS(int x){
    int top=1,bot=1;
    q[1]=x;
    ll sum=0;
    T[x]=-1;
    while (top<=bot){
        int cx=q[top++];
        sum+=w[0][cx]-w[1][cx];
        int nx=cx;
        if (w[0][cx]) while (1){
            if (T[nx]==-1) break;
            if (w[0][T[nx]]==V) break;
            else{
                int v=min(w[0][nx],V-w[0][T[nx]]);
                ans.push_back(edge(nx,T[nx],v));
                w[0][nx]-=v;
                w[0][T[nx]]+=v;
            }
            nx=T[nx];
        }
        for(auto y:a[cx]) if (!T[y]){
            T[y]=cx;
            b[cx].push_back(y);
            b[y].push_back(cx);
            q[++bot]=y;
        }
    }
    if (sum!=0) return 0;
    FORD(i,bot,2) {
        int cx=q[i];
        h[cx]=1;
        if (w[0][cx]<w[1][cx]) DFS1(cx,0,cx);
        else DFS2(cx,0,cx);
    }
    return 1;
}
void solve(){
    FOR(i,1,n) if (!T[i]){
        if (!BFS(i)) {
            printf("NO");
            return;
        }
    }
    printf("%d\n",ans.size());
    for(auto i:ans) printf("%d %d %d\n",i.X.X,i.X.Y,i.Y);
}
int main(){
    scanf("%d%d%d",&n,&V,&m);
    FOR(i,1,n) scanf("%d",w[0]+i);
    FOR(i,1,n) scanf("%d",w[1]+i);
    while (m--){
        scanf("%d%d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    solve();
}