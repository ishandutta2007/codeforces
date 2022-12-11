#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("D.inp","r",stdin)
#define OUTPUT freopen("D.out","w",stdout)
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
const int N=17;

int n,m,x,y,f[N][1<<N];
int main(){
    scanf("%d%d",&n,&m);
    REP(i,0,1<<n) scanf("%d",f[0]+i);
    FOR(j,1,n)
        REP(i,0,1<<(n-j)) if (j&1) f[j][i]=f[j-1][i<<1]|f[j-1][i*2+1];
            else f[j][i]=f[j-1][i<<1]^f[j-1][i*2+1];
    while (m--){
        int i;
        scanf("%d%d",&i,&y);
        f[0][--i]=y;
        FOR(j,1,n){
            i>>=1;
            if (j&1) f[j][i]=f[j-1][i<<1]|f[j-1][i*2+1];
            else f[j][i]=f[j-1][i<<1]^f[j-1][i*2+1];
        }
        printf("%d\n",f[n][0]);
    }
}