#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("draft.inp","r",stdin)
#define OUTPUT freopen("draft.out","w",stdout)
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
const int ldig[2]={4,7};

int n,m,g[N],lucky[100],h[N],f[2][N],q[N],pot[N];
vector <int> v[N];
int BFS(int x){
    h[x]=1;
    int top=1,bot=1;
    q[1]=x;
    while (top<=bot){
        int x=q[top++];
        for(auto y:v[x]) if (!h[y]){
            h[y]=1;
            q[++bot]=y;
        }
    }
    return bot;
}
void prepare(){
    scanf("%d%d",&n,&m);
    while (m--){
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    FOR(i,1,n) if (!h[i]) g[BFS(i)]++;
    m=0;
    for(int phase=0,st=0;phase<5;phase++){
        int en=m;
        FOR(i,st,m)
            FOR(j,0,1){
                int x=lucky[i]*10+ldig[j];
                if (x<=n) lucky[++en]=x;
            }
        st=m+1;
        m=en;
    }
}
int solve(){
    int cur=0;
    FOR(i,1,lucky[m]) f[0][i]=inf;
    FOR(sel,1,lucky[m]) if (g[sel]){
        int last=cur;cur^=1;
        REP(st,0,sel){
            int top=1,bot=0;
            for(int i=st;i<=lucky[m];i+=sel){
                pot[i]=f[last][i]+(lucky[m]-i)/sel;
                while (top<=bot&&(i-q[top])/sel>g[sel]) top++;
                while (top<=bot&&pot[i]<=pot[q[bot]]) bot--;
                q[++bot]=i;
                f[cur][i]=f[last][q[top]]+(i-q[top])/sel;
            }
        }
    }
    int ans=inf;
    FOR(i,1,m) ans=min(ans,f[cur][lucky[i]]);
    return (ans<inf)?ans-1:-1;
}
int main(){
    prepare();
//    FOR(i,1,m) printf("%d ",lucky[i]);
    cout<<solve();
}