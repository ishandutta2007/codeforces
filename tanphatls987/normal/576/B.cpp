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

int n,p[N],h[N];
vector <int> g[N];
vector <ii> ans;
void build(int x,int y){
    int m1=g[x].size();
    if (x==y) {
        REP(i,0,m1-1) ans.push_back(ii(g[x][i],g[x][i+1]));
        return;
    }
    REP(i,0,g[y].size()) ans.push_back(ii(g[x][i%m1],g[y][i]));
}
void solve(){
    int m=0;
    FOR(i,1,n) if (!h[i]){
        m++;
        int cur=i;
        while (!h[cur]){
            h[cur]=1;
            g[m].push_back(cur);
            cur=p[cur];
        }
    }
    int root=1;
    FOR(i,1,m) if (g[i].size()<g[root].size()) root=i;
    if (g[root].size()>2){
        printf("NO");
        return;
    }
    FOR(i,1,m) if (g[i].size()%g[root].size()){
        printf("NO");
        return;
    }
    FOR(i,1,m) build(root,i);
    if (ans.size()!=n-1){
//        exit(-1);
        printf("NO\n");
        return;
    }
    printf("YES\n");
    for(auto i:ans) printf("%d %d\n",i.X,i.Y);
}
int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",p+i);
    solve();
}