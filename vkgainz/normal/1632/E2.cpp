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
 
vector<int> st, en;
vector<vector<int>> adj;
vector<int> depth, dist, par;
vector<int> top;
int r;

void dfs(int curr, int pare) {
    st[curr] = r++;
    for (int next : adj[curr]) {
        if (next == pare) continue;
        depth[next] = depth[curr] + 1;
        par[next] = curr;
        dfs(next, curr);
        dist[curr] = max(dist[curr], dist[next] + 1);
    }
    en[curr] = r++;
}

int curr_par;

int add(int x, int curr, int largest) {
    //increment until d(curr, largest) >= d(curr, x)
    if (st[curr_par] <= st[x] && en[x] <= en[curr_par]) {
        int dl = depth[largest] - depth[curr];
        int dr = depth[curr] - depth[curr_par] + depth[x] - depth[curr_par];
        if (dl >= dr) {
            return curr;
        } else {
            return add(x, par[curr], largest);
        }
    } else {
        curr_par = par[curr_par];
        return add(x, curr, largest);
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        r = 0;
        int n; cin >> n;
        st.resize(n), en.resize(n);
        adj.clear(); adj.resize(n);
        dist.clear(); dist.resize(n);
        depth.clear(); depth.resize(n);
        par.clear(); par.resize(n);
        for (int i = 0; i < n - 1; i++) {
            int u, v; cin >> u >> v;
            --u, --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0, -1);
        int largest = 0;
        vector<vector<int>> d(n);
        for (int i = 0; i < n; i++) {
            if (depth[i] > depth[largest]) {
                largest = i;
            }
            d[depth[i]].push_back(i);
        }
        //for each k, can get the vertex we need to add to!
        //then calculate x easily ==> gg....
        curr_par = largest;
        int curr = largest;
        vector<int> ans(n);
        ans[n - 1] = n;
        for (int i = n - 2; i >= 0; i--) {
            for (int put : d[i + 1]) {
                curr = add(put, curr, largest);
                //get x such that all accessible at a dist <= i
            }
            if (i >= depth[largest]) {
                ans[i] = n;
            } else {
                int x = i - (depth[largest] - depth[curr]);
                ans[i] = x;
            }
        }
        vector<int> ret(n + 1);
        for (int i = n - 2; i >= 0; i--) {
            for (int j = ans[i] + 1; j <= ans[i + 1]; j++) {
                if (j > 0)
                    ret[j] = i + 1;
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << ret[i] << " ";
        }
        cout << "\n";
    }
}