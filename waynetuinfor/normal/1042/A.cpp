#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
int a[maxn];

int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int mans = *max_element(a, a + n) + m;
    while (m) {
        int j = 0;
        for (int i = 1; i < n; ++i) if (a[i] < a[j]) j = i;
        a[j]++;
        m--;
    }
    cout << *max_element(a, a + n) << ' ' << mans << endl;
}