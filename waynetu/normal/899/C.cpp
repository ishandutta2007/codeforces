#include <bits/stdc++.h>
using namespace std;

const int maxn = 6e4 + 10;
const long long inf = (1ll << 40);
int n;
vector<int> vans;

bool check(long long k) {
    // cout << "check k = " << k << endl;
    long long t = n * 1ll * (n + 1) / 2;
    long long a = 0;
    int now = n;
    vector<int> vec;
    while (a < 1.0 * t / 2 && now >= 1) {
        if (a + now > 1.0 * (t + k) / 2) --now;
        else a += now, vec.push_back(now), --now;
    }
    if (a <= 1.0 * (t + k) / 2 && a >= 1.0 * t / 2) vans = vec;
    // cout << "a = " << a << endl;
    return a <= 1.0 * (t + k) / 2 && a >= 1.0 * t / 2;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    // check(0);
    int d = 41;
    long long ans = inf;
    while (d--) if (ans - (1ll << d) >= 0) if (check(ans - (1ll << d))) ans -= (1ll << d);
    cout << ans << endl;
    cout << vans.size() << ' ';
    for (int i : vans) cout << i << ' ';
    cout << endl;
}