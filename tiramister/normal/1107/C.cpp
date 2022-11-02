#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;

    int a[N];
    for (int i = 0; i < N; ++i) cin >> a[i];

    string S;
    cin >> S;
    S.push_back('$');

    vector<ll> damage;
    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        damage.push_back(a[i]);
        if (S[i] != S[i + 1]) {
            sort(damage.rbegin(), damage.rend());
            ans += accumulate(damage.begin(), damage.begin() + min((int)damage.size(), K), 0LL);
            damage.clear();
        }
    }

    cout << ans << endl;
    return 0;
}