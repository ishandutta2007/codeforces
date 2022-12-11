#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second
#define INPUT freopen(".inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")

typedef long long ll;
typedef pair<int,int> ii;

const int inf=((1LL<<31)-1);
const int MOD=1e9+7;
const int N=2e3+10,M=12;


int n,a[N][N],h[N][N]={0},p[N]={0},f[N][M+2];
vector <int> b[N];
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n)
        FOR(j,1,n) scanf("%d",&a[i][j]);
}
int LCA(int x,int y){
    if (p[x]<p[y]) swap(x,y);
    FORD(i,M,0) if (p[f[x][i]]>=p[y]) x=f[x][i];
    if (x==y) return x;
    FORD(i,M,0) if (f[x][i]!=f[y][i]&&f[x][i]>0&&f[y][i]>0)
        x=f[x][i],y=f[y][i];
    return f[x][0];
}
void solve(){
    FOR(i,1,n)
        FOR(j,1,n) if (i==j){
            if (a[i][j]!=0) {printf("NO");return;}
        }else if (a[i][j]!=a[j][i]||a[i][j]==0) {printf("NO");return;}
    p[1]=1;
    FOR(i,2,n) p[i]=2,h[i][1]=1;
    FOR(i,2,n)
        FOR(j,2,n) if (i!=j) if (a[1][i]+a[i][j]==a[1][j]) h[j][i]=1,p[j]++;
    FOR(i,1,n) b[p[i]].push_back(i);
    FOR(i,2,n){
        REP(j,0,b[i].size()){
            int x=b[i][j],par=0;
            REP(k,0,b[i-1].size()) if (h[x][b[i-1][k]]) par++,f[x][0]=b[i-1][k];
            if (par!=1) {printf("NO");return;}
        }
    }
    //FOR(i,1,n) printf("%d ",f[i][0]);
    FOR(j,1,M)
        FOR(i,1,n) f[i][j]=f[f[i][j-1]][j-1];
    FOR(i,2,n)
        FOR(j,i+1,n){
            int x=LCA(i,j);
            //printf("%d %d %d",x,i,j);
            if (a[x][i]+a[x][j]!=a[i][j]) {printf("NO");return;}
        }
    printf("YES");
}
int main()
{
    prepare();
    solve();
}