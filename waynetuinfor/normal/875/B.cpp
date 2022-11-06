#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10;
bool v[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    cout << "1 ";
    int now = n;
    for (int i = 1; i <= n; ++i) {
        int p; cin >> p; v[p] = true;
        while (now > 0 && v[now]) --now;
        // cout << now << endl;
        cout << now - n + i + 1 << ' ';
        // cout << n - now + (n - i - 1) << ' ';
        // cout << n -  << ' ';
    }
    return 0;
}