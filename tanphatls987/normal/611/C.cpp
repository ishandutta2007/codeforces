#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("C.inp","r",stdin)
#define OUTPUT freopen("C.out","w",stdout)
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
const int N=5e2+10;

int n,m,a[N][N],b[2][N][N];
char s[N];
int getr(int type,int xa,int ya,int xb,int yb){
    if (xa>xb||ya>yb) return 0;
    return b[type][xb][yb]+b[type][xa-1][ya-1]-b[type][xa-1][yb]-b[type][xb][ya-1];
}
void prepare(){
    int test,xa,ya,xb,yb;
    //
    scanf("%d%d",&n,&m);
    FOR(i,1,n){
        scanf("\n%s",s);
        FOR(j,1,m) a[i][j]=s[j-1]=='.';
    }
    FOR(i,1,n)
        FOR(j,1,m) b[0][i][j]=b[0][i-1][j]+b[0][i][j-1]-b[0][i-1][j-1]+(a[i][j]+a[i][j-1]==2);
    FOR(i,1,n)
        FOR(j,1,m) b[1][i][j]=b[1][i-1][j]+b[1][i][j-1]-b[1][i-1][j-1]+(a[i][j]+a[i-1][j]==2);
    scanf("%d",&test);
    while (test--){
        scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
        printf("%d\n",getr(0,xa,ya+1,xb,yb)+getr(1,xa+1,ya,xb,yb));
    }
}
int main(){
    prepare();
}