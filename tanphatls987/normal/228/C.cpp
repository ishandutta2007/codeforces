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

int n,m,a[N][N],f[12][N][N],g[N][N];
char s[N];
int get(int xa,int ya,int xb,int yb){
    return g[xb][yb]+g[xa-1][ya-1]-g[xa-1][yb]-g[xb][ya-1];
}
void prepare(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n){
        scanf("\n%s",s);
        FOR(j,1,m) a[i][j]=(s[j-1]=='*');
    }
}
bool check(int st,int k,int x,int y){
    if (st) return (get(x,y,x+(1<<k)-1,y+(1<<k)-1)==(1<<(k<<1)));
    return f[k][x][y];
}
int solve(){
    FOR(i,1,n)
        FOR(j,1,m) g[i][j]=g[i][j-1]+g[i-1][j]-g[i-1][j-1]+a[i][j];
    int ans=0;
    REP(st,0,1<<4){
        FOR(i,1,n-1)
            FOR(j,1,m-1) f[1][i][j]=(a[i][j]+2*a[i][j+1]+4*a[i+1][j]+8*a[i+1][j+1]==st);
        FOR(k,1,9)
            FOR(i,1,n-(1<<(k+1))+1)
                FOR(j,1,m-(1<<(k+1))+1){
                    f[k+1][i][j]=check(st&1,k,i,j)&check(st&2,k,i,j+(1<<k))&check(st&4,k,i+(1<<k),j)&check(st&8,k,i+(1<<k),j+(1<<k));
                    ans+=f[k+1][i][j];
                }
    }
    return ans;
}
int main(){
    prepare();
    cout<<solve();
}