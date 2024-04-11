#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<int> cnt(2);
        for(char c : s) cnt[c - '0'] += 1;
        if(1ll * cnt[1] * m % n) {
            cout << -1 << '\n';
            continue;
        }
        int x = 1ll * cnt[1] * m / n, y = m - x;
        vector<int> sum(n + 1);
        for(int i = 0; i < n; ++i) sum[i + 1] = sum[i] + (s[i] == '1');

        int l = -1, r = -1;
        for(int i = 0; i + m <= n; ++i) {
            if(sum[i + m] - sum[i] == x) {
                l = i, r = l + m - 1;
                break;
            }
        }
        if(l != -1) {
            cout << 1 << '\n';
            cout << l + 1 << ' ' << r + 1 << '\n';
            continue;
        }
        for(int i = 0; i + (n - m) <= n; ++i) {
            if(sum[i + (n - m)] - sum[i] == cnt[1] - x) {
                l = i, r = l + n - m;
                break;
            }
        }
        assert(l != -1);
        cout << 2 << '\n';
        cout << 1 << ' ' << l << '\n';
        cout << r + 1 << ' ' << n << '\n';
    }
}