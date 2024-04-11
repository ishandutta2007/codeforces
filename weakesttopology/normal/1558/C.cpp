#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> a(N);
        bool good = true;
        for (int i = 0; i < N; ++i) {
            cin >> a[i];
            if (a[i] % 2 != (i + 1) % 2) {
                good = false;
            }
        }
        if (not good) {
            cout << "-1\n";
            continue;
        }
        int M = 0;
        vector<int> ps;
        auto apply = [&](int p) {
            assert(p % 2);
            ps.push_back(p);
            reverse(a.begin(), a.begin() + p);
            ++M;
        };
        for (int x = N; x > 1; x -= 2) {
            apply(int(find(a.begin(), a.end(), x) - a.begin()) + 1);
            int i = int(find(a.begin(), a.end(), x - 1) - a.begin());
            if (i > 1) {
                apply(i);
            }
            apply(i + 2);
            apply(3);
            apply(x);
        }
        assert(is_sorted(a.begin(), a.end()));
        cout << M << '\n';
        for (int j = 0; j < M; ++j) {
            cout << ps[j] << "\n "[j + 1 < M];
        }
    }
    exit(0);
}