#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }

    vector<int> b(n);
    int sol = 0;
    for (int k = 0; k < 25; ++k) {
        int bit = 1 << k;
        for (int i = 0; i < n; ++i) {
            b[i] = a[i] & (bit * 2 - 1);
        }
        sort(b.begin(), b.end());

        long long ct = 0;
        int j = n;
        for (int i = 0; i < n; ++i) {
            if (j <= i) {
                ++j;
            }
            while (j - 1 > i && b[i] + b[j - 1] >= bit * 3) {
                --j;
            }
            ct += n - j;
        }

        j = n;
        int l = n;
        for (int i = 0; i < n; ++i) {
            if (j <= i) {
                ++j;
            }
            if (l <= i) {
                ++l;
            }
            while (j - 1 > i && b[i] + b[j - 1] >= bit) {
                --j;
            }
            while (l - 1 > i && b[i] + b[l - 1] >= bit * 2) {
                --l;
            }
            ct += l - j;
        }
        if (ct % 2) {
            sol |= 1 << k;
        }
    }
    cout << sol << '\n';
}