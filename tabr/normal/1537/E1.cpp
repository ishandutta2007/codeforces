#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

vector<int> suffix_array(const vector<int> &s, int upper) {
    int n = (int) s.size();
    if (n == 0) {
        return {};
    }
    if (n == 1) {
        return {0};
    }
    if (n == 2) {
        if (s[0] < s[1]) {
            return {0, 1};
        } else {
            return {1, 0};
        }
    }
    vector<int> sa(n);
    vector<bool> ls(n);
    for (int i = n - 2; i >= 0; i--) {
        ls[i] = (s[i] == s[i + 1]) ? ls[i + 1] : (s[i] < s[i + 1]);
    }
    vector<int> sum_l(upper + 1), sum_s(upper + 1);
    for (int i = 0; i < n; i++) {
        if (!ls[i]) {
            sum_s[s[i]]++;
        } else {
            sum_l[s[i] + 1]++;
        }
    }
    for (int i = 0; i <= upper; i++) {
        sum_s[i] += sum_l[i];
        if (i < upper) {
            sum_l[i + 1] += sum_s[i];
        }
    }
    function<void(vector<int>)> induce = [&](const vector<int> &lms) {
        fill(sa.begin(), sa.end(), -1);
        vector<int> buf(upper + 1);
        copy(sum_s.begin(), sum_s.end(), buf.begin());
        for (auto d : lms) {
            if (d == n) {
                continue;
            }
            sa[buf[s[d]]++] = d;
        }
        copy(sum_l.begin(), sum_l.end(), buf.begin());
        sa[buf[s[n - 1]]++] = n - 1;
        for (int i = 0; i < n; i++) {
            int v = sa[i];
            if (v >= 1 && !ls[v - 1]) {
                sa[buf[s[v - 1]]++] = v - 1;
            }
        }
        copy(sum_l.begin(), sum_l.end(), buf.begin());
        for (int i = n - 1; i >= 0; i--) {
            int v = sa[i];
            if (v >= 1 && ls[v - 1]) {
                sa[--buf[s[v - 1] + 1]] = v - 1;
            }
        }
    };
    vector<int> lms_map(n + 1, -1);
    int m = 0;
    for (int i = 1; i < n; i++) {
        if (!ls[i - 1] && ls[i]) {
            lms_map[i] = m++;
        }
    }
    vector<int> lms;
    lms.reserve(m);
    for (int i = 1; i < n; i++) {
        if (!ls[i - 1] && ls[i]) {
            lms.emplace_back(i);
        }
    }
    induce(lms);
    if (m) {
        vector<int> sorted_lms;
        sorted_lms.reserve(m);
        for (int v : sa) {
            if (lms_map[v] != -1) {
                sorted_lms.emplace_back(v);
            }
        }
        vector<int> rec_s(m);
        int rec_upper = 0;
        rec_s[lms_map[sorted_lms[0]]] = 0;
        for (int i = 1; i < m; i++) {
            int l = sorted_lms[i - 1], r = sorted_lms[i];
            int end_l = (lms_map[l] + 1 < m) ? lms[lms_map[l] + 1] : n;
            int end_r = (lms_map[r] + 1 < m) ? lms[lms_map[r] + 1] : n;
            bool same = true;
            if (end_l - l != end_r - r) {
                same = false;
            } else {
                while (l < end_l) {
                    if (s[l] != s[r]) {
                        break;
                    }
                    l++;
                    r++;
                }
                if (l == n || s[l] != s[r]) {
                    same = false;
                }
            }
            if (!same) {
                rec_upper++;
            }
            rec_s[lms_map[sorted_lms[i]]] = rec_upper;
        }
        vector<int> rec_sa = suffix_array(rec_s, rec_upper);
        for (int i = 0; i < m; i++) {
            sorted_lms[i] = lms[rec_sa[i]];
        }
        induce(sorted_lms);
    }
    return sa;
}

template <typename T>
vector<int> suffix_array(const vector<T> &s) {
    int n = (int) s.size();
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int l, int r) { return s[l] < s[r]; });
    vector<int> s2(n);
    int now = 0;
    for (int i = 0; i < n; i++) {
        if (i && s[idx[i - 1]] != s[idx[i]]) {
            now++;
        }
        s2[idx[i]] = now;
    }
    return suffix_array(s2, now);
}

vector<int> suffix_array(const string &s) {
    int n = (int) s.size();
    vector<int> s2(n);
    for (int i = 0; i < n; i++) {
        s2[i] = s[i];
    }
    return suffix_array(s2, 255);
}

template <typename T>
vector<int> lcp_array(const vector<T> &s, const vector<int> &sa) {
    int n = (int) s.size();
    vector<int> rnk(n);
    for (int i = 0; i < n; i++) {
        rnk[sa[i]] = i;
    }
    vector<int> lcp(n - 1);
    int h = 0;
    for (int i = 0; i < n; i++) {
        if (h > 0) {
            h--;
        }
        if (rnk[i] == 0) {
            continue;
        }
        for (int j = sa[rnk[i] - 1]; j + h < n && i + h < n; h++) {
            if (s[j + h] != s[i + h]) {
                break;
            }
        }
        lcp[rnk[i] - 1] = h;
    }
    return lcp;
}

vector<int> lcp_array(const string &s, const vector<int> &sa) {
    int n = (int) s.size();
    vector<int> s2(n);
    for (int i = 0; i < n; i++) {
        s2[i] = s[i];
    }
    return lcp_array(s2, sa);
}

template <typename T>
struct sparse {
    int n, h;
    vector<vector<T>> table;
    T func(T x, T y) {
        return min(x, y);
    }

    sparse(vector<T> v) {
        n = (int) v.size();
        h = 32 - __builtin_clz(n);
        table.resize(h);
        table[0] = v;
        for (int j = 1; j < h; j++) {
            table[j].resize(n - (1 << j) + 1);
            for (int i = 0; i <= n - (1 << j); i++) {
                table[j][i] = func(table[j - 1][i], table[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    T get(int from, int to) {  // [from, to]
        int k = 32 - __builtin_clz(to - from + 1) - 1;
        return func(table[k][from], table[k][to - (1 << k) + 1]);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string t = s;
    vector<int> sa = suffix_array(s);
    vector<int> lcp = lcp_array(s, sa);
    sparse<int> st(lcp);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[sa[i]] = i;
    }
    debug(sa, lcp, a);
    for (int i = n - 1; i >= 1; i--) {
        int j = (int) t.size();
        if (a[i] > a[0]) {
            t.resize(i);
        } else if (st.get(a[i], a[0] - 1) == j - i && a[j - i] < a[0]) {
            t.resize(i);
        }
    }
    for (int i = 0; i < k; i++) {
        cout << t[i % t.size()];
    }
    cout << '\n';
    return 0;
}