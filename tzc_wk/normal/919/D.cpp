#include <bits/stdc++.h>
using namespace std;
const int MAXN=3e5+50;
int n,m,f[MAXN][26],head[MAXN],cnt,deg[MAXN];
char a[MAXN];
struct Edge{
    int to,next;
};
Edge edge[MAXN*2];
void add(int u,int v){
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
void toposort(){
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(!deg[i]){
            q.push(i);
            f[i][a[i-1]-'a']++;
        }
    }
    int cnt=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        cnt++;
        for(int i=head[u];i!=-1;i=edge[i].next){
            int v=edge[i].to;
            deg[v]--;
            if(!deg[v]) q.push(v);
            for(int j=0;j<26;j++)
				f[v][j]=max(f[v][j],f[u][j]+int(a[v-1]-'a'==j));
        }
    }
    if(cnt<n) cout<<"-1\n";
    else{
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<26;j++){
                ans=max(ans,f[i][j]);
            }
        }
        cout<<ans<<endl;
    }
}
 
int main(){
    cin>>n>>m>>a;
    memset(head,-1,sizeof(head));
    cnt = 0;
    int u,v;
    for(int i = 0; i < m; i ++){
        cin>>u>>v;
        deg[v]++;
        add(u,v);
    }
    toposort();
    return 0;
}