#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iomanip>
#include <set>
#include <map>
#include <queue>

using namespace std;

int adj[48][48];
vector<int> ans;

void recurse(vector<int> idx, int N, bool need) {
    if (idx.size() == 5) {
        ans = idx;
        return;
    }
    int st = (idx.size() == 0) ? 0 : idx.back() + 1;
    for (int j = st; j < N; j++) {
        int sum = 0;
        for (int i : idx) {
            sum += adj[i][j];
        }
        if (sum == idx.size() && need) {
            idx.push_back(j);
            recurse(idx, N, need);
            idx.pop_back();
        } else if (sum == 0 && !need) {
            idx.push_back(j);
            recurse(idx, N, need);
            idx.pop_back();
        }
    }
}

int main() {
    int N, M; cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        if (u <= 47 && v <= 47) {
            adj[u][v] = 1;
            adj[v][u] = 1;
        }
    }
    N = min(N, 48);
    recurse({}, N, 0);
    recurse({}, N, 1);
    if (ans.size() == 5) {
        for (int x : ans) {
            cout << x + 1 << " ";
        }
        cout << "\n";
    } else {
        cout << -1 << "\n";
    }
}