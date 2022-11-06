#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int s = 0;
    for (int i = 0; i < n; ++i) cin >> a[i], s += a[i];
    vector<int> vec;
    for (int i = 0; i < n; ++i) {
        if ((s - a[i]) % (n - 1) == 0 && (s - a[i]) / (n - 1) == a[i]) vec.push_back(i + 1);
    }
    cout << vec.size() << endl;
    for (int i : vec) cout << i << ' '; cout << endl;
    return 0;
}