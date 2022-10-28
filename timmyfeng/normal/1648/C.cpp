#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;

template <class T>
struct fenwick_tree {
    fenwick_tree(int n = 0) : n(n) {
        tree.resize(n + 1);
    }

    void update(int i, T x) {
        if (i > n) return;
        tree[i] += x;
        update(i + (i & -i), x);
    }

    T operator()(int i) {
        if (i == 0) return T(0);
        return tree[i] + (*this)(i - (i & -i));
    }

    vector<T> tree;
    int n;
};

template <int M>
struct modint {
    modint() : n(0) {}
    template <class T> modint(T n) { n %= M; if (n < 0) n += M; this->n = n; }

    modint & operator+=(const modint &r) { n += r.n; if (n >= M) n -= M; return *this; }
    modint & operator-=(const modint &r) { n -= r.n; if (n < 0) n += M; return *this; }
    modint & operator*=(const modint &r) { n = (int) ((long long) n * r.n % M); return *this; }

    modint & operator--() { if (--n == -1) n = M - 1; return *this; }
    modint & operator++() { if (++n == M) n = 0; return *this; }
    modint operator--(int) { modint t = *this; --*this; return t; }
    modint operator++(int) { modint t = *this; ++*this; return t; }

    modint operator-() const { return 0 - *this; }
    modint operator+() const { return *this; }

    modint pow(long long k = M - 2) const {
        modint f = 1, p = *this;
        while (k > 0) {
            if (k % 2 == 1) f *= p;
            p *= p, k /= 2;
        }
        return f;
    }

    int mod() const { return M; }

    friend modint operator+(modint l, const modint &r) { return l += r; }
    friend modint operator-(modint l, const modint &r) { return l -= r; }
    friend modint operator*(modint l, const modint &r) { return l *= r; }
    
    friend bool operator==(const modint &l, const modint &r) { return l.n == r.n; }
    friend bool operator!=(const modint &l, const modint &r) { return l.n != r.n; }

    friend ostream & operator<<(ostream &out, const modint &r) { return out << r.n; }

    int n;
};

using mint = modint<998244353>;

mint count_smaller_perms(vector<int> a) {
    int n = (int) a.size();

    mint count_suffix_perms = 1, answer = 0;
    fenwick_tree<int> sum(N);
    vector<int> freq(N);

    for (int i = n - 1; i >= 0; --i) {
        ++freq[a[i]], sum.update(a[i], 1);
        count_suffix_perms *= mint(freq[a[i]]).pow();
        answer += count_suffix_perms * sum(a[i] - 1);
        count_suffix_perms *= n - i;
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(true);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;

    multiset<int> s;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        s.insert(x);
    }

    vector<int> t(m);
    for (auto &i : t) cin >> i;

    while (t.size() < s.size()) t.push_back(0);
    if (t.size() > s.size()) t.resize(n), ++t[n - 1];

    vector<int> u;
    while ((int) u.size() < n) {
        if (s.find(t[u.size()]) != s.end()) {
            s.erase(s.find(t[u.size()]));
            u.push_back(t[u.size()]);
        } else if (*s.rbegin() > t[u.size()]) {
            auto it = s.upper_bound(t[u.size()]);
            u.push_back(*it);
            s.erase(it);
            break;
        } else {
            while (*s.rbegin() <= t[u.size()] && !u.empty()) {
                s.insert(u.back());
                u.pop_back();
            }

            if (*s.rbegin() > t[u.size()]) {
                auto it = s.upper_bound(t[u.size()]);
                u.push_back(*it);
                s.erase(it);
                break;
            }

            for (auto i : s) u.push_back(i);
            reverse(u.begin(), u.end());
            cout << count_smaller_perms(u) + 1 << "\n";
            exit(0);
        }
    }

    for (auto i : s) u.push_back(i);

    cout << count_smaller_perms(u) << "\n";
}