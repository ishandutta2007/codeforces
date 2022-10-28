#include <bits/stdc++.h>
using namespace std;

const long long N = 10000000000000000LL;
const int M = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> lcms = {1};
    for (int i = 1; lcms.back() <= N; ++i) {
        lcms.push_back(lcm(lcms.back(), i));
    }

    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        long long ans = 0;
        for (auto i : lcms) {
            ans += n / i;
        }

        cout << ans % M << "\n";
    }
}