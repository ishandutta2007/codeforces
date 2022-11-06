#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    map<int, int> pos;
    vector<int> b;
    for (int i = 0; i < n; ++i) b.push_back(a[i]), pos[a[i]] = i;
    sort(b.begin(), b.end());
    for (int i = 0; i < n; ++i) if (a[i] != b[i]) {
        int p = pos[b[i]];
        reverse(a + i, a + p + 1);
        for (int j = 0; j < n; ++j) if (a[j] != b[j]) return cout << "no" << endl, 0;
        cout << "yes" << endl;
        cout << i + 1 << ' ' << p + 1 << endl;
        return 0;
    }
    cout << "yes" << endl;
    cout << "1 1" << endl;
    return 0;
}