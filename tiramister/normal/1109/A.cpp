#include <iostream>
#include <map>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    int x[N + 1];
    x[0] = 0;
    for (int i = 1; i <= N; ++i) {
        int a;
        cin >> a;
        x[i] = x[i - 1] ^ a;
    }

    map<int, ll> cnt[2];
    for (int i = 0; i <= N; ++i) {
        if (!cnt[i % 2].count(x[i])) cnt[i % 2][x[i]] = 0;
        ++cnt[i % 2][x[i]];
    }

    ll ans = 0;
    for (int i = 0; i < 2; ++i) {
        for (auto p : cnt[i]) {
            ans += p.second * (p.second - 1) / 2;
        }
    }

    cout << ans << endl;
    return 0;
}