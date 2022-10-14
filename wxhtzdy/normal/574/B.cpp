#include <bits/stdc++.h>
using namespace std;
void ckmin(int&a,int b){a=min(a,b);}
void ckmax(int&a,int b){a=max(a,b);}
const int N=4050;
int u[N],v[N],con[N][N],deg[N];
bool was[N];
int Comp(int a,int b,int c){
    return con[a][b]*2+con[a][c]*2+con[b][c]*2;
}
int main(){
    int n,m;scanf("%i%i",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%i%i",&u[i],&v[i]);
        con[u[i]][v[i]]=con[v[i]][u[i]]=1;
        deg[u[i]]++,deg[v[i]]++;
    }
    int ans=N;
    for(int i=1;i<=m;i++){
        for(int j=i+1;j<=m;j++){
            if(u[i]==u[j]&&con[v[i]][v[j]])ckmin(ans,deg[u[i]]+deg[v[i]]+deg[v[j]]-Comp(u[i],v[i],v[j]));
            if(u[i]==v[j]&&con[v[i]][u[j]])ckmin(ans,deg[u[i]]+deg[v[i]]+deg[u[j]]-Comp(u[i],v[i],u[j]));
            if(v[i]==u[j]&&con[u[i]][v[j]])ckmin(ans,deg[u[i]]+deg[v[i]]+deg[v[j]]-Comp(u[i],v[i],v[j]));
            if(v[i]==v[j]&&con[u[i]][u[j]])ckmin(ans,deg[u[i]]+deg[v[i]]+deg[u[j]]-Comp(u[i],v[i],u[j]));
        }
    }
    if(ans==N)printf("-1");
    else printf("%i",ans);
    return 0;
}