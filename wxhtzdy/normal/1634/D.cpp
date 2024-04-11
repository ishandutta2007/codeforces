#include <bits/stdc++.h>

using namespace std;

int n;
bool was[1005];

int ask(vector<int> v) {
    printf("? %d %d %d\n", v[0], v[1], v[2]);
    fflush(stdout);
    int x;
    scanf("%d", &x);
    return x;
}

vector<int> solve(vector<int> v) {
    vector<int> a(4);
    for (int i = 0; i < 4; i++) {
        vector<int> qq;
        for (int j = 0; j < 4; j++) {
            if (i != j) {
                qq.push_back(v[j]);
            }
        }
        a[i] = ask(qq);
    }
    vector<int> order(4);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
        return a[i] < a[j];
    });
    return {v[order[0]], v[order[1]]};
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        was[i] = false;
    }
    vector<int> v = {1, 2, 3, 4};
    was[1] = true;
    was[2] = true;
    was[3] = true;
    was[4] = true;
    while (v.size() > 2) {
        if (v.size() == 3) {
            for (int i = 1; i <= n; i++) {
                bool ok = true;
                for (int x : v) {
                    if (x == i)
                        ok = false;
                }
                if (ok) {
                    v.push_back(i);
                    break;
                }
            }
        }
        v = solve(v);
        for (int i = 1; i <= n; i++) {
            if (!was[i] && v.size() < 4) {
                was[i] = true;
                v.push_back(i);
            }
        }
    }
    printf("! %d %d\n", v[0], v[1]);
    fflush(stdout);
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}