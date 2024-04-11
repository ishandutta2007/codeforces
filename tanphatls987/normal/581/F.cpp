#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("draft.inp","r",stdin)
#define OUTPUT freopen("draft.out","w",stdout)
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
const int N=5e3+10;

int n,f[N][N][2],g[N][2],p[N],q[N],leaf[N];
vector <int> v[N];
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n-1) {
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
}
void BFS(){
    q[1]=1;
    while (v[q[1]].size()==1) q[1]++;
//    printf("tick\n");
    int top=1,bot=1;
    while (top<=bot){
        int x=q[top++];
        for(auto y:v[x]) if (y!=p[x]){
            p[y]=x;
            q[++bot]=y;
        }
    }
//    FOR(i,1,n) cout<<q[i]<<" \n"[i==n];
}
int solve(){
    if (n==2) return 1;
    BFS();
    FORD(ph,n,1){
        int x=q[ph];
        if (v[x].size()==1) {
            leaf[x]=1;
            f[x][1][1]=f[x][0][0]=0;
            f[x][1][0]=f[x][0][1]=inf;
            continue;
        }
        FOR(j,1,n) f[x][j][0]=f[x][j][1]=inf;
        for(auto y:v[x]) if (y!=p[x]){
            FOR(j,0,n)
                FOR(type,0,1) {
                    g[j][type]=f[x][j][type];
                    f[x][j][type]=inf;
                }
            leaf[x]+=leaf[y];
            FORD(i,leaf[x],0)
                FOR(j,0,min(i,leaf[y]))
                    FOR(type,0,1) f[x][i][type]=min(f[x][i][type],min(g[i-j][type]+f[y][j][type],g[i-j][type]+f[y][j][type^1]+1));
        }
//        printf("%d %d\n",x,leaf[x]);
//        FOR(i,0,leaf[x]) printf("->%d %d %d\n",i,f[x][i][0],f[x][i][1]);
        if (ph==1) return min(f[x][leaf[x]>>1][0],f[x][leaf[x]>>1][1]);
    }
}
int main(){
    prepare();
    cout<<solve();
}