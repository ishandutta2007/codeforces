#include <bits/stdc++.h>
using namespace std;

namespace sfx {

template <class String = string, size_t Alpha = 256>
vector<int> SuffixArray(const String &s) {
    size_t n = s.size() + 1;
    vector<int> str(s.begin(), s.end());
    str.resize(n * 2, 0);
    vector<int> sa(n * 2), c(max(Alpha, n) * 2), x(max(Alpha, n)), p(n), q(n * 2);
    vector<bool> t(n * 2);

    auto Pre = [&](auto sa, auto c, size_t n, size_t z) {
        fill(sa, sa + n, 0);
        copy(c, c + z, x.begin());
    };

    auto Induce = [&](auto sa, auto c, auto s, auto t, size_t n, size_t z) {
        copy(c, c + (z - 1), next(x.begin()));
        for (size_t i = 0; i < n; ++i) if (sa[i] && !t[sa[i] - 1]) sa[x[s[sa[i] - 1]]++] = sa[i] - 1;
        copy(c, c + z, x.begin());
        for (int i = int(n) - 1; i >= 0; --i) if (sa[i] && t[sa[i] - 1]) sa[--x[s[sa[i] - 1]]] = sa[i] - 1;
    };

    auto SAIS = [&](auto self, auto s, auto sa, auto p, auto q, 
            auto t, auto c, size_t n, size_t z) {
        bool uniq = t[n - 1] = true;
        size_t nn = 0;
        int nmxz = -1, last = -1;
        auto nsa = sa + n;
        auto ns = s + n;
        fill(c, c + z, 0);
        for (size_t i = 0; i < n; ++i) uniq &= ++c[s[i]] < 2;
        for (size_t i = 0; i + 1 < z; ++i) c[i + 1] += c[i];
        if (uniq) {
            for (size_t i = 0; i < n; ++i) sa[--c[s[i]]] = i;
            return;
        }
        for (int i = int(n) - 2; i >= 0; --i) t[i] = (s[i] == s[i + 1] ? t[i + 1] : s[i] < s[i + 1]);
        Pre(sa, c, n, z);
        for (size_t i = 1; i + 1 <= n; ++i) if (t[i] && !t[i - 1]) sa[--x[s[i]]] = p[q[i] = nn++] = i;
        Induce(sa, c, s, t, n, z);
        for (size_t i = 0; i < n; ++i) if (sa[i] && t[sa[i]] && !t[sa[i] - 1]) {
            bool neq = last < 0 || !equal(s + sa[i], s + sa[i] + (p[q[sa[i]] + 1] - sa[i]), s + last);
            ns[q[last = sa[i]]] = nmxz += neq;
        }
        self(self, ns, nsa, p + nn, q + n, t + n, c + z, nn, nmxz + 1);
        Pre(sa, c, n, z);
        for (int i = int(nn) - 1; i >= 0; --i) sa[--x[s[p[nsa[i]]]]] = p[nsa[i]];
        Induce(sa, c, s, t, n, z);
    };

    SAIS(SAIS, str.begin(), sa.begin(), p.begin(), q.begin(), 
            t.begin(), c.begin(), n, Alpha);
    for (size_t i = 0; i < s.size(); ++i) sa[i] = sa[i + 1];
    sa.resize(s.size());
    return sa;
}

vector<int> BuildRank(const vector<int> &sa) {
    vector<int> rev(sa.size());
    for (size_t i = 0; i < sa.size(); ++i) rev[sa[i]] = i;
    return rev;
}

template <class String = string>
vector<int> BuildPrefix(const String &s, const vector<int> &sa) {
    size_t n = s.size();
    auto rev = BuildRank(sa);
    vector<int> lcp(n);
    for (size_t i = 0, idx = 0; i < n; ++i) {
        if (!rev[i]) {
            idx = 0;
            continue;
        }
        while (i + idx < n && s[i + idx] == s[sa[rev[i] - 1] + idx]) idx++;
        lcp[rev[i]] = idx;
        if (idx > 0) idx--;
    }
    return lcp;
}

}  // namespace sfx

int main() {
    int n, m; int64_t k; 
    cin >> n >> m >> k;
    string s; 
    cin >> s;
    string t = "";
    vector<vector<int>> pos(n, vector<int>(n, -1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i; ++j) pos[j][n - i - 1] = t.size() + j;
        t += s.substr(0, n - i);
        t += "#";
    }
    vector<int> sa = sfx::SuffixArray(t);
    vector<int> rnk = sfx::BuildRank(sa);
    vector<int> use;
    for (int i = 0; i < sa.size(); ++i) {
        if (t[sa[i]] != '#') use.push_back(sa[i]);
    }

    auto Count = [&](int p) {
        constexpr int64_t kInf = 2'000'000'000'000'000'000;
        vector<vector<int64_t>> dp(n + 1, vector<int64_t>(m + 1, 0));
        vector<vector<int64_t>> sum(n + 1, vector<int64_t>(m + 1, 0));
        dp[n][0] = 1;
        sum[n][0] = 1;
        for (int i = n - 1; i >= 0; --i) {
            int nxt = -1;
            for (int k = i + 1; k <= n; ++k) {
                if (rnk[pos[i][k - 1]] >= rnk[p]) {
                    nxt = k;
                    break;
                }
            }
            if (nxt != -1) {
                for (int j = 1; j <= m; ++j) dp[i][j] = sum[nxt][j - 1];
            }
            for (int j = 0; j <= m; ++j) {
                sum[i][j] = dp[i][j] + sum[i + 1][j];
                if (sum[i][j] > kInf) sum[i][j] = kInf;
            }
        }
        return dp[0][m];
    };

    int ans = use.size();
    for (int d = 20; d >= 0; --d) {
        if (ans - (1 << d) < 0) continue;
        if (Count(use[ans - (1 << d)]) < k) ans -= (1 << d);
    }
    ans--;
    for (int i = use[ans]; t[i] != '#'; i++) cout << t[i];
    cout << endl;
    return 0;
}