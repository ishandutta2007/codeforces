#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("311b.inp","r",stdin)
#define OUTPUT freopen("311b.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e5+10,M=1e2+5;

int n,m,k,d[N],a[N],x,q[N];
ll g[N],f[M][N];
void prepare(){
    scanf("%d%d%d",&m,&n,&k);
    FOR(i,2,m) scanf("%d",d+i),d[i]+=d[i-1];
    FOR(i,1,n){
        scanf("%d%d",&x,a+i);
        a[i]-=d[x];
    }
    sort(a+1,a+n+1);
    FOR(i,1,n) g[i]=g[i-1]+a[i];
}
pll line(int x,int y){
    return pll(-y,f[x][y]+g[y]);
}
ll cal(pll lin,ll x){
    return x*lin.X+lin.Y;
}
bool isLeft(pll a,pll b,pll c){
    return ((b.Y-a.Y)*(b.X-c.X)<=(c.Y-b.Y)*(a.X-b.X));
}
int main(){
    prepare();
    //FOR(i,1,n) cout<<a[i]<<" \n"[i==n];
    FOR(i,1,n) f[1][i]=1LL*i*a[i]-g[i];
    FOR(T,2,k){
        int top=1,bot=1;
        q[1]=T-1;
        FOR(i,T,n){
            while (bot<top&&cal(line(T-1,q[bot]),a[i])>=cal(line(T-1,q[bot+1]),a[i])) bot++;
            f[T][i]=cal(line(T-1,q[bot]),a[i])+1LL*i*a[i]-g[i];
            pll cur=line(T-1,i);
            while (top>bot&&isLeft(cur,line(T-1,q[top]),line(T-1,q[top-1]))) top--;
            q[++top]=i;
        }
    }
    cout<<f[k][n];
}