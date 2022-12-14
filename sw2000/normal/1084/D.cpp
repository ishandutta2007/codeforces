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
const int mod=1e9+7;
const int N=6e5+10;
int n;
ll arr[N],ans;
struct E{int to,ne,w;}e[N];
int head[N],cnt;
void add_edg(int u,int v,int w){
    e[cnt]={v,head[u],w},head[u]=cnt++;
}
void dfs(int u,int f){
    ll ma=0,maa=0;
    for(int i=head[u];~i;i=e[i].ne){
        int v=e[i].to,w=e[i].w;
        if(v==f)continue;
        dfs(v,u);
        ll t=arr[v]-w;
        if(t>ma){
            maa=ma;
            ma=t;
        }
        else if(t>maa){
            maa=t;
        }
    }
    ans=max(ans,arr[u]+ma+maa);
    arr[u]+=ma;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    cin>>n;
    memset(head,-1,sizeof(head));
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=0;i<n-1;i++){
        int u,v,w;cin>>u>>v>>w;
        add_edg(u,v,w);
        add_edg(v,u,w);
    }
    dfs(1,0);
    cout<<ans;
	return 0;
}