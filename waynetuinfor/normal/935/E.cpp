#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <class c> struct rge { c bg, ed; };
template <class c> rge<c> range(c i, c j) { return rge<c>{i, j}; }
template <class c> auto dud(c *x) -> decltype(cerr << *x, 0);
template <class c> char dud(...);
#define imie(...) #__VA_ARGS__" = " << (__VA_ARGS__) << " "
struct debug {
~debug() { cerr << endl; }
template <class c> typename \
enable_if <sizeof dud<c>(0) != 1, debug&>::type operator<<(c i) { cerr << boolalpha << i; return *this; }
template <class c> typename \
enable_if <sizeof dud<c>(0) == 1, debug&>::type operator<<(c i) { return *this << range(begin(i), end(i)); }
template <class c, class b> debug &operator<<(pair<c, b> p) { return *this << "(" << p.first << ", " << p.second << ")"; }
template <class c> debug &operator<<(rge<c> d) { *this << "[ "; for (auto it = d.bg; it != d.ed; ++it) *this << ", " + 2 * (it == d.bg) << *it; return *this << " ]"; }
};

const int maxn = 1e4 + 10, maxm = 100 + 10;
const long long inf = 1e18;
long long dpmax[maxm][maxn], dpmin[maxm][maxn];
int lto[maxn], rto[maxn], match[maxn], val[maxn], sum, need[maxn];
bool dig[maxn], ptag;
bool vmax[maxm][maxn], vmin[maxm][maxn];

long long dfsmin(int, int, int);

long long dfsmax(int left, int now, int u) {
    u = need[now];
    if (dig[now]) {
        if (left > 0 || u - left > 0) return -inf;
        return val[now];
    }
    if (vmax[left][now]) return dpmax[left][now];
    dpmax[left][now] = -inf;
    if (ptag) {
        if (u - left > 0) for (int i = 0; i <= left; ++i) dpmax[left][now] = max(dpmax[left][now], dfsmax(i, lto[now], u + 1 + left - i) - dfsmin(left - i, rto[now], u + 1 + i));
        if (left > 0) for (int i = 0; i < left; ++i) dpmax[left][now] = max(dpmax[left][now], dfsmax(i, lto[now], u + 1 + left - i - 1) + dfsmax(left - 1 - i, rto[now], u + 1 + i));
    } else {
        if (u - left > 0) for (int i = 0; i <= left; ++i) dpmax[left][now] = max(dpmax[left][now], dfsmax(i, lto[now], u + 1 + left - i) + dfsmax(left - i, rto[now], u + 1 + i));
        if (left > 0) for (int i = 0; i < left; ++i) dpmax[left][now] = max(dpmax[left][now], dfsmax(i, lto[now], u + 1 + left - 1 - i) - dfsmin(left - 1 - i, rto[now], u + 1 + i));
    }
    vmax[left][now] = true;
    return dpmax[left][now];
}

long long dfsmin(int left, int now, int u) {
    u = need[now];
    if (dig[now]) {
        if (left > 0 || u - left > 0) return inf;
        return val[now];
    }
    if (vmin[left][now]) return dpmin[left][now];
    dpmin[left][now] = inf;
    if (ptag) {
        if (u - left > 0) for (int i = 0; i <= left; ++i) dpmin[left][now] = min(dpmin[left][now], dfsmin(i, lto[now], u + 1 + left - i) - dfsmax(left - i, rto[now], u + 1 + i));
        if (left) for (int i = 0; i < left; ++i) dpmin[left][now] = min(dpmin[left][now], dfsmin(i, lto[now], u + 1 + left - 1 - i) + dfsmin(left - 1 - i, rto[now], u + 1 + i));
    } else {
        if (u - left > 0) for (int i = 0; i <= left; ++i) dpmin[left][now] = min(dpmin[left][now], dfsmin(i, lto[now], u + 1 + left - i) + dfsmin(left - i, rto[now], u + 1 + i));
        if (left > 0) for (int i = 0; i < left; ++i) dpmin[left][now] = min(dpmin[left][now], dfsmin(i, lto[now], u + 1 + left - 1 - i) - dfsmax(left - 1 - i, rto[now], u + 1 + i));
    }
    vmin[left][now] = true;
    return dpmin[left][now];
}

int dfs(int now) {
    need[now] = 0;
    if (dig[now]) return 0;
    need[now] = dfs(lto[now]) + dfs(rto[now]) + 1;
    return need[now];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string e; cin >> e;
    stack<int> s;
    int cnt = 0;
    for (int i = 0; i < (int)e.size(); ++i) {
        if (e[i] == '(') {
            ++cnt;
            if (s.size() && !lto[s.top()]) lto[s.top()] = cnt;
            s.push(cnt);
        } else if (e[i] == ')') {
            match[i] = s.top();
            s.pop();
        } else if (e[i] >= '0' && e[i] <= '9') {
            ++cnt;
            if (s.size() && !lto[s.top()]) lto[s.top()] = cnt;
            match[i] = cnt;
            dig[cnt] = true;
            val[cnt] = e[i] - '0';
        } 
    }
    assert(s.size() == 0);
    for (int i = (int)e.size() - 1; i >= 0; --i) {
        if (e[i] == ')') {
            if (s.size() && !rto[s.top()]) rto[s.top()] = match[i];
            s.push(match[i]);
        } else if (e[i] == '(') s.pop();
        else if (e[i] >= '0' && e[i] <= '9') {
            if (s.size() && !rto[s.top()]) rto[s.top()] = match[i];
        }
    }
    int p, m; cin >> p >> m;
    sum = p + m;
    if (p < m) ptag = true; 
    dfs(1);
    cout << dfsmax(min(p, m), 1, 0) << endl;
    return 0;
}