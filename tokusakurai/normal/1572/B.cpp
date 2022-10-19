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
const int MOD = 1000000007;
// const int MOD = 998244353;
const int inf = (1 << 30) - 1;
const ll INF = (1LL << 60) - 1;
template <typename T>
bool chmax(T &x, const T &y) {
    return (x < y) ? (x = y, true) : false;
}
template <typename T>
bool chmin(T &x, const T &y) {
    return (x > y) ? (x = y, true) : false;
}

struct io_setup {
    io_setup() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout << fixed << setprecision(15);
    }
} io_setup;

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
void unique(vector<T> &v) {
    sort(begin(v), end(v));
    v.erase(unique(begin(v), end(v)), end(v));
}

template <typename T>
vector<int> iota(const vector<T> &v, bool greater = false) {
    int n = v.size();
    vector<int> ret(n);
    iota(begin(ret), end(ret), 0);
    sort(begin(ret), end(ret), [&](int i, int j) { return greater ? v[i] > v[j] : v[i] < v[j]; });
    return ret;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> a(N);
        rep(i, N) cin >> a[i];

        if (accumulate(all(a), 0) & 1) {
            cout << "NO\n";
            continue;
        }

        vector<int> ans;
        vector<int> c(N, 0);
        rep3(i, N - 1, 0) {
            if (i < N - 1 && a[i] == a[i + 1])
                c[i] = c[i + 1] + 1;
            else
                c[i] = 1;
        }

        int tmp = 0;
        int p = 0;

        while (p < N) {
            if (a[p] == 1) {
                if (tmp == -1) a[p] = 0;
                tmp += c[p];
            } else {
                if (tmp % 2 == 1) {
                    int np = p + c[p];
                    if (c[p] % 2 == 1) {
                        for (int i = p; i <= np - 3; i += 2) {
                            ans.eb(i - 1);
                            a[i] = 1, a[i + 1] = 1;
                        }
                        ans.eb(np - 2);
                        a[np - 2] = 0;
                        tmp = -1;
                    } else {
                        for (int i = p; i <= np - 2; i += 2) {
                            ans.eb(i - 1);
                            a[i] = 1, a[i + 1] = 1;
                        }
                        tmp += c[p];
                    }
                }
            }
            p += c[p];
        }

        if (accumulate(all(a), 0) == N) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        rep(i, N) {
            if (a[i] == 0) continue;
            int j = 0;
            while (i + j < N && a[i + j] == 1) j++;
            if (i + j < N) {
                for (int k = i + j - 2; k >= i; k -= 2) {
                    ans.eb(k);
                    a[k] = 0, a[k + 1] = 0;
                }
            } else {
                for (int k = i; k <= i + j - 2; k += 2) {
                    ans.eb(k - 1);
                    a[k] = 0, a[k + 1] = 0;
                }
            }
        }

        cout << sz(ans) << '\n';
        print(ans, 1);
    }
}