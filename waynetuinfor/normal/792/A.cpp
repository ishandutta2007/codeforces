#include <bits/stdc++.h>
using namespace std;

const int maxn = 200000 + 5;
int n, a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    int Min = INT_MAX, cnt = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] - a[i - 1] < Min) {
            Min = a[i] - a[i - 1];
            cnt = 1;
        } else if (a[i] - a[i - 1] == Min) ++cnt;
    }
    cout << Min << ' ' << cnt << '\n';
    return 0;
}