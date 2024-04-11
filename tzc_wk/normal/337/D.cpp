#include <bits/stdc++.h>
using namespace std;
int dist1[100001],dist2[100001];
vector<int> g[100001];
int p[100001];
int n,m,d;
void dfs(int f,int rt,int depth,int* dist){
    dist[rt]=depth;
    for(int i=0;i<g[rt].size();i++)
        if(g[rt][i]!=f)
			dfs(rt,g[rt][i],depth+1,dist);
}
int main(){
    cin>>n>>m>>d;
    for(int i=0;i<m;i++)	cin>>p[i];
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0,1,0,dist1);
    int mx=0;
    for(int i=0;i<m;i++){
        if(dist1[mx]<dist1[p[i]]) mx=p[i];
    }
    dfs(0,mx,0,dist1);
    mx=0;
    for(int i=0;i<n;i++){
        if(dist1[mx]<dist1[p[i]]) mx=p[i];
    }
    dfs(0,mx,0,dist2);
    int ans=0;
    for(int i=1;i<=n;i++){
        if(dist1[i]<=d&&dist2[i]<=d) ans++;
    }
    cout<<ans<<endl;
    return 0;
}//