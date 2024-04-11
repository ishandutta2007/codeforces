#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=100050;
vector<int> E[N];
bool was[N];
int sz[N];
void DFS(int u,int p){sz[u]=1;for(int e:E[u])if(e!=p&&!was[e])DFS(e,u),sz[u]+=sz[e];}
int Find(int u,int p,int n){for(int e:E[u])if(e!=p&&!was[e]&&sz[e]*2>n)return Find(e,u,n);return u;}
int FindCentroid(int u){DFS(u,u);return Find(u,u,sz[u]);}
char ans[N];
void Decompose(int u,char tmp){
    u=FindCentroid(u);
    //printf("%i\n",u);
    was[u]=1,ans[u]=tmp;
    for(int e:E[u])if(!was[e])Decompose(e,(char)(tmp+1));
}
int main(){
    int n;scanf("%i",&n);
    for(int i=1;i<n;i++){
        int u,v;scanf("%i %i",&u,&v);
        E[u].pb(v),E[v].pb(u);
    }
    Decompose(1,'A');
    for(int i=1;i<=n;i++)printf("%c ",ans[i]);
    return 0;
}