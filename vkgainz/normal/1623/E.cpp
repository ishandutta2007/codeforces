#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <math.h>
#include <array>
#include <numeric>
#include <unordered_set>
using namespace std;
 
vector<array<int, 2>> adj;
vector<int> nxt;
vector<int> lst;
vector<int> ord;
vector<bool> mark;
vector<int> depth;
vector<int> p;

void dfs(int curr, int par, bool left = false) {
    if (curr == -1)
        return;
    if (par != -1) {
        depth[curr] = depth[par] + 1;
    }
    if (left) {
        lst[curr] = lst[par];
    } else {
        lst[curr] = par;
    }
    dfs(adj[curr][0], curr, true);
    ord.push_back(curr);
    p[curr] = par;
    dfs(adj[curr][1], curr, false);
}

int main() {
    int n, k; cin >> n >> k;
    string c; cin >> c;
    adj.resize(n);
    nxt.resize(n, -1);
    lst.resize(n, -1);
    depth.resize(n);
    p.resize(n);
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        --l, --r;
        adj[i][0] = l;
        adj[i][1] = r;
    }
    dfs(0, -1);
    for (int i = ord.size() - 1; i >= 0; i--) {
        int curr = ord[i];
        if (i == ord.size() - 1) {
            nxt[curr] = -1;
        } else {
            if (c[curr] != c[ord[i + 1]]) {
                nxt[curr] = c[ord[i + 1]] - 'a';
            } else {
                nxt[curr] = nxt[ord[i + 1]];
            }
        }
    }
    string ans = "";
    mark.resize(n, false);
    for (int i = 0; i < ord.size(); i++) {
        int curr = ord[i];
        if (!mark[curr] && nxt[curr] != -1 && c[curr] - 'a' < nxt[curr]) {
            //want to potentially mark it
            bool up = false;
            up |= lst[curr] == -1 && k >= depth[curr] + 1;
            up |= lst[curr] != -1 && mark[lst[curr]]
                && k >= depth[curr] - depth[lst[curr]];
            for (int x = curr; up && x != lst[curr] && !mark[x]; x = p[x]) {
                mark[x] = true;
                --k;
            }
        }
        if (mark[curr]) {
            ans += c[curr];
        }
        ans += c[curr];
    }
    cout << ans << "\n";
}