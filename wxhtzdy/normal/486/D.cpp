#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
const int N=2050;
const int mod=1e9+7;
vector<int> E[N];
int a[N];
ll DFS(int u,int p,int bot,int top,int id){
    if(a[u]<bot||a[u]>top)return 0;
    if(a[u]==bot&&u>id)return 0;
    ll ans=1;
    for(int e:E[u]){
        if(e!=p)ans*=DFS(e,u,bot,top,id)+1,ans%=mod;
    }
    return ans;
}
int main(){
    int d,n;scanf("%i %i",&d,&n);
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
    for(int i=1;i<n;i++){
        int u,v;scanf("%i %i",&u,&v);
        --v,--u;
        E[u].pb(v);E[v].pb(u);
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        ans+=DFS(i,i,a[i],a[i]+d,i);
        ans%=mod;
    }
    printf("%lld",ans);
    return 0;
}