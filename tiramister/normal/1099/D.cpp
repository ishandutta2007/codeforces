#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

const ll INF = 1LL << 50;

int main() {
    int N;
    cin >> N;

    vector<int> child[N + 1];
    int p[N + 1];

    p[1] = 0;
    for (int i = 2; i <= N; ++i) {
        cin >> p[i];
        child[p[i]].push_back(i);
    }

    ll s[N + 1], a[N + 1];
    s[0] = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> s[i];
    }

    ll ans = 0;

    queue<int> que;
    que.push(1);

    while (!que.empty()) {
        int v = que.front();
        que.pop();

        if (s[v] >= 0) {
            a[v] = s[v] - s[p[v]];
        } else {
            if (child[v].empty()) {
                a[v] = 0;
            } else {
                ll minval = INF;
                for (int sv : child[v]) {
                    minval = min(minval, s[sv]);
                }

                a[v] = minval - s[p[v]];
                if (a[v] < 0) {
                    cout << -1 << endl;
                    return 0;
                }
                s[v] = minval;
            }
        }

        ans += a[v];

        for (int sv : child[v]) {
            que.push(sv);
        }
    }

    cout << ans << endl;
    return 0;
}