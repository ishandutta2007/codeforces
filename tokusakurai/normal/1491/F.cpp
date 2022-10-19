#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep2(i, x, n) for (int i = x; i <= n; i++)
#define rep3(i, x, n) for (int i = x; i >= n; i--)
#define each(e, v) for (auto &e : v)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

template <typename T>
bool chmax(T &x, const T &y) {
    return (x < y) ? (x = y, true) : false;
}

template <typename T>
bool chmin(T &x, const T &y) {
    return (x > y) ? (x = y, true) : false;
}

template <typename T>
int flg(T x, int i) {
    return (x >> i) & 1;
}

template <typename T>
void print(const vector<T> &v, T x = 0) {
    int n = v.size();
    for (int i = 0; i < n; i++) cout << v[i] + x << (i == n - 1 ? '\n' : ' ');
}

template <typename T>
void printn(const vector<T> &v, T x = 0) {
    int n = v.size();
    for (int i = 0; i < n; i++) cout << v[i] + x << '\n';
}

template <typename T>
int lb(const vector<T> &v, T x) {
    return lower_bound(begin(v), end(v), x) - begin(v);
}

template <typename T>
int ub(const vector<T> &v, T x) {
    return upper_bound(begin(v), end(v), x) - begin(v);
}

template <typename T>
void rearrange(vector<T> &v) {
    sort(begin(v), end(v));
    v.erase(unique(begin(v), end(v)), end(v));
}

template <typename T>
vector<int> id_sort(const vector<T> &v, bool greater = false) {
    int n = v.size();
    vector<int> ret(n);
    iota(begin(ret), end(ret), 0);
    sort(begin(ret), end(ret), [&](int i, int j) { return greater ? v[i] > v[j] : v[i] < v[j]; });
    return ret;
}

const int inf = (1 << 30) - 1;
const ll INF = (1LL << 60) - 1;
const int MOD = 1000000007;
// const int MOD = 998244353;

int query(vector<int> l, vector<int> r) {
    cout << "? ";
    cout << sz(l) << ' ' << sz(r) << '\n';
    print(l, 1), print(r, 1);
    int x;
    cin >> x;
    return x;
}

void answer(vector<int> v) {
    cout << "! ";
    cout << sz(v) << ' ';
    print(v, 1);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> col(N, 0);
        int p = inf;

        rep(i, N - 1) {
            vector<int> l, r;
            l.eb(i);
            rep2(j, i + 1, N - 1) r.eb(j);
            int x = query(l, r);
            if (x != 0) {
                p = i;
                col[i] = x;
                break;
            }
        }

        int s = 0;
        // cout << p << endl;

        rep2(i, p + 1, N - 2) {
            vector<int> l = {p}, r = {i};
            int x = query(l, r);
            col[i] = x;
            s += x;
        }

        col[N - 1] = col[p] - s;

        int L = 0, R = p;

        while (R - L > 1) {
            int M = (L + R + 1) / 2;
            vector<int> l, r;
            rep2(i, L, M - 1) l.eb(i);
            r.eb(p);
            int x = query(l, r);
            (x != 0 ? R : L) = M;
        }

        if (L == p - 1) {
            vector<int> l = {L}, r = {p};
            col[L] = query(l, r);
        } else if (L < p) {
            col[L] = 1;
        }

        vector<int> v;

        rep(i, N) {
            if (col[i] == 0) v.eb(i);
        }

        answer(v);
    }
}