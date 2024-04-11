#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("D.inp","r",stdin)
#define OUTPUT freopen("D.out","w",stdout)
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
const int N=3e2+10;

int f[N][N],a[4],n;
int DP(int x,int y){
    if (f[x][y]!=-1) return f[x][y];
    if (x+y==0) return 0;
    f[x][y]=0;
    FOR(i,1,min(x,y)) f[x][y]|=1^DP(x-i,y-i);
    FOR(i,1,x) f[x][y]|=1^DP(x-i,y);
    FOR(i,1,y) f[x][y]|=1^DP(x,y-i);
    return f[x][y];
}
int solve(){
    if (n&1){
        int ans=0;
        FOR(i,1,n) ans^=a[i];
        return ans?1:0;
    }
    memset(f,-1,sizeof(f));
    return DP(a[1],a[2]);
}
int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    cout<<(solve()?"BitLGM":"BitAryo");
}