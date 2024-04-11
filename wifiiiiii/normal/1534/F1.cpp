#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 400005;
vector<int> g[maxn];
int low[maxn],dfn[maxn],dfscnt=0;
int st[maxn],ins[maxn],tp=0;
int scc[maxn],sccno=0;
void tarjan(int u) {
    low[u]=dfn[u]=++dfscnt;
    st[++tp]=u,ins[u]=1;
    for(int v:g[u]) {
        if(!dfn[v]) tarjan(v),low[u]=min(low[u],low[v]);
        else if(ins[v]) low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u]) {
        ++sccno;
        int p=-1;
        while(p!=u) p=st[tp--],ins[p]=0,scc[p]=sccno;
    }
}
int dir1[4]={-1,1,0,0};
int dir2[4]={0,0,1,-1};
int deg[maxn];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<char>> a(n,vector<char>(m));
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            cin>>a[i][j];
        }
    }
    auto get=[&](int x,int y) {return x*m+y;};
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            if(a[i][j]=='#') {
                int x=i,y=j,u=get(x,y);
                while(1) {
                    for(int k=0;k<4;++k) {
                        int xx=x+dir1[k],yy=y+dir2[k];
                        if(xx<0||yy<0||xx>=n||yy>=m||a[xx][yy]=='.') continue;
                        int v=get(xx,yy);
                        g[u].push_back(v);
                    }
                    ++x;
                    if(x==n || a[x][y]=='#') break;
                }
            }
        }
    }
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            if(a[i][j]=='#') {
                int u=get(i,j);
                if(dfn[u]) continue;
                tarjan(u);
            }
        }
    }
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            if(a[i][j]=='#') {
                int u=get(i,j);
                for(int v:g[u]) {
                    if(scc[u]!=scc[v]) {
                        deg[scc[v]]++;
                    }
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=sccno;++i) if(!deg[i]) ++ans;
    cout<<ans<<endl;
}