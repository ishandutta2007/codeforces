#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7;
int perm[N];
pair <int, int> v[N];
vector <pair <int, int>> s[N];

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("Desktop/input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i].first >> v[i].second;
        s[v[i].first].push_back({v[i].second, i});
    }
    set <pair <int, int>> best;
    vector <pair <int, int>> ch;
    for (int i = 1; i <= n; i++) {
        for (auto elem : s[i]) best.insert(elem);
        assert(!best.empty());
        int p = (*best.begin()).second;
        perm[p] = i;
        best.erase(best.begin());
        if (!best.empty()) {
            ch.push_back({p, (*best.begin()).second});
        }
    }
    pair <int, int> res = {-1, -1};
    for (auto [a, b] : ch) {
        if (v[b].first <= perm[a] && perm[a] <= v[b].second) {
            if (v[a].first <= perm[b] && perm[b] <= v[a].second) {
                res = {a, b};
                break;
            }
        }
    }
    if (res.first == -1) {
        cout << "YES" << endl;
        for (int i = 1; i <= n; i++) cout << perm[i] << ' ';
        cout << endl;
    } else {
        cout << "NO" << endl;
        for (int i = 1; i <= n; i++) cout << perm[i] << ' ';
        cout << endl;
        swap(perm[res.first], perm[res.second]);
        for (int i = 1; i <= n; i++) cout << perm[i] << ' ';
        cout << endl;
    }
    return 0;
}