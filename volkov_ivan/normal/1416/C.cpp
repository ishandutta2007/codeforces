#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 7, K = 31;
int a[N];
unordered_map <int, pair <int, int>> cnt[K];
pair <long long, long long> pay[K];

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(pay, 0, sizeof(pay)); 
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = n - 1; i >= 0; i--) {
        int mask = 0;
        for (int j = K - 1; j > 0; j--) {
            int bit = a[i] & (1 << j);
            mask |= bit;
            int nxtbit = a[i] & (1 << (j - 1));
            if (bit != 0) bit = 1;
            if (nxtbit == 0) {
                int other = cnt[j][mask].second;
                pay[j - 1].second += other;
                //if (other != 0) cout << i << ' ' << j - 1 << "1" << endl;
            } else {
                int other = cnt[j][mask].first;
                pay[j - 1].first += other;
                //if (other != 0) cout << i << ' ' << j - 1 << "0" << endl;
            }
            if (nxtbit != 0) cnt[j][mask].second++;
            else cnt[j][mask].first++;
        }
    }
    long long res = 0, ans = 0;
    for (int j = K - 1; j >= 0; j--) {
        res += min(pay[j].first, pay[j].second);
        //cout << pay[j].first << ' ' << pay[j].second << endl;
        if (pay[j].second < pay[j].first) ans |= (1 << j);
    }
    cout << res << ' ' << ans << endl;
    return 0;
}