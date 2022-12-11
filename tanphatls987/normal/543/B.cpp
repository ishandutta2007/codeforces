#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("b.inp","r",stdin)
#define OUTPUT freopen("b.out","w",stdout)
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
const int N=3e3+10;

int h[N][N],n,m,x,y,xa,ya,xb,yb,ta,tb;
queue <int> q;
vector <int> a[N];
void BFS(int x){
    q.push(x);
    h[x][x]=1;
    while (!q.empty()){
        int cx=q.front();q.pop();
        for(auto y:a[cx]) if (!h[x][y]){
            h[x][y]=h[x][cx]+1;
            q.push(y);
        }
    }
    //FOR(i,1,n) cout<<h[x][i]<<" \n";
    FOR(i,1,n) h[x][i]--;
}
int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,m){
        scanf("%d%d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    scanf("%d%d%d%d%d%d",&xa,&ya,&ta,&xb,&yb,&tb);
    FOR(i,1,n) BFS(i);
//    FOR(i,1,n)
//        FOR(j,1,n) cout<<h[i][j]<<" \n"[j==n];
    if (h[xa][ya]>ta||h[xb][yb]>tb){
        printf("-1");
        return 0;
    }
    int ans=h[xa][ya]+h[xb][yb];
    FOR(i,1,n)
        FOR(j,1,n) {
            int t1=h[i][xa]+h[i][j]+h[j][ya],t2=min(h[i][xb]+h[j][yb],h[i][yb]+h[j][xb])+h[i][j];
//            printf("%d %d %d %d %d\n",i,j,t1,t2,t1+t2-h[i][j]);
            if (t1<=ta&&t2<=tb) ans=min(ans,t1+t2-h[i][j]);
        }
    cout<<m-ans;
}