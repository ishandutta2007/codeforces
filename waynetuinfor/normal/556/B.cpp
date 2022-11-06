#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10;
int a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int dlt = n - a[0];
    a[0] = 0;
    for (int i = 1; i < n; ++i) {
        if (i & 1) {
            a[i] -= dlt;
            if (a[i] < 0) a[i] += n;
        } else {
            a[i] += dlt;
            if (a[i] >= n) a[i] -= n;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] != i) return cout << "No" << endl, 0;
    }
    cout << "Yes" << endl;
}