#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 10, maxv = 4e6 + 10;
int a[maxn], b[maxn];
bool v[maxv];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i], v[a[i]] = true;
    for (int i = 0; i < n; ++i) cin >> b[i], v[b[i]] = true;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) if (v[a[i] ^ b[j]]) ++ans;
    }
    if (ans & 1) cout << "Koyomi" << endl;
    else cout << "Karen" << endl;
    return 0;
}