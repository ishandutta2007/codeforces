#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second
#define INPUT freopen(".inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=1e5;

int q,k;
ll f[N+10];
void solve(){
    FOR(i,0,N) if (i<k) f[i]=1;else f[i]=(f[i-k]+f[i-1])%MOD;
    FOR(i,1,N) f[i]=(f[i]+f[i-1])%MOD;
}
int main(){
    scanf("%d%d",&q,&k);
    solve();
    while (q--){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%lld\n",(f[y]-f[x-1]+MOD)%MOD);
    }
}