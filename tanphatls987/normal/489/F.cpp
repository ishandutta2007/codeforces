#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cmath>
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
const int N=2e3+10;

int n,m,mod,f[N][N],h[N]={0},c[3]={0};
char s[N];
bool ok;
void prepare(){
    ok=true;
    scanf("%d%d%d",&n,&m,&mod);
    FOR(i,1,m){
        int v=0;
        scanf("\n%s",s);
        FOR(j,1,n) h[j]+=s[j-1]-'0',v+=s[j-1]-'0';
        if (v!=2) ok=false;
    }
    int v=0;
    FOR(i,1,n) c[h[i]]++,v+=2-h[i];
    if (v!=2*(n-m)) ok=false;
}
int DP(int x,int y){
    //printf("%d %d\n",x,y);
    if (f[x][y]!=-1) return f[x][y];
    if (x==0&&y==0) return 1;
    f[x][y]=0;
    if (x>1) f[x][y]=(f[x][y]+(((1LL*x*(x-1))/2)%mod*DP(x-2,y+2))%mod)%mod;
    if (y>1) f[x][y]=(f[x][y]+((((1LL*y*(y-1))/2)%mod*DP(x,y-2))%mod))%mod;
    if (x&&y) f[x][y]=(f[x][y]+((1LL*x*y)%mod*DP(x-1,y))%mod)%mod;
    return f[x][y];
}
int main(){
    prepare();
    //cout<<ok;
    memset(f,-1,sizeof(f));
    if (ok) cout<<DP(c[0],c[1]);
    else cout<<0;
}