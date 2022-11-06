#include <bits/stdc++.h>
using namespace std;

int Solve() {
    long long n; int m; 
    scanf("%lld%d", &n, &m);
    vector<int> cnt(31), nd(31);
    long long sum = 0;
    for (int i = 0; i < m; ++i) {
        int x; scanf("%d", &x);
        sum += x;
        cnt[__builtin_ctz(x)]++;
    }
    if (sum < n) return -1;
    for (int i = 0; i < 60; ++i) {
        if (n >> i & 1) {
            if (i <= 30) nd[i]++;
            else nd[30] += (1 << (i - 30));
        }
    }
    int res = 0;
    for (int i = 0; i < 30; ++i) {
        if (nd[i] == 1 && cnt[i] == 0) {
            for (int j = i + 1; j <= 30; ++j) {
                if (cnt[j] > 0) {
                    res += j - i;
                    cnt[j]--;
                    for (int k = j - 1; k > i; --k) cnt[k]++;
                    cnt[i] += 2;
                    break;
                }
            }
        }
        if (nd[i] == 1 && cnt[i] == 0) return -1;
        if (nd[i] == 1) cnt[i]--; 
        cnt[i + 1] += cnt[i] / 2;
    }
    if (cnt[30] < nd[30]) return -1;
    return res;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) printf("%d\n", Solve());
}