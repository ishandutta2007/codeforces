#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
const int MX = 2e5+5;
vector<int> adj[MX];
bool visited[MX];
vector<int> adjR[MX], adjC[MX];
map<pair<int, int>, int> idx;
void dfs(int x) {
    visited[x] = 1;
    for(int next : adj[x]) if(!visited[next]) dfs(next);
}
int main() {
    int n,m,q; cin >> n >> m >> q;
    int r[n], c[m];
    memset(r,0,sizeof(r)), memset(c,0,sizeof(c));
    for(int i=0;i<q;i++) {
        int a, b; cin >> a >> b;
        --a, --b;
        adjR[a].push_back(b);
        adjC[b].push_back(a);
        ++r[a], ++c[b];
        idx[make_pair(a, b)] = i;
    }
    for(int i=0;i<n;i++) {
        for(int j=1;j<adjR[i].size();j++) {
            adj[idx[make_pair(i, adjR[i][j])]].push_back(idx[make_pair(i, adjR[i][j-1])]);
            adj[idx[make_pair(i, adjR[i][j-1])]].push_back(idx[make_pair(i, adjR[i][j])]);
        }
    }
    for(int j=0;j<m;j++) {
        for(int i=1;i<adjC[j].size();i++) {
            adj[idx[make_pair(adjC[j][i-1], j)]].push_back(idx[make_pair(adjC[j][i], j)]);
            adj[idx[make_pair(adjC[j][i], j)]].push_back(idx[make_pair(adjC[j][i-1], j)]);
        }
    }
    int ans = 0;
    for(int i=0;i<q;i++) {
        if(!visited[i]) {
            ++ans;
            dfs(i);
        }
    }
    for(int i=0;i<n;i++) if(r[i]==0) ++ans;
    for(int j=0;j<m;j++) if(c[j]==0) ++ans;
    cout << ans-1 << "\n";
}