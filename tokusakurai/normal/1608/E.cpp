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

int N;
vector<vector<pii>> ps(3);

bool comp_x(const pii &p, const pii &q) {
    if (p.first != q.first) return p.first < q.first;
    return p.second < q.second;
}

bool comp_y(const pii &p, const pii &q) {
    if (p.second != q.second) return p.second < q.second;
    return p.first < q.first;
}

void rotate() {
    rep(i, 3) {
        rep(j, N) {
            swap(ps[i][j].first, ps[i][j].second);
            ps[i][j].first *= -1;
        }
    }
}

int solve1(int a, int b, int c) {
    rep(i, 3) sort(all(ps[i]), comp_x);
    int L = 0, R = N + 1;
    while (R - L > 1) {
        int M = (L + R) / 2;
        int x1 = ps[a][M - 1].first + 1;
        int p2 = lb(ps[b], pii(x1, -inf)) + M - 1;
        int x2 = (p2 < N ? ps[b][p2].first + 1 : inf);
        int p3 = lb(ps[c], pii(x2, -inf)) + M - 1;
        (p3 < N ? L : R) = M;
    }
    return L;
}

int solve2(int a, int b, int c) {
    sort(all(ps[a]), comp_x);
    sort(all(ps[b]), comp_y);
    sort(all(ps[c]), comp_y);
    int L = 0, R = N + 1;
    while (R - L > 1) {
        int M = (L + R) / 2;
        int x = ps[a][M - 1].first + 1;
        int cnt = 0, ptr = -1;
        while (ptr < N - 1 && cnt < M) {
            ptr++;
            if (ps[b][ptr].first >= x) cnt++;
        }
        int y = (cnt == M ? ps[b][ptr].second + 1 : inf);
        cnt = 0, ptr = -1;
        while (ptr < N - 1 && cnt < M) {
            ptr++;
            if (ps[c][ptr].first >= x && ps[c][ptr].second >= y) cnt++;
        }
        (cnt == M ? L : R) = M;
    }
    return L;
}

int main() {
    cin >> N;

    rep(i, N) {
        int x, y, c;
        cin >> x >> y >> c;
        c--;
        ps[c].eb(x, y);
    }
    N /= 3;

    int ans = 0;

    rep(i, 4) {
        vector<int> v = {0, 1, 2};
        do {
            int a = v[0], b = v[1], c = v[2];
            chmax(ans, solve1(a, b, c));
            chmax(ans, solve2(a, b, c));
        } while (next_permutation(all(v)));
        rotate();
    }

    cout << ans * 3 << '\n';
}