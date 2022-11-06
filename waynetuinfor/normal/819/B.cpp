#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int diff[maxn << 1], p[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        if (p[i] > i) ++diff[p[i] - i];
        else ++cnt;
    }
    long long cur = 0;
    for (int i = 1; i <= n; ++i) cur += abs(p[i] - i);
    long long ans = cur;
    int tans = 0;
    for (int i = 1; i < n; ++i) {
        int ind = (n - i + 1) % n;
        if (ind == 0) ind = n;
        --cnt;
        cur -= abs(p[ind] - n); cur += abs(p[ind] - 1);
        if (p[ind] > n + i - 1) --diff[p[ind] - (n + i - 1)];
        ++diff[p[ind] - 1 + i];
        cur += cnt; cur -= (n - cnt - 1); 
        cnt += diff[i]; 
        if (cur < ans) {
            ans = cur;
            tans = i;
        }
    }
    cout << ans << ' ' << tans << endl;
    return 0;
}