#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define pb push_back
#define clr(i) memset(i,0,sizeof(i))

typedef pair<int,int> pii;
typedef long long ll;

vector<int> g[100005];
int vis[100005];
vector<int> ans;
priority_queue<int,vector<int>,greater<int> > p;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        int u,v;cin>>u>>v;
        g[u].pb(v);g[v].pb(u);
    }
    p.push(1);
    vis[1] = 1;
    while(!p.empty())
    {
        int cur = p.top();p.pop();
        ans.pb(cur);
        for(int i=0;i<g[cur].size();++i)
        {
            int v = g[cur][i];
            if(vis[v]) continue;
            vis[v] = 1;
            p.push(v);
        }
    }
    for(int i:ans) cout<<i<<" ";
    cout << endl;
}