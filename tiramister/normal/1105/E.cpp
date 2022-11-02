#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

set<int> path[40];
map<ll, int> dp;

int rec(ll S) {
    if (S == 0) return 0;
    if (dp.count(S)) return dp[S];

    int& ret = dp[S];

    int l;
    for (l = 0; l < 39; ++l) {
        if ((S >> l) & 1) break;
    }
    S ^= (1LL << l);

    // l
    ret = rec(S);

    // l
    // 
    for (int i : path[l]) S &= ~(1LL << i);
    ret = max(ret, rec(S) + 1);

    return ret;
}

int main() {
    int N, M;
    cin >> N >> M;

    map<string, int> id;
    int cnt = 0;
    vector<vector<int>> groups;
    vector<int> g;

    for (int i = 0; i < N; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            groups.push_back(g);
            g.clear();
        } else {
            string s;
            cin >> s;

            if (id.count(s) == 0) id[s] = cnt++;
            g.push_back(id[s]);
        }
    }
    groups.push_back(g);

    for (auto g : groups) {
        sort(g.begin(), g.end());
        g.erase(unique(g.begin(), g.end()), g.end());

        for (int i = 0; i < g.size(); ++i) {
            for (int j = i + 1; j < g.size(); ++j) {
                path[g[i]].insert(g[j]);
            }
        }
    }

    cout << rec((1LL << M) - 1) << endl;
    return 0;
}