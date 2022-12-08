#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int maxn = 300005;
vector<int> g[maxn], g2[maxn];
int f[maxn][20], sz[maxn], dep[maxn], dfn[maxn], dfscnt=0;
int bit[maxn];
void add(int x,int v){for(;x<maxn;x+=x&-x)bit[x]+=v;}
int sum(int x) {int ret=0;for(;x;x-=x&-x)ret+=bit[x];return ret;}
int sum(int l, int r) {return sum(r)-sum(l-1);}
void dfs(int u) {
    dfn[u] = ++dfscnt;
    sz[u] = 1;
    for(int v : g[u]) {
        dep[v] = dep[u] + 1;
        f[v][0] = u;
        for(int i=1;i<=19;++i) f[v][i] = f[f[v][i-1]][i-1];
        dfs(v);
        sz[u] += sz[v];
    }
}
pair<int,int> mem[maxn];
int tp=0,cur=0;
void ins(int u) {
    if(sum(dfn[u], dfn[u]+sz[u]-1)) return;
    int x = u;
    for(int i=19;i>=0;--i) {
        if(f[x][i] && !sum(dfn[f[x][i]], dfn[f[x][i]]+sz[f[x][i]]-1)) x = f[x][i];
    }
    if(u != 1) {
        int p = f[x][0];
        if(sum(dfn[p], dfn[p])) {
            mem[++tp] = {dfn[p], 1};
            add(dfn[p], -1);
            --cur;
        }
    }
    mem[++tp] = {dfn[u], -1};
    add(dfn[u], 1);
    ++cur;
}
int ans = 0;
void dfs2(int u) {
    int pretp = tp;
    ins(u);
    ans = max(ans, cur);
    for(int v : g2[u]) dfs2(v);
    for(int i=pretp+1;i<=tp;++i) {
        int rt;
        for(int j=1;;++j) {
            if(dfn[j]==mem[i].first) {
                rt=j;
                break;
            }
        }
        cur += mem[i].second;
        add(mem[i].first, mem[i].second);
    }
    tp = pretp;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        ans = 0;
        int n;
        cin >> n;
        for(int i=1;i<=n;++i) {
            g[i].clear();
            g2[i].clear();
            for(int j=0;j<=19;++j) f[i][j]=0;
            dfscnt=cur=ans=tp=0;
        }
        for(int i=2;i<=n;++i) {
            int x;
            cin>>x;
            g2[x].push_back(i);
        }
        for(int i=2;i<=n;++i) {
            int x;
            cin>>x;
            g[x].push_back(i);
        }
        dfs(1);
        dfs2(1);
        cout << ans << '\n';
    }
}