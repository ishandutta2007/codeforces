#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int solve_pair(const string& s, const string& t) {
    if (s == t) return 0;
    int l = 0;
    while (s[l] == t[l]) ++l;
    int r = (int)size(s) - 1;
    while (s[r] == t[r]) --r;
    return is_sorted(begin(s) + l, begin(s) + r + 1) || is_sorted(begin(t) + l, begin(t) + r + 1) ? 1 : 2;
}

const int cutoff = 350, wtf = 1337;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int m = -1;
    map<string, vector<string>> C;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        string t = s;
        sort(all(t));
        C[t].push_back(s);
        m = (int)size(s);
    }

    ll ans = 0;
    if (n <= m * cutoff) {
        for (auto& [_, V] : C) {
            int k = (int)size(V);
            for (int i = 0; i < k; ++i) {
                for (int j = i + 1; j < k; ++j) {
                    ans += solve_pair(V[i], V[j]);
                }
            }
        }
    }
    else {
        for (auto& [_, V] : C) {
            sort(all(V));
            ans += 2 * size(V) * (size(V) - 1) / 2;
            // O(n * m * m * log(m))
            for (auto& s : V) {
                for (int l = 0; l + 1 < m; ++l) {
                    for (int r = l + 1; r < m; ++r) {
                        auto t = s;
                        sort(begin(t) + l, begin(t) + r + 1);
                        if (t[l] != s[l] && t[r] != s[r] && binary_search(all(V), t)) --ans;
                    }
                }
            }
        }
    }

    int cnt = 0;
    for (auto& [_, V] : C) {
        int k = (int)size(V);
        ans += 1LL * wtf * k * cnt;
        cnt += k;
    }

    cout << ans << endl;

    exit(0);
}