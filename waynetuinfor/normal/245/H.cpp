#include <bits/stdc++.h>
#define getchar gtx
using namespace std;

const int maxn = 5000 + 10, mod = 433494437, p = 233, maxq = 1e6 + 1;
long long pw[maxn], hs[maxn], rhs[maxn];
int ans[maxq];
string s;

inline int gtx() {
    const int N = 1048576;
    static char buffer[N];
    static char *p = buffer, *end = buffer;
    if (p == end) {
        if ((end = buffer + fread(buffer, 1, N, stdin)) == buffer) return EOF;
        p = buffer;
    }
    return *p++;
}

template <typename T>
inline bool rit(T& x) {
    char __c = 0; bool flag = false;
    while (__c = getchar(), (__c < '0' && __c != '-') || __c > '9') if (__c == -1) return false;
    __c == '-' ? (flag = true, x = 0) : (x = __c - '0');
    while (__c = getchar(), __c >= '0' && __c <= '9') x = x * 10 + __c - '0';
    if (flag) x = -x;
    return true;
}

template <typename T, typename ...Args>
inline bool rit(T& x, Args& ...args) { return rit(x) && rit(args...); }

int mul(int a, int b) {
    return (long long)a * (long long)b >= mod ? (long long)a * (long long)b % mod : (long long)a * (long long)b;
}

int add(int a, int b) {
    return a + b >= mod ? a + b - mod : a + b;
}

int sub(int a, int b) {
    return a - b < 0 ? a - b + mod : a - b;
}

void init() {
    pw[0] = 1;
    for (int i = 1; i < maxn; ++i) pw[i] = mul(pw[i - 1], p);
    hs[0] = s[0];
    for (int i = 1; i < s.length(); ++i) hs[i] = add(mul(hs[i - 1], p), s[i]);
    rhs[s.length() - 1] = s[s.length() - 1];
    for (int i = s.length() - 2; i >= 0; --i) rhs[i] = add(mul(rhs[i + 1], p), s[i]);
}

bool check(int l, int r) {
    long long h, rh;
    if (l == 0) h = hs[r];
    else h = sub(hs[r], mul(hs[l - 1], pw[r - l + 1]));
    if (r == s.length() - 1) rh = rhs[l];
    else rh = sub(rhs[l], mul(rhs[r + 1], pw[r - l + 1]));
    return h == rh;
}

struct query { int l, r, id;  } qry[maxq];

struct Fenwick {
    int arr[maxn];
    void init() {
        memset(arr, 0, sizeof(arr));
    }
    inline int lowbit(int x) {
        return x & -x;
    }
    void add(int x, int v) {
        for (int i = x; i < maxn; i += lowbit(i)) arr[i] += v;
    }
    int qry(int x) {
        int ret = 0;
        for (int i = x; i; i -= lowbit(i)) ret += arr[i];
        return ret;
    }
} bit;

int main() {
    //  ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> s;
    init();
    vector<pair<int, int>> pal;
    for (int i = 0; i < s.length(); ++i) {
        for (int j = i; j < s.length(); ++j) if (check(i, j)) {
            pal.push_back(make_pair(i + 1, j + 1));
        }
    }
    sort(pal.begin(), pal.end(), [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; });
    int q; rit(q);
    for (int i = 0; i < q; ++i) {
        rit(qry[i].l, qry[i].r);
        qry[i].id = i;
    }
    sort(qry, qry + q, [](const query& a, const query& b) { return a.r < b.r; });
    bit.init();
    int ind = 0;
    for (int i = 0; i < q; ++i) {
        while (ind < pal.size() && pal[ind].second <= qry[i].r) {
            bit.add(pal[ind].first, 1);
            ++ind;
        }
        ans[qry[i].id] = bit.qry(qry[i].r) - bit.qry(qry[i].l - 1);
    }
    for (int i = 0; i < q; ++i) printf("%d\n", ans[i]);
    return 0;
}