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
const int N=1e2+10;

int n,m,a[N][N];
ii t[N][N];
void prepare(){
    int test,type,x,y,z;
    scanf("%d%d%d",&n,&m,&test);
    FOR(i,1,n)
        FOR(j,1,m) t[i][j]=ii(i,j);
    while (test--){
        scanf("%d%d",&type,&x);
        if (type==3){
            scanf("%d%d",&y,&z);
            ii cur=t[x][y];
            a[cur.X][cur.Y]=z;
            continue;
        }
        if (type==1){
            t[x][m+1]=t[x][1];
            FOR(i,1,m) t[x][i]=t[x][i+1];
        }
        if (type==2){
            t[n+1][x]=t[1][x];
            FOR(i,1,n) t[i][x]=t[i+1][x];
        }
    }
    FOR(i,1,n){
        FOR(j,1,m) printf("%d ",a[i][j]);
        ENDL;
    }
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
}