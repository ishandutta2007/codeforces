#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 1;

vector<int> difficulty[N];
int a[N], t[N], order[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    multiset<int> problems;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> t[i];
        problems.insert(t[i]);
        difficulty[a[i]].push_back(i);
    }

    int solved = 0, sum = 0, ans = 0;

    for (int i = 1; i <= n; ++i) {
        while (!problems.empty() && solved < i) {
            int t = *problems.begin();
            problems.erase(problems.begin());
            ++solved;
            sum += t;
        }

        if (solved == i && sum <= k) {
            ans = solved;
        }

        for (auto u : difficulty[i]) {
            auto it = problems.find(t[u]);
            if (it == problems.end()) {
                sum -= t[u];
                --solved;
            } else {
                problems.erase(it);
            }
        }
    }

    iota(order, order + n, 0);
    sort(order, order + n, [&](int a, int b) {
        return t[a] < t[b];
    });

    cout << ans << "\n";
    cout << ans << "\n";
    for (int i = 0, j = 0; j < ans; ++i) {
        if (a[order[i]] >= ans) {
            cout << order[i] + 1 << " ";
            ++j;
        }
    }
    cout << "\n";
}