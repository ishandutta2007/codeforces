#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int cnt[maxn];

int main() {
    int n; cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; ++i) cin >> d[i];
    for (int i = 0; i < n; ++i) ++cnt[d[i]];
    int x = 0;
    for (int i = 0; i < maxn; ++i) {
        if (cnt[i] == 0) continue;
        x = i;
    }
    for (int i = 1; i < maxn; ++i) {
        if (cnt[i] == 0) continue;
        if (x % i == 0) --cnt[i];
    }
    int y = 0;
    for (int i = 0; i < maxn; ++i) {
        if (cnt[i] == 0) continue;
        y = i;
    }
    cout << x << ' ' << y << endl;
}