#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <class c> struct rge { c bg, ed; };
template <class c> rge<c> range(c i, c j) { return rge<c>{i, j}; }
template <class c> auto dud(c *x) -> decltype(cerr << *x, 0);
template <class c> char dud(...);
#define var(...) #__VA_ARGS__" = " << (__VA_ARGS__) << " "
struct debug {
~debug() { cerr << endl; }
template <class c> typename \
enable_if <sizeof dud<c>(0) != 1, debug&>::type operator<<(c i) { cerr << boolalpha << i; return *this; }
template <class c> typename \
enable_if <sizeof dud<c>(0) == 1, debug&>::type operator<<(c i) { return *this << range(begin(i), end(i)); }
template <class c, class b> debug &operator<<(pair<c, b> p) { return *this << "(" << p.first << ", " << p.second << ")"; }
template <class c> debug &operator<<(rge<c> d) { *this << "[ "; for (auto it = d.bg; it != d.ed; ++it) *this << ", " + 2 * (it == d.bg) << *it; return *this << " ]"; }
};

const int mod = 1e9 + 7, maxn = 1000 + 10, maxk = 10;

int add(int a, int b) { return (a += b) >= mod ? a - mod : a; }
int sub(int a, int b) { return (a -= b) < 0 ? a + mod : a; }
int mul(int a, int b) { return a * 1ll * b % mod; }

int fpow(int a, int n) {
    int ret = 1;
    for (; n; n >>= 1, a = mul(a, a)) if (n & 1) ret = mul(ret, a);
    return ret;
}

vector<int> graf[maxk];
bitset<maxk> v;
int n, k;

void f(int now) {
    v[now] = true;
    for (int u : graf[now]) if (!v[u]) f(u);
}

bool check(const vector<int> &cur) {
    for (int i = 1; i <= k; ++i) graf[i].clear();
    for (int i = 1; i <= k; ++i) {
        graf[cur[i]].push_back(i);
    }
    v.reset();
    f(1);
    for (int i = 1; i <= k; ++i) if (!v[i]) return false;
    return true;
}

int dfs(vector<int> &cur, int now) {
    if (now > k) {
        if (check(cur)) return 1;
        return 0;
    }
    int ret = 0;
    for (int i = 1; i <= k; ++i) if (now != i) {
        cur[now] = i;
        ret = add(ret, dfs(cur, now + 1));
        cur[now] = 0;
    }
    return ret;
}

int main() {
    cin >> n >> k;
    int m = fpow(n - k, n - k);
    vector<int> perm(maxk);
    int to = dfs(perm, 2);
    for (int i = 2; i <= k; ++i) perm.push_back(i);
    cout << mul(mul(to, k), m) << endl;
}