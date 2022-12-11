#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("d.inp","r",stdin)
#define OUTPUT freopen("d.out","w",stdout)
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
const int N=2e5+10;

int f[N],n,x,y,g[2][N],t[N],ans[N],re[N];
vector <int> a[N];
queue <int> q;
/*ll power(ll x,ll y){
    if (y==0) return 1;
    if (y==1) return x;
    ll tmp=power(x,y/2);
    return tmp*tmp%MOD*power(x,y%2)%MOD;
}*/
void DFS1(int par,int x){
    f[x]=1;
    for(auto y:a[x]) if (y!=par){
        DFS1(x,y);
        f[x]=(1LL*f[x]*f[y])%MOD;
    }
    if (par) f[x]++;
}
void BFS(){
    q.push(1);
    t[1]=0;
    while (!q.empty()){
        int x=q.front();q.pop();
        int m1=a[x].size();
        g[0][0]=g[1][m1+1]=1;
        //-----------------
        FOR(i,1,m1) if (a[x][i-1]==t[x]) g[0][i]=1LL*g[0][i-1]*re[x]%MOD;
        else g[0][i]=1LL*g[0][i-1]*f[a[x][i-1]]%MOD;
        FORD(i,m1,1) if (a[x][i-1]==t[x]) g[0][i]=1LL*g[0][i-1]*re[x]%MOD;
        else g[1][i]=1LL*g[1][i+1]*f[a[x][i-1]]%MOD;
        //printf("%d\n",x);
        //FOR(j,0,1)
            //FOR(i,0,m1+1) cout<<g[j][i]<<" \n"[i==m1+1];
        //-----------------------------
        FOR(i,1,m1) {
            int y=a[x][i-1];
            if (y!=t[x]){
                re[y]=(1LL*g[0][i-1]*g[1][i+1]+1)%MOD;
                //printf("%d %d %d %d\n",y,g[0][i-1],g[1][i+1],othway);
                if (a[y].size()==1) f[y]=re[y];
                else f[y]=1LL*(f[y]+MOD-1)*re[y]%MOD;
                t[y]=x;
                q.push(y);
            }
        }
    }
}
int main(){
    scanf("%d",&n);
    FOR(i,2,n) {
        scanf("%d",&x);
        a[x].push_back(i);
        a[i].push_back(x);
    }
    DFS1(0,1);
    //FOR(i,1,n) printf("%d ",f[i]);ENDL;
    BFS();

    FOR(i,1,n) printf("%d ",f[i]);
}