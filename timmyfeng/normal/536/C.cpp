#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

long long x[N], y[N];
vector<int> ids[N];
int order[N];

long long cross(int a, int b, int c) {
    return x[c] * y[c] * (x[b] * y[a] - x[a] * y[b]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    iota(order, order + n, 0);
    sort(order, order + n, [&](int a, int b) {
        return x[a] == x[b] ? y[a] > y[b] : x[a] > x[b];
    });

    vector<int> hull;
    for (int i = 0, j = 0; i < n; i = j) {
        int a = order[i];

        while (hull.size() >= 2) {
            int b = hull[hull.size() - 1], c = hull[hull.size() - 2];
            if (cross(a, c, b) + cross(b, a, c) + cross(c, b, a) >= 0) {
                break;
            }
            hull.pop_back();
        }

        hull.push_back(a);

        while (j < n && x[order[j]] == x[a] && y[order[j]] == y[a]) {
            ids[a].push_back(order[j++]);
        }
    }

    while (hull.size() >= 2) {
        int a = hull[hull.size() - 1], b = hull[hull.size() - 2];
        if (y[b] < y[a]) {
            break;
        }
        hull.pop_back();
    }

    vector<int> ans;
    for (auto i : hull) {
        ans.insert(ans.begin(), ids[i].begin(), ids[i].end());
    }
    sort(ans.begin(), ans.end());

    for (auto i : ans) {
        cout << i + 1 << " ";
    }
    cout << "\n";
}