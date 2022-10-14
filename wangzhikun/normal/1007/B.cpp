#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

template<class T> ostream& operator<<(ostream& os, const V<T> &v) {
    cout << "[";
    for (auto p: v) cout << p << ", ";
    cout << "]";
    return os;
}

const int MN = 100100;
V<int> fac[MN];

void first() {
    for (int i = 1; i < MN; i++) {
        for (int j = i; j < MN; j += i) {
            fac[j].push_back(i);
        }
    }
}

void calc() {
    int a, b, c;
    cin >> a >> b >> c;
    V<int> res_ab, res;
    merge(begin(fac[a]), end(fac[a]), begin(fac[b]), end(fac[b]), back_inserter(res_ab));
    merge(begin(res_ab), end(res_ab), begin(fac[c]), end(fac[c]), back_inserter(res));
    res.erase(unique(begin(res), end(res)), end(res));

    ll cnt[8] = {};
    for (int d: res) {
        int f = 0;
        if (a % d == 0) f += 1;
        if (b % d == 0) f += 2;
        if (c % d == 0) f += 4;
        assert(f);
        cnt[f]++;
    }
    ll ans = 0;
    for (int i = 1; i <= 7; i++) {
        for (int j = i; j <= 7; j++) {
            for (int k = j; k <= 7; k++) {
                if ((i | j | k) != 7) continue;
                if ((i == j || j == k) && (j == 1 || j == 2 || j == 4)) continue;

                ll z = cnt[j];
                if (i == j && j == k) {
                    ans += z * (z+1) * (z+2) / 6;
                    continue;
                }
                if (i == j) {
                    ans += z * (z+1) * cnt[k] / 2;
                    continue;
                }
                if (j == k) {
                    ans += z * (z+1) * cnt[i] / 2;
                    continue;                    
                }
                ans += cnt[i] * cnt[j] * cnt[k];
            }
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20) << fixed;
    first();
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        calc();
    }
    return 0;
}