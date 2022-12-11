#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("301.inp","r",stdin)
#define OUTPUT freopen("301.out","w",stdout)
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
const int N=1e2+2;

double f[N][N][N];
int g[N][N][N],sx,sy,sz;

int way(int x,int y,int z){
    return x*y+y*z+z*x;
}
double DP(int x,int y,int z){
    if (x>sx||y>sy||z>sz) return .0;
    if (g[x][y][z]) return f[x][y][z];
    g[x][y][z]=1;
    if (z) f[x][y][z]+=DP(x+1,y,z)*(x+1)*z/way(x+1,y,z);
    if (x) f[x][y][z]+=DP(x,y+1,z)*(y+1)*x/way(x,y+1,z);
    if (y) f[x][y][z]+=DP(x,y,z+1)*y*(z+1)/way(x,y,z+1);
    //printf("%d %d %d %.10f\n",x,y,z,f[x][y][z]);
    return f[x][y][z];
}
int main(){
    cin>>sx>>sy>>sz;
    double ansx=0,ansy=0,ansz=0;
    g[sx][sy][sz]=1;
    f[sx][sy][sz]=1.0;
    FOR(i,1,sx) ansx+=DP(i,0,0);
    //FOR(i,1,sx) printf("%.10f\n",DP(i,0,0));
    FOR(i,1,sy) ansy+=DP(0,i,0);
    FOR(i,1,sz) ansz+=DP(0,0,i);
    printf("%.10f %.10f %.10f",ansx,ansy,ansz);
}