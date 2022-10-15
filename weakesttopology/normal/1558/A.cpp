#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int A, B;
        cin >> A >> B;
        int N = A + B;
        vector<int> ks;
        for (int t = 0; t < 2; ++t) {
            swap(A, B);
            int A_serves = (N + 1) / 2, B_serves = N / 2;
            for (int x = 0; x <= min(A_serves, A); ++x) {
                int y = B_serves - (A - x);
                if (0 <= y && y + (A_serves - x) == B) {
                    ks.push_back(N - (x + y));
                }
            }
        }
        sort(ks.begin(), ks.end());
        ks.erase(unique(ks.begin(), ks.end()), ks.end());
        int M = (int)ks.size();
        cout << M << '\n';
        for (int j = 0; j < M; ++j) {
            cout << ks[j] << "\n "[j + 1 < M];
        }
    }
    exit(0);
}