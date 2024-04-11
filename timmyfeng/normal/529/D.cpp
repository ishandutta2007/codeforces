#include <bits/stdc++.h>
using namespace std;

const int N = 20000;

int request[N], order[N], ans[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, t;
    scanf("%d %d %d\n", &n, &m, &t);

    for (int i = 0; i < n; ++i) {
        int h, m, s;
        scanf("%d:%d:%d\n", &h, &m, &s);
        request[i] = 60 * (60 * h + m) + s;
    }

    iota(order, order + n, 0);
    sort(order, order + n, [&](int a, int b) {
        return request[a] < request[b];
    });

    int r = 0;
    bool record = false;
    set<array<int, 2>> logoff;
    for (int i = 0; i < n; ++i) {
        int a = order[i];

        while (!logoff.empty() && (*logoff.begin())[0] <= request[a]) {
            logoff.erase(logoff.begin());
        }

        if ((int) logoff.size() == m) {
            ans[a] = (*--logoff.end())[1];
            logoff.erase(--logoff.end());
        } else {
            ans[a] = ++r;
        }

        logoff.insert({request[a] + t, ans[a]});
        record |= ((int) logoff.size() == m);
    }

    if (record) {
        cout << r << "\n";
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << "\n";
        }
    } else {
        cout << "No solution\n";
    }
}