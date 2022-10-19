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
    if (v.empty()) cout << '\n';
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

template <typename S, typename T>
pair<S, T> operator+(const pair<S, T> &p, const pair<S, T> &q) {
    return make_pair(p.first + q.first, p.second + q.second);
}

template <typename S, typename T>
pair<S, T> operator-(const pair<S, T> &p, const pair<S, T> &q) {
    return make_pair(p.first - q.first, p.second - q.second);
}

template <typename S, typename T>
istream &operator>>(istream &is, pair<S, T> &p) {
    S a;
    T b;
    is >> a >> b;
    p = make_pair(a, b);
    return is;
}

template <typename S, typename T>
ostream &operator<<(ostream &os, const pair<S, T> &p) {
    return os << p.first << ' ' << p.second;
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

int L = 0;
vector<pii> ans;

void solve1(vector<int> &a, int l, int r) {
    rep2(i, l, r - 1) {
        ans.eb(L + r + (i - l), a[i]);
        //
    }
    L += 2 * (r - l);
    reverse(begin(a) + l, begin(a) + r);
}

void solve2(vector<int> &a, int l, int r) {
    rep3(i, r - 1, l) {
        ans.eb(L + l + r - 1 - i, a[i]);
        //
    }
    reverse(begin(a) + l, begin(a) + r);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        L = 0;
        ans.clear();

        int N;
        cin >> N;

        vector<int> a(N);
        map<int, int> mp;
        rep(i, N) {
            cin >> a[i];
            mp[a[i]]++;
        }

        bool flag = false;
        each(e, mp) {
            if (e.second & 1) flag = true;
        }
        if (flag) {
            cout << "-1\n";
            continue;
        }

        vector<int> ans1, ans2;

        rep(i, N / 2) {
            int ptr = 2 * i;
            while (ptr < N && a[ptr] != a[N - 1]) ptr++;
            solve1(a, 2 * i, ptr + 1);
            solve2(a, 2 * i + 1, N);
            ans1.eb(2 * (ptr + 1 - 2 * i));
            ans1.eb(2);
            ans2.eb(2 * (N - (2 * i + 1)));
        }

        cout << sz(ans) << '\n';
        each(e, ans) cout << e << '\n';

        reverse(all(ans2));
        // cout << sz(ans1) + N / 2 + sz(ans2) << '\n';

        vector<int> all = ans1;
        each(e, ans2) all.eb(e);
        cout << sz(all) << '\n';
        print(all);
    }
}