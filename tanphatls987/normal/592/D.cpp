#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("cf.inp","r",stdin)
#define OUTPUT freopen("cf.out","w",stdout)
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

int n,m,sub[N],p[N],q[N];
vector <int> v[N];
ll f[N];
int d[2][N];
void prepare(){
    scanf("%d%d",&n,&m);
    int x,y;
    FOR(i,1,n-1){
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    while (m--){
        scanf("%d",&x);
        sub[x]=1;
    }
}
void BFS(){
    int top=1,bot=1;
    q[1]=1;
    while (top<=bot){
        int x=q[top++];
        for(auto y:v[x]) if (y!=p[x]){
            p[y]=x;
            q[++bot]=y;
        }
    }
}
int finddist(int type,int st){
    int top=1,bot=1;
    q[1]=st;
    memset(d[type],0,sizeof(d[type]));
    d[type][st]=1;
    while (top<=bot){
        int x=q[top++];
        for(auto y:v[x]) if (!d[type][y]){
            d[type][y]=d[type][x]+1;
            q[++bot]=y;
        }
    }
    int ans=st;
//    cout<<st<<'\n';
//    FOR(i,1,n) cout<<d[type][i]<<" \n"[i==n];
    FOR(i,1,n) if (sub[i]&&d[type][i]>d[type][ans]) ans=i;
    return ans;
}
void solve(){
//    FOR(i,1,n) cout<<q[i]<<" \n"[i==n];
    int sel1=finddist(0,1),sel2=finddist(1,sel1);
    finddist(0,sel2);
    BFS();
//    cout<<sel1<<" "<<sel2<<'\n';
    ///
    FORD(i,n,1){
        int x=q[i];
        for(auto y:v[x]) if (y!=p[x]){
            sub[x]+=sub[y];
            if (sub[y]) f[x]+=f[y]+2;
        }
    }
//    FOR(i,1,n) cout<<f[i]<<" \n"[i==n];
    FOR(i,1,n){
        int x=q[i];
        for(auto y:v[x]) if (y!=p[x]){
            int tsub=sub[x]-sub[y],tf=f[x]-(sub[y]?f[y]+2:0);
//            cout<<x<<" "<<y<<" "<<tsub<<" "<<tf<<'\n';
            if (tsub) f[y]+=tf+2;
            sub[y]=sub[x];
        }
    }
//    FOR(i,1,n) cout<<f[i]<<" \n"[i==n];
    FOR(i,1,n) f[i]-=max(d[0][i],d[1][i])-1;
    int ans=min_element(f+1,f+n+1)-f;
    cout<<ans<<"\n"<<f[ans];
}
int main(){
    prepare();
    solve();
}