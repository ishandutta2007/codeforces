#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <set>
#include <map>
#include <array>
#include <queue>
#include <unordered_map>
#include <cstring>
#include <iomanip>
#include <chrono>
 
using namespace std;
 
int main() {
    int n, p; cin >> n >> p;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<long long> f(p + 1);
    f[0] = 1LL;
    f[1] = 2LL;
    long long MOD = 1e9 + 7;
    for (int i = 2; i <= p; i++) {
        f[i] = (f[i - 1] + f[i - 2] + 1) % MOD;
    }
    sort(a.begin(), a.end());
    long long ans = 0LL;
    set<int> in;
    for (int i = 0; i < n; i++) {
        bool unique = true;
        int tmp = a[i];
        while (tmp > 0) {
            if (in.count(tmp)) {
                unique = false;
                break;
            }
            if (tmp % 4 == 2) {
                break;
            }
            if (tmp % 2) {
                tmp /= 2;
            } else {
                tmp /= 4;
            }
        }
        if (!unique) continue;
        in.insert(a[i]);
        int numDig = 0;
        while (a[i]) {
            ++numDig;
            a[i] /= 2;
        }
        int make = p - numDig;
        if (make < 0) continue;
        ans += f[make];
        ans %= MOD;
    }
    cout << ans << "\n";
}