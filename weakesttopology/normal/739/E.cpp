#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b;
    cin >> n >> a >> b;

    vector<double> p(n), u(n);
    for (auto& x : p) cin >> x;
    for (auto& x : u) cin >> x;

    vector<int> I(n);
    iota(all(I), 0), sort(all(I), [&](int i, int j){ return p[i] > p[j]; });

    auto both = [&](int i){ return 1 - (1 - p[i]) * (1 - u[i]); };

    double ans = 0;
    auto solve = [&](int k){
        vector<int> J(begin(I), begin(I) + k);
        double E = 0;
        for (auto i : J) E += p[i];
        sort(all(J), [&](int i, int j){ return u[i] - p[i] > u[j] - p[j]; });
        priority_queue<double> pq;
        for (int i = k; i < n; ++i) pq.push(u[I[i]]);
        vector<double> suff(k + 1);
        double F = 0;
        int cnt = 0, need = k - a;
        for (int i = k; i >= need; --i) {
            if (i < k) {
                int j = J[i];
                pq.push(both(j) - p[j]);
            }
            while (cnt < b - i) {
                F += pq.top();
                pq.pop();
                ++cnt;
            }
            suff[i] = F;
        }
        F = 0;
        pq = priority_queue<double>();
        for (int i = 0; i < need; ++i) {
            int j = J[i];
            double d = u[j] - p[j];
            F += d;
            pq.push(both(j) - u[j]);
        }
        ans = max(ans, F + E + suff[need]);
        for (int i = need; i < min(k, b); ++i) {
            int j = J[i];
            F += u[j] - p[j];
            pq.push(both(j) - u[j]);
            F += pq.top();
            pq.pop();
            ans = max(ans, F + E + suff[i + 1]);
        }
    };

    for (int k = a; k <= min(n, a + b); ++k) solve(k);
    cout << setprecision(10) << fixed;
    cout << ans << endl;

    exit(0);
}