#include<bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 600+10;
const int mod=998244353;

struct A{
    int to,w,ne;
}e[N*N];
int head[N],tot;
void add_edg(int u,int v,int w){
    e[tot]={v,w,head[u]};
    head[u]=tot++;
}
int n,m;
ll ans[N];
bool vis[N];
void solve(int c){
    memset(ans,0x3f,sizeof(ans));
    memset(vis,0,sizeof(vis));
    for(int i=head[c];~i;i=e[i].ne){
        ans[e[i].to]=e[i].w;
    }
    while(1){
        int u=-1;
        ll mi=linf;
        for(int i=0;i<n;i++){
            if(!vis[i]&&ans[i]<mi){
                mi=ans[i];
                u=i;
            }
        }
        if(u==-1)break;
        vis[u]=1;
        ans[(u+1)%n]=min(ans[(u+1)%n],ans[u]+1);
        for(int i=head[u];~i;i=e[i].ne){
            int v=(e[i].to+ans[u])%n,w=e[i].w;
            ans[v]=min(ans[v],ans[u]+w);
        }
    }
    ans[c]=0;
    for(int i=0;i<n;i++)cout<<ans[i]<<' ';
    cout<<endl;
}
int main(){
    memset(head,-1,sizeof(head));
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
    cin>>n>>m;
    while(m--){
        int u,v,w;cin>>u>>v>>w;
        add_edg(u,v,w);
    }
    for(int i=0;i<n;i++)solve(i);
}