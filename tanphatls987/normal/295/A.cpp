#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("tmp.inp","r",stdin)
#define OUTPUT freopen("tmp.out","w",stdout)
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
const int N=1e5+10;

int n,m,k,x,y,g[N],a[N],q[N][3];
ll f[N];
int main(){
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,m)
        FOR(j,0,2) scanf("%d",q[i]+j);
    while (k--){
        scanf("%d%d",&x,&y);
        g[x]++,g[y+1]--;
    }
    FOR(i,1,m) {
        g[i]+=g[i-1];
        f[q[i][0]]+=1LL*q[i][2]*g[i];
        f[q[i][1]+1]-=1LL*q[i][2]*g[i];
    }
    FOR(i,1,n){
        f[i]+=f[i-1];
        printf("%I64d ",a[i]+f[i]);
    }
}