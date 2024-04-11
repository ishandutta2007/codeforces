#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define per(i, n) for (int i = (n)-1; i >= 0; i--)
#define rep2(i, l, r) for (int i = (l); i < (r); i++)
#define per2(i, l, r) for (int i = (r)-1; i >= (l); i--)
#define each(e, v) for (auto &e : v)
#define MM << " " <<
#define pb push_back
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

template <typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;

template <typename T>
using maxheap = priority_queue<T>;

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

// struct io_setup {
//     io_setup() {
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);
//         cout << fixed << setprecision(15);
//     }
// } io_setup;

const int inf = (1 << 30) - 1;
const ll INF = (1LL << 60) - 1;
// const int MOD = 1000000007;
const int MOD = 998244353;

int query(const vector<int> &v) {
    cout << "?";
    cout << " " << sz(v);
    each(e, v) cout << " " << e + 1;
    cout << endl;
    cout.flush();
    string S;
    cin >> S;
    return (S == "YES" ? 1 : 0);
}

int answer(int x) {
    cout << "! " << x + 1 << endl;
    cout.flush();
    string S;
    cin >> S;
    return (S == ":)" ? 1 : 0);
}

int main() {
    // int K = 100000;
    // int cnt = 0;
    // while (K >= 3) {
    //     if (K % 3 == 0) {
    //         K = (K / 3) * 2;
    //     } else if (K % 3 == 1) {
    //         K = (K / 3) * 2 + 1;
    //     } else {
    //         K = (K / 3) * 2 + 1;
    //     }
    //     cnt++;
    //     cout << K << '\n';
    // }
    // cout << K MM cnt << '\n';

    int N;
    cin >> N;

    vector<int> v(N);
    rep(i, N) v[i] = i;

    while (sz(v) >= 3) {
        int K = sz(v);
        int X = K / 3, Y = K / 3, Z = K / 3;
        if (K % 3 >= 1) Z++;
        if (K % 3 >= 2) Y++;
        vector<int> v1(begin(v), begin(v) + X), v2(begin(v) + X, begin(v) + X + Y), v3(begin(v) + X + Y, end(v));
        int s = 0;
        rep(j, 2) {
            int c = query(v1);
            s += c;
            if (c == 1) break;
        }
        if (s == 0) {
            v.clear();
            each(e, v2) v.eb(e);
            each(e, v3) v.eb(e);
            continue;
        }
        int c = query(v2);
        v.clear();
        if (c == 1) {
            each(e, v1) v.eb(e);
            each(e, v2) v.eb(e);
        } else {
            each(e, v1) v.eb(e);
            each(e, v3) v.eb(e);
        }
    }

    each(e, v) {
        int c = answer(e);
        if (c == 1) break;
    }
}