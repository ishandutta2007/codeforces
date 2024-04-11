#include <bits/stdc++.h>
using namespace std;

const int N = 50001;

int max_taken[N][3];

void set_max(int &a, int b) {
    if (b > a) a = b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &i : a) cin >> i;

        int x;
        cin >> x;
        for (auto &i : a) i -= x;

        memset(max_taken, 0, sizeof max_taken);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 3; ++j) {
                bool last2 = (j > 0 && i >= 1 && a[i] + a[i - 1] < 0);
                bool last3 = (j > 1 && i >= 2 && a[i] + a[i - 1] + a[i - 2] < 0);

                if (!last2 && !last3) {
                    set_max(max_taken[i + 1][min(2, j + 1)], max_taken[i][j] + 1);
                }
                set_max(max_taken[i + 1][0], max_taken[i][j]);
            }
        }

        cout << *max_element(max_taken[n], max_taken[n] + 3) << "\n";
    }
}