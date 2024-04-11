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

const int inf=1e8;
const int MOD=1e9+7;
const int N=2e2+5,M=1e3+5;

int n,m,tmp,x,y,W[M],h[N],t[N],v[M][2],ans[N][N],f[M][2];
vector <int> e[N];
queue <int> q;
int cw(int x,int dir){
    return W[x]-f[x][dir];
}
bool BFS(){
    q.push(2*n+1);
    memset(h,0,sizeof(h));
    h[2*n+1]=inf;
    t[2*n+1]=-1;
    while (!q.empty()){
        int x=q.front();q.pop();
        for(auto i:e[x]){
            int cdir=(x!=v[i][0]),nx=v[i][1-cdir];
            if (!h[nx]&&cw(i,cdir)>0){
                h[nx]=min(h[x],cw(i,cdir));
                t[nx]=i;
                q.push(nx);
            }
        }
    }
    return h[2*n+2];
}
void inc_flow(){
    int x=2*n+2;
    while (x!=2*n+1){
        int idx=t[x],cdir=(x==v[idx][0]);
        f[idx][cdir]+=h[2*n+2];
        f[idx][1-cdir]-=h[2*n+2];
        x=v[idx][cdir];
    }
}
void setlink(int x,int y,int w){
    static int top=0;
    v[++top][0]=x;v[top][1]=y;
    W[top]=w;
    e[x].push_back(top);
    e[y].push_back(top);
    f[top][1]=w;
}
int main(){
    //OUTPUT;
    scanf("%d%d",&n,&m);
    FOR(i,1,n) {
        scanf("%d",&tmp);
        setlink(2*n+1,i,tmp);
    }
    FOR(i,1,n){
        scanf("%d",&tmp);
        setlink(n+i,2*n+2,tmp);
    }
    FOR(i,1,n) setlink(i,n+i,inf);
    FOR(i,1,m){
        scanf("%d%d",&x,&y);
        setlink(x,n+y,inf);
        setlink(y,n+x,inf);
    }
    while (BFS()) inc_flow();
    FOR(i,1,2*n) if (f[i][1]){
        printf("NO");
        return 0;
    }
    FOR(i,2*n+1,3*n+2*m) ans[v[i][0]][v[i][1]-n]=f[i][0];
    printf("YES\n");
    FOR(i,1,n){
        FOR(j,1,n) printf("%d ",ans[i][j]);ENDL;
    }
}