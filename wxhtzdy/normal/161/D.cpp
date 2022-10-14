#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=50050;
int n,k,sz[N];
vector<int> E[N];
bool was[N];
ll ans=0;
void DFS(int u,int p){sz[u]=1;for(int e:E[u])if(e!=p&&!was[e])DFS(e,u),sz[u]+=sz[e];}
int Find(int u,int p,int n){for(int e:E[u])if(e!=p&&!was[e]&&sz[e]*2>n)return Find(e,u,n);return u;}
int FindCentroid(int u){DFS(u,u);return Find(u,u,sz[u]);}
map<int,int> cnt;
vector<int> tmp;
void Solve(int u,int p,int depth){
    ans+=cnt[k-depth];
    tmp.pb(depth);
    for(int e:E[u])if(e!=p&&!was[e])Solve(e,u,depth+1);
}
void Decompose(int u){
    u=FindCentroid(u);
    was[u]=1;
    cnt.clear();
    cnt[0]=1;
    for(int e:E[u]){
        if(!was[e]){
            Solve(e,u,1);
            for(int c:tmp)cnt[c]++;
            tmp.clear();
        }
    }
    for(int e:E[u])if(!was[e])Decompose(e);
}
int main(){
    scanf("%i %i",&n,&k);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%i %i",&u,&v);
        E[u].pb(v);E[v].pb(u);
    }
    Decompose(1);
    printf("%lld",ans);
    return 0;
}