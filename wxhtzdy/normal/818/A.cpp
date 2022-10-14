#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    int64_t N, K;
    cin >> N >> K;
    int64_t ans = (N / 2) / (K + 1);
    cout << ans << " " << ans * K << " " << N - ans * (K + 1) << '\n';
    return 0;
}