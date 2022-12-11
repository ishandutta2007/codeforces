#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("D.inp","r",stdin)
#define OUTPUT freopen("D.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=2e5+10;

int n,span,non,deg[N],f[2][N],s[N];
vector <int> v[N];
void prepare(){
    scanf("%d%d%d",&n,&span,&non);
    REP(i,1,n){
        int x,y;
        scanf("%d%d",&x,&y);
        deg[x]++,deg[y]++;
        v[x].push_back(y);
        v[y].push_back(x);
    }
}
bool comp(int x,int y){
    return f[1][x]-f[0][x]<f[1][y]-f[0][y];
}
void DFS(int par,int x){
    int top=0;
    f[0][x]=f[1][x]=1;
    for(auto y:v[x]) if (y!=par){
        DFS(x,y);
        f[0][x]+=f[0][y];
    }
    for(auto y:v[x]) if (y!=par) s[++top]=y;
    if (!top) return;
    sort(s+1,s+top+1,comp);
//    cout<<par<<" "<<x<<" "<<top<<'\n';
//    FOR(i,1,top) cout<<s[i]<<" ";ENDL;
    f[1][x]=f[0][x]+min(-f[0][s[1]]-1+f[1][s[1]],0);
    f[0][x]=f[1][x];
//    cout<<x<<" "<<f[0][x]<<" "<<f[1][x]<<" "<<s[1]<<'\n';
    if (top>=2) f[0][x]=min(f[0][x],f[1][x]+f[1][s[2]]-f[0][s[2]]-1);
}
ll solve(){
    if (span<=non){
        DFS(0,1);
//        FOR(i,1,n) cout<<"->"<<f[0][i]<<" "<<f[1][i]<<'\n';
        int sw=min(f[0][1],f[1][1])-1;
        return 1LL*sw*non+1LL*(n-1-sw)*span;
    }
    if (*max_element(deg+1,deg+n+1)==n-1) return 1LL*non*(n-2)+span;
    return 1LL*non*(n-1);
}
int main(){
    prepare();
    cout<<solve();
}