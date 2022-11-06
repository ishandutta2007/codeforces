#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int n, a, b, p[maxn];

void solve(int aa, int bb) {
    assert(aa * a + bb * b == n);
    int now = 1;
    for (int i = 0; i < aa; ++i) {
        for (int j = 0; j < a - 1; ++j) p[now + j] = now + j + 1;
        p[now + a - 1] = now;
        now += a;
    }
    for (int i = 0; i < bb; ++i) {
        for (int j = 0; j < b - 1; ++j) p[now + j] = now + j + 1;
        p[now + b - 1] = now;
        now += b;
    }
    for (int i = 1; i <= n; ++i) cout << p[i] << ' '; cout << endl;
    exit(0);
}

int main() {
    cin >> n >> a >> b;
    for (int i = 0; ; ++i) {
        if (a * i > n) break;
        int to = n - a * i;
        if (to % b == 0) solve(i, to / b);
    }
    cout << "-1" << endl;
    return 0;
}