#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("draft.inp","r",stdin)
#define OUTPUT freopen("draft.out","w",stdout)
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
const int N=1e3+10;

int n,g[4][N][N],a[N][N];
ii b[2][N][N];
string s;
ii operator +(ii a,ii b){
    return ii(a.X+b.X,a.Y+b.Y);
}
ii operator -(ii a,ii b){
    return ii(a.X-b.X,a.Y-b.Y);
}
bool psmall(ii a,ii b){
    return a.X-b.X<log2(3)*(b.Y-a.Y);
}
void prepare(){
    cin>>n;
    FOR(i,1,n) {
        cin>>s;
        FOR(j,1,n) a[i][j]=s[j-1]-'0';
    }
    int n0=0;
    FOR(i,1,n)
        FOR(j,1,n) n0+=a[i][j];
    if (n0==0) {
        printf("0");
        exit(0);
    }
}
ii solvedia(){
    ii ans=ii(0,0);
    ///main dia
    FOR(i,1,n)
        FOR(j,1,n){
            b[0][i][j]=b[0][i-1][j-1];
            if (a[i][j]>1) b[0][i][j]=b[0][i][j]+ii(a[i][j]==2,a[i][j]==3);
        }
//    FOR(i,1,n)
//        FOR(j,1,n) cout<<i<<" "<<j<<" "<<b[0][i][j].X<<" "<<b[0][i][j].Y<<'\n';
    ///sub dia
    FOR(i,1,n)
        FOR(j,1,n){
            b[1][i][j]=b[1][i-1][j+1];
            if (a[i][j]>1) b[1][i][j]=b[1][i][j]+ii(a[i][j]==2,a[i][j]==3);
        }
    ///NW
    FOR(i,1,n)
        FOR(j,1,n) if (!a[i][j]) g[0][i][j]=0;
        else g[0][i][j]=g[0][i-1][j-1]+1;
    ///NE
    FOR(i,1,n)
        FORD(j,n,1) if (!a[i][j]) g[1][i][j]=0;
        else g[1][i][j]=g[1][i-1][j+1]+1;
    ///SW
    FORD(i,n,1)
        FOR(j,1,n) if (!a[i][j]) g[2][i][j]=0;
        else g[2][i][j]=g[2][i+1][j-1]+1;
    ///SE
    FORD(i,n,1)
        FOR(j,1,n) if (!a[i][j]) g[3][i][j]=0;
        else g[3][i][j]=g[3][i+1][j+1]+1;
    ///
    FOR(i,1,n)
        FOR(j,1,n) if (a[i][j]){
            int curd=inf;
            FOR(k,0,3) curd=min(curd,g[k][i][j]);
            ii cval=b[0][i+curd-1][j+curd-1]-b[0][i-curd][j-curd]+b[1][i+curd-1][j-curd+1]-b[1][i-curd][j+curd];
            if (a[i][j]>1) cval=cval-ii(a[i][j]==2,a[i][j]==3);
//            cout<<i<<" "<<j<<" "<<cval.X<<" "<<cval.Y<<'\n';
            ans=max(ans,cval,psmall);
        }
    return ans;
}
ii solven(){
    ii ans=ii(0,0);
    ///horizontal
    FOR(i,1,n)
        FOR(j,1,n){
            b[0][i][j]=b[0][i][j-1];
            if (a[i][j]>1) b[0][i][j]=b[0][i][j]+ii(a[i][j]==2,a[i][j]==3);
        }
    ///vertical
    FOR(i,1,n)
        FOR(j,1,n){
            b[1][i][j]=b[1][i-1][j];
            if (a[i][j]>1) b[1][i][j]=b[1][i][j]+ii(a[i][j]==2,a[i][j]==3);
        }
    ///left to right
    FOR(i,1,n)
        FOR(j,1,n) if (!a[i][j]) g[0][i][j]=0;
        else g[0][i][j]=g[0][i][j-1]+1;
    ///right to left
    FOR(i,1,n)
        FORD(j,n,1) if (!a[i][j]) g[1][i][j]=0;
        else g[1][i][j]=g[1][i][j+1]+1;
    ///up to down
    FOR(i,1,n)
        FOR(j,1,n) if (!a[i][j]) g[2][i][j]=0;
        else g[2][i][j]=g[2][i-1][j]+1;
    ///down to up
    FORD(i,n,1)
        FOR(j,1,n) if (!a[i][j]) g[3][i][j]=0;
        else g[3][i][j]=g[3][i+1][j]+1;
    ///
    FOR(i,1,n)
        FOR(j,1,n) if (a[i][j]){
            int curd=inf;
            FOR(k,0,3) curd=min(curd,g[k][i][j]);
            ii cval=b[0][i][j+curd-1]-b[0][i][j-curd]+b[1][i+curd-1][j]-b[1][i-curd][j];
            if (a[i][j]>1) cval=cval-ii(a[i][j]==2,a[i][j]==3);
            ans=max(ans,cval,psmall);
        }
    return ans;
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    ii tar=max(solven(),solvedia(),psmall);
//    cout<<tar.X<<" "<<tar.Y<<'\n';
    ll ans=1;
    FOR(i,1,tar.X) ans=ans*2%MOD;
    FOR(i,1,tar.Y) ans=ans*3%MOD;
    cout<<ans;
}