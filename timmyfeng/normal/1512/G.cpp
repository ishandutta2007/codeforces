#include <bits/stdc++.h>
using namespace std;

const int N = 10000001;

int sum[N], ans[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i < N; ++i) {
        for (int j = i; j < N; j += i) {
            sum[j] += i;
        }
    }

    for (int i = N - 1; i > 0; --i) {
        if (sum[i] < N) {
            ans[sum[i]] = i;
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int c;
        cin >> c;

        cout << (ans[c] == 0 ? -1 : ans[c]) << "\n";
    }
}