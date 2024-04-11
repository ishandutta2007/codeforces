#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("a.inp","r",stdin)
#define OUTPUT freopen("a.out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=3e4+10,M=256;

int n,d,f[N][2*M+50],h[N]={0};
int solve(){
    FOR(j,d,30000)
        FOR(i,0,M<<1) f[j][i]=-inf;
    f[d][M]=h[d];
    int ans=-inf;
    FOR(i,d,30000)
        FOR(j,0,M<<1) if (f[i][j]>=0) {
            ans=max(ans,f[i][j]);
            FOR(k,-1,1) {
                int step=j+k-M+d,next=i+step;
                //printf("%d %d %d %d\n",i,step,next,f[i][j]+h[next]);
                if (step>0&&j+k>=0&&j+k<=2*M&&next<=30000) f[next][j+k]=max(f[next][j+k],f[i][j]+h[next]);
            }
        }
    return ans;
}
int main(){
    //INPUT;
    scanf("%d%d",&n,&d);
    FOR(i,1,n) {
        int x;
        scanf("%d",&x);
        h[x]++;
    }
    cout<<solve();
}