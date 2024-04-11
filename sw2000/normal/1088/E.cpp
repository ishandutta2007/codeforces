#include<bits/stdc++.h>
#define fi first
#define se second
//#define mid (l+r>>1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 1e6 + 10;

struct E{int to,ne;}edg[N];
int n,w[N],head[N],cnt;
ll arr[N],mid=-2e9,ans;
void add(int u,int v){
    edg[++cnt]={v,head[u]};
    head[u]=cnt;
}
void dfs0(int u,int f){
    arr[u]=w[u];
    for(int i=head[u];i;i=edg[i].ne)if(edg[i].to!=f){
        dfs0(edg[i].to,u);
        arr[u]+=arr[edg[i].to];
    }
    mid=max(mid,arr[u]);
    arr[u]=max(0ll,arr[u]);
}
void dfs(int u,int f){
    arr[u]=w[u];
    for(int i=head[u];i;i=edg[i].ne)if(edg[i].to!=f){
        dfs(edg[i].to,u);
        arr[u]+=arr[edg[i].to];
    }
    if(arr[u]>=mid){
        arr[u]=0;
        ans++;
    }
    arr[u]=max(0ll,arr[u]);
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>w[i];
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    dfs0(1,0);
    dfs(1,0);
    cout<<mid*ans<<" "<<ans<<endl;
	return 0;
}