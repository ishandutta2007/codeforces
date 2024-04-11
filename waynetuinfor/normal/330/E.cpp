#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
set<pair<int, int>> edge;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    srand(time(nullptr));
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        edge.insert(minmax(a, b));
    }
    vector<int> vec;
    for (int i = 1; i <= n; ++i) vec.push_back(i);
    while (1.0 * clock() / CLOCKS_PER_SEC <= 1.0) {
        random_shuffle(vec.begin(), vec.end()); 
        int cnt = 0;
        for (int i = 0; i < vec.size() - 1; ++i) {
            if (edge.count(minmax(vec[i], vec[i + 1])) == 0) ++cnt;
        }
        if (edge.count(minmax(vec[vec.size() - 1], vec[0])) == 0) ++cnt;
        if (cnt >= m) {
            for (int i = 0; i < vec.size() - 1 && m; ++i) {
                if (edge.count(minmax(vec[i], vec[i + 1])) == 0) {
                    cout << vec[i] << ' ' << vec[i + 1] << endl;
                    --m;
                }
            }
            if (m == 0) return 0;
            cout << vec[vec.size() - 1] << ' ' << vec[0] << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
    return 0;
}