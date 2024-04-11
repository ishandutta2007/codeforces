#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 5;
int p[maxn], q[maxn];

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> p[i], p[i] = abs(p[i]);
    for (int i = 1; i <= n; ++i) {
        int a = 0, b = 0;
        for (int j = 1; j <= n; ++j) {
            if (j < i) a += (p[j] < p[i]);
            if (j > i) b += (p[j] < p[i]);
        }
        if (a < b) q[i] = -p[i];
        else q[i] = p[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (j < i && q[j] > q[i]) ++ans;
            else if (j > i && q[j] < q[i]) ++ans;
        }
    }
    cout << (ans >> 1) << endl;
    return 0;
}