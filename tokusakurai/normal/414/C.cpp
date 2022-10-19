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

struct io_setup {
    io_setup() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout << fixed << setprecision(15);
    }
} io_setup;

const int inf = (1 << 30) - 1;
const ll INF = (1LL << 60) - 1;
const int MOD = 1000000007;
// const int MOD = 998244353;

vector<int> a;
vector<ll> c1, c2;

void rec(int i, int l, int r) {
    if (r - l == 1) return;
    int m = (l + r) / 2;
    rec(2 * i, l, m), rec(2 * i + 1, m, r);
    vector<int> al(begin(a) + l, begin(a) + m), ar(begin(a) + m, begin(a) + r);
    int pl = 0, pr = 0;
    each(e, al) {
        while (pr < sz(ar) && ar[pr] < e) pr++;
        c1[i] += pr;
    }
    each(e, ar) {
        while (pl < sz(al) && al[pl] < e) pl++;
        c2[i] += pl;
    }
    al.eb(inf), ar.eb(inf);
    pl = 0, pr = 0;
    for (int j = l; j < r; j++) {
        if (al[pl] < ar[pr]) {
            a[j] = al[pl++];
        } else {
            a[j] = ar[pr++];
        }
    }
}

int main() {
    int N;
    cin >> N;

    a.resize(1 << N);
    rep(i, 1 << N) cin >> a[i];

    c1.assign(1 << (N + 1), 0), c2.assign(1 << (N + 1), 0);
    rec(1, 0, 1 << N);
    // print(a);

    vector<ll> s1(N, 0), s2(N, 0);
    rep(i, N) {
        rep(j, 1 << i) {
            s1[i] += c1[(1 << i) + j];
            s2[i] += c2[(1 << i) + j];
        }
    }

    vector<int> col(N, 0);
    ll ans = accumulate(all(s1), 0LL);

    int Q;
    cin >> Q;

    while (Q--) {
        int t;
        cin >> t;
        rep2(i, N - t, N - 1) {
            if (col[i] == 0) {
                ans += s2[i] - s1[i];
            } else {
                ans += s1[i] - s2[i];
            }
            col[i] ^= 1;
        }
        cout << ans << '\n';
    }
}