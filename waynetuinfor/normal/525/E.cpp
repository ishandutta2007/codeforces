#include <bits/stdc++.h>
using namespace std;

const int maxn = 30;
int a[maxn], n, k;
long long s, frac[maxn];
map<long long, int> cnt[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k >> s;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    frac[1] = 1LL;
    for (int i = 2; i < maxn; ++i) frac[i] = frac[i - 1] * (long long)i;
    int h = n / 2;
    if  (n == 25) h += 2;
    for (int mask = 0; mask < pow(3, h); ++mask) {
        long long sum = 0;
        int tak = 0, tmp = mask;
        bool stop = false;
        for (int i = 0; i < h && !stop; ++i) {
            int bit = tmp % 3;
            if (bit == 2) {
                if (a[i] > 18) stop = true;
                if (!stop) sum += frac[a[i]];
                ++tak;
            } else if (bit == 1) {
                sum += a[i];
            }
            tmp /= 3;
        }
        if (tak > k) continue;
        if (!stop) ++cnt[tak][sum];
    }
    long long ans = 0;
    int m = n - h;
    for (int mask = 0; mask < pow(3, m); ++mask) {
        long long sum = 0;
        int tak = 0, tmp = mask;
        bool stop = false;
        for (int i = h; i < n && !stop; ++i) {
            int bit = tmp % 3;
            if (bit == 2) {
                if (a[i] > 18) stop = true;
                if (!stop) sum += frac[a[i]];
                ++tak;
            } else if (bit == 1) {
                sum += a[i];
            }
            tmp /= 3;
        }
        if (stop) continue;
        if (s < sum) continue;
        if (tak > k) continue;
        for (int i = k; ; --i) {
            if (i - tak < 0) break;
            ans += cnt[i - tak][s - sum];
        }
    }
    cout << ans << endl;
    return 0;
}