#include <bits/stdc++.h>

using namespace std;

const int N=1e6+10;
const long long linf=1e16+10;
int n,m;

int vis[N],use_e[N],sub[N];
int w[N];
int ans[N];
int v[N][2];
vector <int> e[N];
void DFS(int st){
        vis[st]=1;
        sub[st]=w[st];
        for(auto i:e[st]) if (!use_e[i]){
                use_e[i]=1;
                int dir=v[i][1]==st;
                int y=v[i][dir^1];
                if (!vis[y]){
                        DFS(y);
                        ans[i]=sub[y];
                        if (dir==1) ans[i]*=-1;
                        sub[st]+=sub[y];
                }
        }
}

void solve(){
        int all_flow=0;
        for(int i=1;i<=n;i++) all_flow+=w[i];
        if (all_flow!=0){
                cout<<"Impossible";
                return;
        }
        DFS(1);
        cout<<"Possible\n";
        for(int i=1;i<=m;i++) cout<<ans[i]<<'\n';
}
int main(){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>w[i];
        cin>>m;
        for(int i=1;i<=m;i++){
                int x,y;
                cin>>x>>y;
                v[i][0]=x;
                v[i][1]=y;
                e[x].push_back(i);
                e[y].push_back(i);
        }
        solve();
}