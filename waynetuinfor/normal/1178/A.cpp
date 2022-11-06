#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
int a[maxn];

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int sum = a[0];
    vector<int> v = {0};
    for (int i = 1; i < n; ++i) {
        if (a[0] >= a[i] * 2) sum += a[i], v.push_back(i);
    }
    int s = accumulate(a, a + n, 0);
    if (sum * 2 > s) {
        cout << v.size() << endl;
        for (int i : v) cout << i + 1 << ' ';
        cout << endl;
    } else {
        cout << 0 << endl;
    }
}