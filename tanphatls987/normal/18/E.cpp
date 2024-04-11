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
const int N=5e2+10;

int n,m,c[N][2][26],f[N][30][2],g[N][30][2];
ii t[N][30][2];
char s[N];
bool minimize(int &x,int y){
    if (x>y) x=y;else return false;
    return true;
}
void optimize(int row,int c0,int c1){
    int v=inf;
    ii tr;
    if (row==n){
        v=c[n][0][c0]+c[n][1][c1];
        tr=ii(0,0);
    }else{
        FOR(lc0,0,25) if (lc0!=c0){
            int lu=(c1==g[row+1][lc0][0]);
            if (minimize(v,f[row+1][lc0][lu]+c[row][0][c0]+c[row][1][c1])) tr=ii(lc0,lu);
        }
    }
    if (v<f[row][c0][1]){
        int go=1;
        if (v<f[row][c0][0]){
            f[row][c0][1]=f[row][c0][0];
            t[row][c0][1]=t[row][c0][0];
            g[row][c0][1]=g[row][c0][0];
            go--;
        }
        f[row][c0][go]=v;
        t[row][c0][go]=tr;
        g[row][c0][go]=c1;
    }
}
int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n){
        scanf("\n%s",s);
        REP(j,0,m) c[i][j%2][s[j]-'a']--;
        FOR(k,0,1)
            REP(j,0,26) c[i][k][j]+=(m+1-k)/2;
    }
    g[n+1][26][0]=26;
    FORD(row,n,1){
        FOR(i,0,25){
            f[row][i][0]=f[row][i][1]=inf;
            FOR(j,0,25) if (j!=i) optimize(row,i,j);
        }
    }
    ii ct=ii(0,0);
    int ans=inf;
    FOR(i,0,25) if (ans>f[1][i][0]) ans=f[1][i][0],ct.X=i;
    printf("%d\n",ans);
    FOR(i,1,n){
        REP(j,0,m) printf("%c",'a'+((j%2)?g[i][ct.X][ct.Y]:ct.X));ENDL;
        ct=t[i][ct.X][ct.Y];
    }
}