#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("f.inp","r",stdin)
#define OUTPUT freopen("f.out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 0

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

const int inf=2e9;
const int MOD=1e9+7;
const int M=4e3,N=M+10;

iii a[N],b[20010];
ll f[2][N][N]={0},cur[N],ans[20010];
int n,T,m;
void prepare(){
    scanf("%d%d",&n,&T);
    FOR(i,1,n) scanf("%d%d%d",&a[i].Y.X,&a[i].Y.Y,&a[i].X);
    scanf("%d",&m);
    FOR(i,1,m){
        scanf("%d%d",&b[i].X,&b[i].Y.X);
        b[i].Y.Y=i;
    }
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
}
void solve(){
    if (debug){
        FOR(i,1,n) printf("%d %d %d\n",a[i].X,a[i].Y.X,a[i].Y.Y);
        FOR(i,1,m) printf("%d %d %d\n",b[i].X,b[i].Y.X,b[i].Y.Y);
    }
    int top1=0,top2=0,L=1,R=0;
    FOR(i,1,m){
        while (L<=R&&top1&&a[L].X+T<=b[i].X) top1--,L++;
        while (R<n&&a[R+1].X<=b[i].X){
            R++;top2++;
            FORD(j,M,0){
                f[1][top2][j]=f[1][top2-1][j];
                if (j>=a[R].Y.X) f[1][top2][j]=max(f[1][top2][j],f[1][top2-1][j-a[R].Y.X]+a[R].Y.Y);
            }
            FOR(j,1,M) f[1][top2][j]=max(f[1][top2][j],f[1][top2][j-1]);
        }
        if (!top1){
            top2=0;
            FORD(x,R,L){
                top1++;
                FORD(j,M,0){
                    f[0][top1][j]=f[0][top1-1][j];
                    if (j>=a[x].Y.X) f[0][top1][j]=max(f[0][top1][j],f[0][top1-1][j-a[x].Y.X]+a[x].Y.Y);
                }
            }
            FOR(j,1,M) f[0][top1][j]=max(f[0][top1][j],f[0][top1][j-1]);
        }
        while (L<=R&&top1&&a[L].X+T<=b[i].X) top1--,L++;
        FOR(j,0,b[i].Y.X) ans[b[i].Y.Y]=max(ans[b[i].Y.Y],f[0][top1][j]+f[1][top2][b[i].Y.X-j]);
    }
    FOR(i,1,m) printf("%lld\n",ans[i]);
}
int main(){
    //OUTPUT;
    prepare();
    solve();
}