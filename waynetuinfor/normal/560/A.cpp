#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10;
int a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    if (a[0] == 1) return cout << "-1" << endl, 0;
    if (a[0] > 1) return cout << "1" << endl, 0;
    return 0;
}