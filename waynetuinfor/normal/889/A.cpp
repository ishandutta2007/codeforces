#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
bool v[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n; 
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int t; cin >> t;
        if (!v[t]) v[t] = true;
        else ++ans;
    }
    cout << ++ans << endl;
    return 0;
}