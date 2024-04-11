#include <iostream>

using namespace std;

int main() {
    int N, Q, l;
    cin >> N >> Q >> l;

    int a[N + 2];
    for (int i = 1; i <= N; ++i) cin >> a[i];

    bool cutted[N + 2];
    fill(cutted, cutted + N + 2, false);

    for (int i = 1; i <= N; ++i) {
        if (a[i] > l) cutted[i] = true;
    }

    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        if (cutted[i] && !cutted[i + 1]) ++ans;
    }

    for (int q = 0; q < Q; ++q) {
        int t;
        cin >> t;
        if (t == 0) {
            cout << ans << "\n";
        } else {
            int x, d;
            cin >> x >> d;
            if (cutted[x]) continue;
            a[x] += d;
            if (a[x] > l) {
                cutted[x] = true;
                if (cutted[x - 1] && cutted[x + 1]) {
                    --ans;
                } else if (!cutted[x - 1] && !cutted[x + 1]) {
                    ++ans;
                }
            }
        }
    }
    return 0;
}