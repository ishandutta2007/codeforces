#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("d.inp","r",stdin)
#define OUTPUT freopen("d.out","w",stdout)
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
const int N=1e5+10;

int n,x,y,w[N],r[N<<1],aff[N],pop[N],q;
vector <int> a[N];
double ans;
void prepare(){
    scanf("%d",&n);
    REP(i,0,n-1){
        scanf("%d%d%d",&x,&y,w+i);
        r[i]=x;r[n-1+i]=y;
        a[y].push_back(i);a[x].push_back(n-1+i);
    }
}
void DFS(int par,int x){
    pop[x]=1;
    for(auto &i:a[x]){
        int y=r[i];
        if (y==par) continue;
        aff[i%(n-1)]=y;
        DFS(x,y);
        pop[x]+=pop[y];
    }
}
void solve(){
    DFS(0,1);
    //FOR(i,1,n) printf("%d ",pop[i]);ENDL;
    //REP(i,0,n-1) printf("%d ",aff[i]);ENDL;
    ans=.0;
    REP(i,0,n-1){
        int x=aff[i];
        ans+=(((pop[x]+.0)*(n-pop[x])*(n-2))/((n+.0)*(n-1)*(n-2)))*6*w[i];
        //if (pop[x]>1) ans+=(((pop[x]+.0)*(pop[x]-1)*(n-pop[x]))/((n+.0)*(n-1)*(n-2)))*3*w[i];
    }
}
int main(){
    prepare();
    solve();
    scanf("%d",&q);
    //printf("%.8f\n",ans);
    while (q--){
        scanf("%d%d",&x,&y);
        x--;
        int nx=aff[x];
        ans-=(((pop[nx]+.0)*(n-2)*(n-pop[nx]))/((n+.0)*(n-1)*(n-2)))*6*(w[x]-y);
        w[x]=y;
        printf("%.8f\n",ans);
    }
}