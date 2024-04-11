#include <bits/stdc++.h>
using namespace std;
const int N=50050;
int n,r1,r2,ans[N];
vector<int> E[N];
void DFS(int u,int p){
    ans[u]=p;
    for(int v:E[u])if(v!=p)DFS(v,u);
}
int main(){
    scanf("%i%i%i",&n,&r1,&r2);
    for(int i=1;i<=n;i++){
        if(i==r1)continue;
        int par;scanf("%i",&par);
        E[par].push_back(i);
        E[i].push_back(par);
    }
    DFS(r2,r2);
    for(int i=1;i<=n;i++){
        if(i!=r2)printf("%i ",ans[i]);
    }
    return 0;
}