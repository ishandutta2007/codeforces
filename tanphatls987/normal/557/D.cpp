#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("D.inp","r",stdin)
#define OUTPUT freopen("D.out","w",stdout)
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

int n,m,x,y,h[N],g[N][2],q[N];
ll ans;
vector <int> v[N];
bool BFS(int cx){
    q[1]=cx;
    h[cx]=1;
    g[cx][0]=1;
    int top=1,bot=1;
    while (top<=bot){
        int x=q[top++];
        for(auto y:v[x]){
            FOR(i,0,1) g[y][i^1]|=g[x][i];
//            printf("%d %d %d %d\n",x,y,g[y][0],g[y][1]);
            if (!h[y]){
                h[y]=1;
                q[++bot]=y;
            }
        }
    }
    int c0=0,c1=0;
//    FOR(i,1,bot) printf("%d %d %d\n",q[i],g[i][0],g[i][1]);
    FOR(i,1,bot) {
        if (g[q[i]][0]&&g[q[i]][1]) return 1;
        if (g[q[i]][0]) c0++;
        if (g[q[i]][1]) c1++;
    }
    ans+=(1LL*c0*(c0-1)+1LL*c1*(c1-1))/2;
    return 0;
}
int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,m){
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    /// no edges
    if (!m) {
        cout<<"3 "<<1LL*n*(n-1)*(n-2)/6;
        return 0;
    }
    ///every cc have only 2 vertices
    bool ok=0;
    FOR(i,1,n) if (v[i].size()>1) ok=1;
    if (!ok){
        cout<<"2 "<<1LL*m*(n-2);
        return 0;
    }
    ///check if there is odd cycle
    ans=0;
    FOR(i,1,n) if (!h[i]){
        if (BFS(i)) {
            printf("0 1");
            return 0;
        }
    }
    cout<<"1 "<<ans;
}