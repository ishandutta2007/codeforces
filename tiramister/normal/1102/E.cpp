#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;

const ll MOD = 998244353;

int main() {
    int N;
    cin >> N;

    map<int, vector<int>> index;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        index[a].push_back(i);
    }


    int imos[N];
    fill(imos, imos + N, 0);
    for (auto p : index) {
        auto v = p.second;
        ++imos[v.front()];
        --imos[v.back()];
    }

    for (int i = 1; i < N; ++i) {
        imos[i] += imos[i - 1];
    }

    ll ans = 1;
    for (int i = 0; i < N - 1; ++i) {
        if (imos[i] == 0) {
            ans *= 2;
            ans %= MOD;
        }
    }

    cout << ans << endl;
    return 0;
}