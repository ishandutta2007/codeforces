#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios::sync_with_stdio(false);
    cin.tie(0);


    int T;
    cin >> T;

    while(T--) {
        int64_t N;
        cin >> N;
        // sequence 1, 2, 1, 3, 1, 2, 1, 4, 1, 2, 1, 3, 1, 2, 1, 5
        int64_t ans = 0;
        for(int i = 1; (1LL << i - 1) <= N; i++) {
            ans += (N - (1LL << i - 1) + 1 + (1LL << i) - 1)/(1LL << i) * i;
            // cout << i << " " << (N - (1LL << i - 1) + 1 + (1LL << i) - 1) / (1LL << i) * i << "\n";
        }
        cout << ans << "\n";
    }
}