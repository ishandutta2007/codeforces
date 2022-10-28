#include <bits/stdc++.h>
using namespace std;

const int A = 10000000 + 1;
const int N = 200000 + 1;
const int K = 20 + 1;

array<int, 2> segments[N][K];
int sieve[A], prv[A];
int a[N];

template <class T>
void set_min(T &a, T b) {
    if (b < a) {
        a = b;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 2; i < A; ++i) {
        if (sieve[i] == 0) {
            for (int j = i; j < A; j += i) {
                sieve[j] = i;
            }
        }
    }

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a[i] = 1;
            while (x > 1) {
                if (a[i] % sieve[x] == 0) {
                    a[i] /= sieve[x];
                } else {
                    a[i] *= sieve[x];
                }
                x /= sieve[x];
            }
            prv[a[i]] = -1;
        }

        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                segments[i][j] = {INT_MAX, INT_MAX};
            }
        }
        segments[0][0] = {1, 0};

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= k; ++j) {
                if (segments[i][j][0] == INT_MAX) {
                    continue;
                }

                if (prv[a[i]] >= i - segments[i][j][1]) {
                    set_min(segments[i + 1][j], {segments[i][j][0] + 1, 1});
                    if (j < k) {
                        set_min(segments[i + 1][j + 1], {segments[i][j][0], segments[i][j][1] + 1});
                    }
                } else {
                    set_min(segments[i + 1][j], {segments[i][j][0], segments[i][j][1] + 1});
                }
            }
            prv[a[i]] = i;
        }

        cout << min_element(segments[n], segments[n] + k + 1)->at(0) << "\n";
    }
}