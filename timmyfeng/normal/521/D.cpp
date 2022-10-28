#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

struct upgrade {
    long long x = 0, y = 1;
    int i = -1;

    bool operator<(upgrade oth) const {
        if (x * oth.y == y * oth.x) {
            return i < oth.i;
        } else {
            return x * oth.y < y * oth.x;
        }
    }
};

vector<upgrade> add[N];
long long skill[N];
upgrade maxi[N];
bool first[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, n, m;
    cin >> k >> n >> m;

    for (int i = 0; i < k; ++i) {
        cin >> skill[i];
    }

    vector<upgrade> multiply;
    for (int i = 0; i < n; ++i) {
        int t, b;
        long long a;
        cin >> t >> a >> b;

        if (t == 1) {
            maxi[a - 1] = max(maxi[a - 1], upgrade{b, 1, i});
            first[i] = true;
        } else {
            (t == 2 ? add[a - 1] : multiply).push_back({b, 1, i});
        }
    }

    sort(multiply.rbegin(), multiply.rend());
    int t = multiply.size();

    priority_queue<upgrade> que;

    for (int i = 0; i < k; ++i) {
        maxi[i].x -= skill[i];
        if (maxi[i].x > 0) {
            add[i].push_back(maxi[i]);
        }

        sort(add[i].begin(), add[i].end());

        if (!add[i].empty()) {
            que.push({add[i].back().x + skill[i], skill[i], i});
        }
    }

    vector<int> ans;

    while (!que.empty() && m > 0) {
        upgrade u = que.top();
        if (m <= t && u < multiply[m - 1]) {
            break;
        }
        que.pop();

        ans.push_back(add[u.i].back().i);
        add[u.i].pop_back();
        skill[u.i] = u.x;
        --m;

        if (!add[u.i].empty()) {
            que.push({add[u.i].back().x + skill[u.i], skill[u.i], u.i});
        }
    }

    for (int i = 0; i < m && i < t; ++i) {
        ans.push_back(multiply[i].i);
    }

    cout << ans.size() << "\n";
    for (int k = 0; k < 2; ++k) {
        for (auto i : ans) {
            if (first[i] ^ (k == 1)) {
                cout << i + 1 << " ";
            }
        }
    }
    cout << "\n";
}