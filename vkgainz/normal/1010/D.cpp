#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define f first
#define s second
const int MX = 1e6+5;
int c[MX];
vector<int> adj[MX];
int type[MX];
int ans[MX];
void dfs(int curr, int par) {
    if(type[curr]==-1) {
        ans[curr] = c[curr];
        return;
    }
    dfs(adj[curr][0], curr);
    int a = ans[adj[curr][0]];
    if(adj[curr].size()>1) {
        dfs(adj[curr][1], curr);
        int b = ans[adj[curr][1]];
        if(type[curr]==1) ans[curr] = a&b;
        if(type[curr]==2) ans[curr] = a|b;
        if(type[curr]==3) ans[curr] = a^b;
    }
    else {
        ans[curr] = 1-a;
    }
}
bool pos[MX];
void dfs2(int curr, int par) {
    if(type[curr]==-1) {
        pos[curr] = 1;
        return;
    }
    if(type[curr]==0) {
        dfs2(adj[curr][0], curr);
    }
    if(type[curr]==1) {
        if(ans[adj[curr][0]]==1) dfs2(adj[curr][1], curr);
        if(ans[adj[curr][1]]==1) dfs2(adj[curr][0], curr);
    }
    if(type[curr]==2) {
        if(ans[adj[curr][0]]==0) dfs2(adj[curr][1], curr);
        if(ans[adj[curr][1]]==0) dfs2(adj[curr][0], curr);
    }
    if(type[curr]==3) {
        dfs2(adj[curr][0], curr);
        dfs2(adj[curr][1], curr);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    for(int i=0;i<n;i++) {
        string s; cin >> s;
        if(s=="IN") {
            int x; cin >> x;
            c[i] = x;
            type[i] = -1;
            continue;
        }
        if(s=="NOT") {
            int x; cin >> x;
            --x;
            adj[i].push_back(x);
            type[i] = 0;
        }
        else {
            int x,y; cin >> x >> y;
            --x, --y;
            adj[i].push_back(x);
            adj[i].push_back(y);
            if(s=="AND") type[i] = 1;
            if(s=="OR") type[i] = 2;
            if(s=="XOR") type[i] = 3;
        }
    }
    dfs(0, -1);
    dfs2(0, -1);
    string ret = "";
    for(int i=0;i<n;i++) {
        if(type[i]==-1){ 
            if(pos[i]) {
                ret+=to_string(1-ans[0]);
            }
            else {
                ret+=to_string(ans[0]);
            }
        }

    }
    cout << ret << endl;
}