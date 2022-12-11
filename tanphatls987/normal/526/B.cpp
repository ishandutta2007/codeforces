#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("b.inp","r",stdin)
#define OUTPUT freopen("b.out","w",stdout)
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
const int N=3e3+10;

int ans=0,g[N],d[N],a[N],n,m;

void DFS2(int x){
    if (2*x>=m) return;
    g[x]=g[x/2]+a[x];
    ans+=d[1]-g[x]-d[2*x]-a[2*x]+d[1]-g[x]-d[2*x+1]-a[2*x+1];
    a[2*x]=d[1]-g[x]-d[2*x];
    a[2*x+1]=d[1]-g[x]-d[2*x+1];
    DFS2(x*2);DFS2(x*2+1);
}
int main(){
    scanf("%d",&n);
    m=1<<(n+1);
    REP(i,2,m) scanf("%d",a+i);
    //REP(i,1,m) d[i]=a[i];
    FORD(i,(1<<n)-1,1) d[i]=max(d[i*2]+a[i*2],d[i*2+1]+a[i*2+1]);
    //REP(i,1,m) cout<<d[i]<<" \n"[i==m-1];
    DFS2(1);
    //REP(i,1,m) cout<<g[i]<<" \n"[i==m-1];
    cout<<ans;
}