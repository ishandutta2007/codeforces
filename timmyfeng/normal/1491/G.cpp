#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 1;

vector<array<int, 2>> ans;
bool visited[N];
int c[N];

void apply(int a, int b) {
    swap(c[a], c[b]);
    c[a] *= -1, c[b] *= -1;
    ans.push_back({a, b});
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }

    vector<vector<int>> cycles;
    for (int i = 1; i <= n; ++i) {
        int j = i;
        vector<int> path;
        while (!visited[j]) {
            path.push_back(j);
            visited[j] = true;
            j = c[j];
        }

        if (path.size() > 1) {
            cycles.push_back(path);
        }
    }

    while (cycles.size() >= 2) {
        vector<int> a = cycles[cycles.size() - 1];
        vector<int> b = cycles[cycles.size() - 2];
        cycles.pop_back(), cycles.pop_back();

        apply(a[0], b[0]);
        for (int i = 1; i < (int) a.size(); ++i) {
            apply(a[i], b[0]);
        }
        for (int i = 1; i < (int) b.size(); ++i) {
            apply(a[0], b[i]);
        }
        apply(a[0], b[0]);
    }

    if (!cycles.empty()) {
        vector<int> a = cycles[0];
        cycles.pop_back();

        if (a.size() > 2) {
            for (int i = 1; i < (int) a.size() - 1; ++i) {
                apply(a[0], a[i]);
            }
            apply(a[1], a.back());
            apply(a[0], a.back());
            apply(a[0], a[1]);
        } else {
            for (int i = 1; i <= n; ++i) {
                if (i == c[i]) {
                    apply(i, a[0]);
                    apply(i, a[1]);
                    apply(i, a[0]);
                    break;
                }
            }
        }
    }

    cout << ans.size() << "\n";
    for (auto [a, b] : ans) {
        cout << a << " " << b << "\n";
    }
}