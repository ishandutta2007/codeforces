#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

template <typename T, typename U>
T mypow(T b, U n) {
    if (n == 0) return 1;
    if (n == 1) return b /* % MOD */;
    if (n % 2 == 0) {
        return mypow(b * b /* % MOD */, n / 2);
    } else {
        return mypow(b, n - 1) * b /* % MOD */;
    }
}

int main() {
    int N;
    cin >> N;

    map<int, int> cnt;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        if (cnt.find(a) == cnt.end()) cnt[a] = 0;
        ++cnt[a];
    }

    vector<int> num;
    for (auto p : cnt) {
        num.push_back(p.second);
    }
    sort(num.rbegin(), num.rend());

    int K = num[0];
    int ans = K;
    for (int i = 1; i < num.size(); ++i) {
        K = min(K / 2, num[i]);
        if (K == 0) break;
        ans = max(ans, K * (mypow(2, i + 1) - 1));
    }

    cout << ans << endl;
    return 0;
}