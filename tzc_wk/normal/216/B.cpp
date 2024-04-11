#include <bits/stdc++.h>
using namespace std;
int vis[105];
vector<int> g[105];
int cnt;
int start;
bool dfs(int cur,int last)
{
    vis[cur]=1;
    if(last&&start==cur) return true;
    cnt++;
    for(int i=0;i<g[cur].size();i++)
        if(g[cur][i]!=last)
            if(dfs(g[cur][i],cur)) return true;
    return false;
}
int main(){
    int n,m,a,b;
    cin>>n>>m;
    for(int i=0;i<m;i++){
    	cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cnt=0;
            start=i;
            if(dfs(i,0)&&cnt%2) ans++;
    	}
    }
    if((n-ans)%2) ans++;
    cout<<ans<<endl;
    return 0;
}