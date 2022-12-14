#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int mod=1e9+7;

int n,m,w[N],vis[N];
vector<int>edg[N];
ll s[2];
bool dfs(int u,int c){
    vis[u]=c;
    s[c]+=w[u];
    for(auto v:edg[u])if(vis[v]==-1){
        if(!dfs(v,c^1))return 0;
    }
    else if(vis[v]==c)return 0;
    return 1;
}
bool solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)vis[i]=-1;
    for(int i=1;i<=n;i++)cin>>w[i];
    ll sum=0;
    s[0]=s[1]=0;
    for(int i=1;i<=n;i++){
        int a;cin>>a;
        w[i]-=a;
        sum+=w[i];
    }
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        edg[a].push_back(b);
        edg[b].push_back(a);
    }
    if(dfs(1,0))return s[0]==s[1];
    else return sum%2==0;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("A.in","r",stdin);
    int _;cin>>_;
    while(_--){
        cout<<(solve()?"YES":"NO")<<'\n';
        for(int i=1;i<=n;i++)edg[i].clear();
    }
}