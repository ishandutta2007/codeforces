#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
const int N=100050;
ll a[N],sum[N][2];
vector<int> E[N];
void DFS(int u,int p){
    for(int v:E[u])if(v!=p){
        DFS(v,u);
        sum[u][0]=max(sum[u][0],sum[v][0]);
        sum[u][1]=max(sum[u][1],sum[v][1]);
    }
    a[u]+=sum[u][0];
    a[u]-=sum[u][1];
    if(a[u]<0)sum[u][0]+=abs(a[u]);
    else sum[u][1]+=a[u];
}
int main(){
    int n;scanf("%i",&n);
    for(int i=1;i<n;i++){
        int u,v;scanf("%i%i",&u,&v);
        E[u].pb(v);
        E[v].pb(u);
    }
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    DFS(1,0);
    printf("%lld",sum[1][0]+sum[1][1]);
    return 0;
}