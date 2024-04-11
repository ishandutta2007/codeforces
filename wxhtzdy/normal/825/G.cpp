#include <bits/stdc++.h>
using namespace std;
const int N=1000050;
int n,q,last,T,x,mn[N],mnn=N,par[N];
bool was[N];
vector<int> e[N];
void dfs(int u,int p){
        if(u==p)mn[u]=u;
        else mn[u]=min(u,mn[p]);
        par[u]=p;
        for(int v:e[u])if(v^p)dfs(v,u);
}
void upd(int u){
        if(was[u])return;
        was[u]=u;mnn=min(mnn,u);
        upd(par[u]);
}
int main(){
        scanf("%d%d",&n,&q);
        for(int i=1,u,v;i<n;i++){
                scanf("%d%d",&u,&v);
                e[u].push_back(v);
                e[v].push_back(u);
        }
        for(int i=1;i<=q;i++){
                scanf("%d",&T);
                if(T==1){
                        scanf("%d",&x);
                        x=(x+last)%n+1;
                        if(i==1)dfs(x,x);
                        else upd(x);
                }else{
                        scanf("%d",&x);
                        x=(x+last)%n+1;
                        last=min(mnn,mn[x]);
                        printf("%d\n",last);
                }
        }
}