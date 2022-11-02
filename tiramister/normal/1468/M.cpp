#line 2 "/Users/tiramister/CompetitiveProgramming/Cpp/CppLibrary/Tools/compress.hpp"

#include <algorithm>
#include <vector>
#include <map>

template <class T>
std::map<T, int> compress(std::vector<T>& v) {
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());

    std::map<T, int> rev;
    for (int i = 0; i < (int)v.size(); ++i) rev[v[i]] = i;
    return rev;
}
#line 2 "main.cpp"
#include <iostream>
#line 4 "main.cpp"
#include <cmath>
#line 6 "main.cpp"

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n);
    int m, sz;
    {
        vector<int> elems;
        for (auto& es : graph) {
            int k;
            cin >> k;

            while (k--) {
                int x;
                cin >> x;
                es.push_back(x);
                elems.push_back(x);
            }
        }

        sz = elems.size();

        auto erev = compress(elems);
        for (auto& es : graph) {
            for (auto& x : es) x = erev[x];
        }
        m = elems.size();
    }

    const int M = sqrt(sz);

    vector<vector<int>> sets(m);
    // x
    vector<int> cnt(m, 0);

    for (int v = 0; v < n; ++v) {
        if ((int)graph[v].size() < M) {
            // small set
            for (auto x : graph[v]) {
                sets[x].push_back(v);
            }
        } else {
            for (auto x : graph[v]) ++cnt[x];

            // large set O(m/M)
            //  O(m)
            for (int u = 0; u < n; ++u) {
                if (u == v) continue;

                int c = 0;
                for (auto x : graph[u]) c += cnt[x];
                if (c >= 2) {
                    cout << u + 1 << " " << v + 1 << "\n";
                    return;
                }
            }

            for (auto x : graph[v]) --cnt[x];
        }
    }

    fill(cnt.begin(), cnt.end(), -1);
    // x

    for (int x = 0; x < m; ++x) {
        // x
        // deg(v) < MO(sum(deg(v)^2)) = O(mM)
        for (auto v : sets[x]) {
            for (auto y : graph[v]) {
                if (y == x) continue;

                if (cnt[y] != -1) {
                    cout << cnt[y] + 1 << " " << v + 1 << "\n";
                    return;
                }
                cnt[y] = v;
            }
        }
        for (auto v : sets[x]) {
            for (auto y : graph[v]) cnt[y] = -1;
        }
    }

    cout << "-1\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int q;
    cin >> q;
    while (q--) solve();

    return 0;
}