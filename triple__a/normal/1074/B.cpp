#include<bits/stdc++.h>
#define ULL unsigned long long
#define F first
#define S second
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define range(a) a.begin(), a.end()
#define PI pair<int,int>
#define VI vector<int>
 
using namespace std;
 
typedef long long ll;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn=2007;

int t,n,k1[maxn],k2[maxn];
bool v1[maxn],v2[maxn];
VI vec[maxn];

int bfs(int u){
    bool vis[maxn];
    for (int i=1;i<=n;++i) vis[i]=0;
    queue<int> q;
    q.push(u);
    vis[u]=1;
    while (q.size()){
        int r=q.front();
        q.pop();
        if (v1[r]) return r;
        for (auto c:vec[r]){
            if (vis[c]) continue;
            q.push(c);
            vis[c]=1;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while (t--){
        cin>>n;
        rep1(i,n) vec[i].clear(),v1[i]=v2[i]=0;
        rep1(i,n-1){
            int u,v;
            cin>>u>>v;
            vec[u].pb(v), vec[v].pb(u);
        }
        int u,v;
        cin>>u;
        rep1(i,u){
            cin>>k1[i];
            v1[k1[i]]=1;
        }
        cin>>v;
        rep1(i,v){
            cin>>k2[i];
            v2[k2[i]]=1;
        }
        cout<<"B "<<k2[1]<<endl;
        int ans;
        cin>>ans;
        if (v1[ans]) {cout<<"C "<<ans<<endl; continue;}
        ans=bfs(ans);
        cout<<"A "<<ans<<endl;
        int ret=ans;
        cin>>ans;
        if (v2[ans]) cout<<"C "<<ret<<endl;
        else cout<<"C -1"<<endl;
    }
    return 0;
}