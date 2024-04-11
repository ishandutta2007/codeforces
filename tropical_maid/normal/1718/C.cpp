#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, q;
int A[200001];
bool P[200001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    fill(P, P + 200001, true);
    for (int i = 2; i <= 200000; ++i) {
        if (!P[i]) continue;
        for (int j = i * 2; j <= 200000; j += i) {
            P[j] = false;
        }
    }
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> q;
        for (int i = 1; i <= n; ++i) cin >> A[i];
        vector<int> p;
        vector<vector<ll>> S;
        for (int i = 2; i <= n; ++i) {
            if (P[i] && n % i == 0) p.push_back(i);
        }
        int m = p.size();
        multiset<ll> ans;
        for (int i = 0; i < m; ++i) {
            S.emplace_back(n / p[i], 0);
            for (int j = 1; j <= n; ++j) {
                S[i][j % int(S[i].size())] += A[j];
            }
            for (ll j : S[i]) ans.insert(j * ll(S[i].size()));
        }
        printf("%lld\n", *ans.rbegin());
        for (int i = 0; i < q; ++i) {
            int pos, x;
            cin >> pos >> x;
            for (int j = 0; j < m; ++j) {
                ans.erase(ans.find(S[j][pos % int(S[j].size())] * ll(S[j].size())));
                S[j][pos % int(S[j].size())] += x - A[pos];
                ans.insert(S[j][pos % int(S[j].size())] * ll(S[j].size()));
            }
            A[pos] = x;
            printf("%lld\n", *ans.rbegin());
        }
    }
}