#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;
        vector<int> freq(64);
        long long sum = 0;
        for (int i = 0; i < m; i++) {
            long long a;
            cin >> a;
            sum += a;
            int n = -1;
            while (a) {
                n++;
                a /= 2;
            }
            freq[n]++;
        }
        if (sum < n) {
            cout << -1 << '\n';
            continue;
        }
        int sol = 0;
        for (int i = 0; i < 63; i++) {
            if (n & (1LL << i)) {
                if (freq[i]) {
                    freq[i]--;
                } else {
                    int j = i + 1;
                    while (freq[j] == 0) {
                        j++;
                    }
                    freq[j]--;
                    for ( ; j > i; j--) {
                        freq[j - 1]++;
                        sol++;
                    }
                }
            }
            freq[i + 1] += freq[i] / 2;
        }
        cout << sol << '\n';
    }
}