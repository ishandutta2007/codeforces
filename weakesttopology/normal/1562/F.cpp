#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
pair<vector<int>, vector<int>> sieve(int N) {
    vector<int> lp(N + 1, 0), pr;
    for (int i = 2; i <= N; ++i) {
        if (lp[i] == 0) pr.push_back(lp[i] = i);
        for (auto p : pr) {
            if (p > lp[i] || i * p > N) break;
            lp[i * p] = p;
        }
    }
    return {lp, pr};
}
long long query(int x, int y) {
    assert(x != y);
    cout << "? " << x + 1 << ' ' << y + 1 << endl;
    long long res;
    cin >> res;
    return res;
    //return lcm<long long>(x + 2000, y + 2000);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    const int amax = 2e5;
    auto [lp, pr] = sieve(amax);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<long long> a(N);
        if (1LL * N * N <= 5000) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < i; ++j) {
                    long long x = query(i, j);
                    a[i] = gcd(a[i], x);
                    a[j] = gcd(a[j], x);
                }
            }
            if (N == 3 && a[0] % 2 == 0 && a[1] % 2 == 0 && a[2] % 2 == 0) {
                *max_element(a.begin(), a.end()) /= 2;
            }
        } else {
            uniform_int_distribution<int> unif(0, N - 1);
            auto compute = [&](int i) {
                long long res = 0;
                for (int t = 0; t < 40; ++t) {
                    int j = unif(rng);
                    if (j == i) continue;
                    res = gcd(res, query(i, j));
                }
                return res;
            };
            auto cost = [&](long long x) {
                if (x > amax) return numeric_limits<int>::max();
                int res = 0;
                while (x > 1) {
                    int p = lp[x];
                    res += N / p;
                    while (x % p == 0) x /= p;
                }
                return res;
            };
            long long x;
            int k;
            while (true) {
                k = unif(rng);
                x = compute(k);
                if (cost(x) <= 1000) break;
            }
            long long y = 0;
            int w;
            while (gcd(x, y) != 1) {
                w = unif(rng);
                y = compute(w);
            }
            auto cheap_compute = [&](int i) {
                return i == k ? x : i == w ? y : gcd(query(i, k), query(i, w));
            };
            map<long long, vector<int>> C;
            a[k] = x;
            C[x].push_back(k);
            for (int i = 0; i < N; ++i) {
                if (i == k) continue;
                a[i] = query(i, k) / x;
                C[a[i]].push_back(i);
            }
            while (true) {
                auto [z, I] = *C.begin();
                C.erase(C.begin());
                bool good = true;
                for (auto i : I) {
                    a[i] = cheap_compute(i);
                    C[a[i]].push_back(i);
                    if (a[i] != z) {
                        good = false;
                    }
                }
                if (good) break;
            }
            queue<long long> q;
            for (auto& [z, I] : C) {
                if (I.size() > 1) q.push(z);
            }
            while (not q.empty()) {
                auto z = q.front();
                q.pop();
                if (C[z].size() == 1) continue;
                auto I = C[z];
                C.erase(z);
                for (auto i : I) {
                    a[i] = cheap_compute(i);
                    C[a[i]].push_back(i);
                    if (C[a[i]].size() > 1) {
                        q.push(a[i]);
                    }
                }
            }
            assert((int)C.size() == N);
        }
        cout << '!';
        for (int i = 0; i < N; ++i) {
            cout << ' ' << a[i];
        }
        cout << endl;
    }
    exit(0);
}