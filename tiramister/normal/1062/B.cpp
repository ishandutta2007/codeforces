#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

vector<pair<int, int>> factor(int n) {
    vector<pair<int, int>> ret;

    for (int p = 2; p * p <= n; ++p) {
        if (n % p > 0) continue;
        int cnt = 0;
        while (n % p == 0) {
            n /= p;
            ++cnt;
        }
        ret.push_back(make_pair(p, cnt));
    }

    if (n > 1) ret.push_back(make_pair(n, 1));
    return ret;
}

bool ispow2(int n) {
    while (n % 2 == 0) n /= 2;
    return n == 1;
}

int exp2(int n) {
    for (int i = 0; i < 25; ++i) {
        if (n <= (1 << i)) return i;
    }
    return 0;
}

int main() {
    int N;
    cin >> N;

    if (N == 1) {
        cout << 1 << " " << 0 << endl;
        return 0;
    }

    auto fact = factor(N);
    int ans = accumulate(fact.begin(), fact.end(), 1, [](int init, pair<int, int> p) { return init * p.first; });

    int cnt = 0, e = 0;
    for (auto p : fact) e = max(e, p.second);

    // 21
    if (!ispow2(e) || !all_of(fact.begin(), fact.end(), [&](pair<int, int> p) { return p.second == e; })) ++cnt;
    cnt += exp2(e);

    cout << ans << " " << cnt << endl;
    return 0;
}