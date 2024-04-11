#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int cnt[101], sum = 0, kind = 0;
    fill(cnt, cnt + 101, 0);
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        if (cnt[a] == 0) ++kind;
        ++cnt[a];
        sum += a;
    }

    if (kind <= 2) {
        cout << N << endl;
        return 0;
    }

    int pat[N + 1][sum + 1];
    fill(pat[0], pat[N + 1], 0);
    pat[0][0] = 1;

    for (int w = 1; w <= 100; ++w) {
        for (int n = N; n >= 0; --n) {
            for (int sw = sum; sw >= 0; --sw) {
                for (int k = cnt[w]; k >= 1; --k) {
                    // wk
                    if (n + k > N || sw + w * k > sum) continue;
                    pat[n + k][sw + w * k] += pat[n][sw];
                    pat[n + k][sw + w * k] = min(2, pat[n + k][sw + w * k]);
                }
            }
        }
    }

    for (int k = N; k >= 0; --k) {
        for (int w = 1; w <= 100 && w * k <= sum; ++w) {
            // wk
            if (cnt[w] >= k && pat[k][w * k] == 1) {
                cout << k << endl;
                return 0;
            }
        }
    }
    return 0;
}