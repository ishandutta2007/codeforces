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
const int N=2e5+10;

int h[N][2],ans[N],sign[N],v[N][2],deg[N],g[N],n,m;
priority_queue <ii> q;
vector <int> e[N];
void prepare(){
    scanf("%d%d",&n,&m);
    int m1,x;
    FOR(i,1,n){
        scanf("%d",&m1);
        while (m1--){
            scanf("%d",&x);
            h[abs(x)][x>0]++;
            int cur=abs(x);
            if (!v[cur][0]) sign[cur]=cur/x;
            v[cur][v[cur][0]>0]=i;
        }
    }
}
void destroy(int x,int val){
    ans[x]=val;
    FOR(i,0,1) {
        deg[v[x][i]]--;
        q.push(ii(-deg[v[x][i]],v[x][i]));
    }
}
void setval(int x){
    if (g[x]==1) return;
//    printf("%d\n",x);
    g[x]=1;
    for(auto i:e[x]) if (!ans[i]){
        int val=(x==v[i][0]?-sign[i]:sign[i]);
        destroy(i,val);
        setval(v[i][0]+v[i][1]-x);
    }
}
void solve(){
//    FOR(i,1,m) printf("%d ",sign[i]);ENDL;
    FOR(i,1,m) if (h[i][0]&&h[i][1])
        FOR(j,0,1) e[v[i][j]].push_back(i);
    FOR(i,1,n) deg[i]=e[i].size();
    FOR(i,1,m) if (!(h[i][0]*h[i][1])){
        ans[i]=sign[i];
        FOR(j,0,h[i][0]+h[i][1]) setval(v[i][j]);
    }
    FOR(i,1,n) if (!g[i]) q.push(ii(-deg[i],i));
    while (!q.empty()){
        int x=q.top().Y;
        q.pop();
        if (g[x]) continue;
        if (!deg[x]){
            printf("NO");
            return;
        }
        for(auto i:e[x]) if (!ans[i]){
            int val=(x==v[i][0]?sign[i]:-sign[i]);
            destroy(i,val);
            break;
        }
        setval(x);
    }
    printf("YES\n");
    FOR(i,1,m) printf("%d",ans[i]==1?1:0);
}
int main(){
    prepare();
    solve();
}