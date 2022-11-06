#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;
int a[maxn];

int main() {
    int n, k, x; cin >> n >> k >> x;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = n - k; i < n; ++i) a[i] = x;
    cout << accumulate(a, a + n, 0) << endl;
    return 0;
}