#include <bits/stdc++.h>
using namespace std;

const int maxn = 200 + 10;
int a[maxn], b[maxn];
bool v[maxn];

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n * 2; ++i) cin >> a[i];
    sort(a + 1, a + n * 2 + 1);
    int ind = 1;
    for (int i = n * 2; i > n; --i) b[ind++] = a[i];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i] == b[j]) return cout << "NO" << endl, 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}