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

template <typename T>
struct Segment_Tree_Beats {
    vector<T> max_1, max_2, min_1, min_2;
    vector<int> max_cnt, min_cnt;
    vector<T> sum, add, upd; // addupd
    vector<int> L, R;
    const T INF_T = numeric_limits<T>::max() / 2;
    int n;

    Segment_Tree_Beats(const vector<T> &v) {
        int m = v.size();
        n = 1;
        while (n < m) n <<= 1;
        max_1.assign(2 * n, -INF_T), max_2.assign(2 * n, -INF_T), max_cnt.assign(2 * n, 0);
        min_1.assign(2 * n, INF_T), min_2.assign(2 * n, INF_T), min_cnt.assign(2 * n, 0);
        sum.assign(2 * n, 0), add.assign(2 * n, 0), upd.assign(2 * n, INF_T);
        L.assign(2 * n, 0), R.assign(2 * n, n);
        for (int i = 1; i < n; i++) {
            L[2 * i] = L[i], R[2 * i] = (L[i] + R[i]) / 2;
            L[2 * i + 1] = (L[i] + R[i]) / 2, R[2 * i + 1] = R[i];
        }
        for (int i = 0; i < m; i++) init_node(i, v[i]);
        for (int i = n - 1; i > 0; i--) pull(i);
    }

    void init_node(int i, T x) {
        i += n;
        max_1[i] = x, max_cnt[i] = 1;
        min_1[i] = x, min_cnt[i] = 1;
        sum[i] = x;
    }

    void node_chmin(int i, const T &x) { // max_1[i] > x > max_2[i]chmin
        sum[i] += (x - max_1[i]) * max_cnt[i];
        if (min_1[i] == max_1[i]) min_1[i] = x;
        if (min_2[i] == max_1[i]) min_2[i] = x;
        max_1[i] = x;
        if (upd[i] != INF_T && x < upd[i]) upd[i] = x;
    }

    void node_chmax(int i, const T &x) { // min_1[i] < x < min_2[i]chmax
        sum[i] += (x - min_1[i]) * min_cnt[i];
        if (max_1[i] == min_1[i]) max_1[i] = x;
        if (max_2[i] == min_1[i]) max_2[i] = x;
        min_1[i] = x;
        if (upd[i] != INF_T && x > upd[i]) upd[i] = x;
    }

    void node_add(int i, const T &x) { //add
        if (max_1[i] != -INF_T) max_1[i] += x;
        if (max_2[i] != -INF_T) max_2[i] += x;
        if (min_1[i] != INF_T) min_1[i] += x;
        if (min_2[i] != INF_T) min_2[i] += x;
        sum[i] += x * (R[i] - L[i]);
        if (upd[i] != INF_T) upd[i] += x;
        add[i] += x;
    }

    void node_update(int i, const T &x) { //update
        max_1[i] = x, max_2[i] = -INF_T, max_cnt[i] = R[i] - L[i];
        min_1[i] = x, min_2[i] = INF_T, min_cnt[i] = R[i] - L[i];
        upd[i] = x, add[i] = 0;
    }

    void push(int i) { // i
        if (upd[i] != INF_T) {
            node_update(2 * i, upd[i]);
            node_update(2 * i + 1, upd[i]);
            upd[i] = INF_T;
            return;
        }
        if (add[i] != 0) {
            node_add(2 * i, add[i]);
            node_add(2 * i + 1, add[i]);
            add[i] = 0;
        }
        if (max_1[i] < max_1[2 * i]) node_chmin(2 * i, max_1[i]);
        if (min_1[i] > min_1[2 * i]) node_chmax(2 * i, min_1[i]);
        if (max_1[i] < max_1[2 * i + 1]) node_chmin(2 * i + 1, max_1[i]);
        if (min_1[i] > min_1[2 * i + 1]) node_chmax(2 * i + 1, min_1[i]);
    }

    void pull(int i) { //i
        int l = 2 * i, r = 2 * i + 1;
        sum[i] = sum[l] + sum[r];
        if (max_1[l] > max_1[r]) {
            max_1[i] = max_1[l], max_2[i] = max(max_2[l], max_1[r]);
            max_cnt[i] = max_cnt[l];
        } else if (max_1[l] < max_1[r]) {
            max_1[i] = max_1[r], max_2[i] = max(max_1[l], max_2[r]);
            max_cnt[i] = max_cnt[r];
        } else {
            max_1[i] = max_1[l], max_2[i] = max(max_2[l], max_2[r]);
            max_cnt[i] = max_cnt[l] + max_cnt[r];
        }
        if (min_1[l] < min_1[r]) {
            min_1[i] = min_1[l], min_2[i] = min(min_2[l], min_1[r]);
            min_cnt[i] = min_cnt[l];
        } else if (min_1[l] > min_1[r]) {
            min_1[i] = min_1[r], min_2[i] = min(min_1[l], min_2[r]);
            min_cnt[i] = min_cnt[r];
        } else {
            min_1[i] = min_1[l], min_2[i] = min(min_2[l], min_2[r]);
            min_cnt[i] = min_cnt[l] + min_cnt[r];
        }
    }

    void range_chmin(int l, int r, const T &x, int i = 1) {
        if (r <= L[i] || R[i] <= l || max_1[i] <= x) return;
        if (l <= L[i] && R[i] <= r && max_2[i] < x)
            node_chmin(i, x);
        else {
            push(i);
            range_chmin(l, r, x, 2 * i);
            range_chmin(l, r, x, 2 * i + 1);
            pull(i);
        }
    }

    void range_chmax(int l, int r, const T &x, int i = 1) {
        if (r <= L[i] || R[i] <= l || min_1[i] >= x) return;
        if (l <= L[i] && R[i] <= r && min_2[i] > x)
            node_chmax(i, x);
        else {
            push(i);
            range_chmax(l, r, x, 2 * i);
            range_chmax(l, r, x, 2 * i + 1);
            pull(i);
        }
    }

    void range_add(int l, int r, const T &x, int i = 1) {
        if (r <= L[i] || R[i] <= l) return;
        if (l <= L[i] && R[i] <= r)
            node_add(i, x);
        else {
            push(i);
            range_add(l, r, x, 2 * i);
            range_add(l, r, x, 2 * i + 1);
            pull(i);
        }
    }

    void range_update(int l, int r, const T &x, int i = 1) {
        if (r <= L[i] || R[i] <= l) return;
        if (l <= L[i] && R[i] <= r)
            node_update(i, x);
        else {
            push(i);
            range_update(l, r, x, 2 * i);
            range_update(l, r, x, 2 * i + 1);
            pull(i);
        }
    }

    T range_min(int l, int r, int i = 1) {
        if (r <= L[i] || R[i] <= l) return INF_T;
        if (l <= L[i] && R[i] <= r) return min_1[i];
        push(i);
        return min(range_min(l, r, 2 * i), range_min(l, r, 2 * i + 1));
    }

    T range_max(int l, int r, int i = 1) {
        if (r <= L[i] || R[i] <= l) return -INF_T;
        if (l <= L[i] && R[i] <= r) return max_1[i];
        push(i);
        return max(range_max(l, r, 2 * i), range_max(l, r, 2 * i + 1));
    }

    T range_sum(int l, int r, int i = 1) {
        if (r <= L[i] || R[i] <= l) return 0;
        if (l <= L[i] && R[i] <= r) return sum[i];
        push(i);
        return range_sum(l, r, 2 * i) + range_sum(l, r, 2 * i + 1);
    }
};

int main() {
    int N, Q, K;
    cin >> N >> Q >> K;

    vector<int> a(N);
    rep(i, N) cin >> a[i];

    vector<int> b(N);
    deque<int> que;
    rep3(i, N - 1, 0) {
        while (!empty(que) && a[que.front()] >= a[i]) que.pop_front();
        que.push_front(i);
        if (que.back() == i + K) que.pop_back();
        b[i] = a[que.back()];
    }

    vector<vector<pii>> qs(N);
    rep(i, Q) {
        int l, r;
        cin >> l >> r;
        l--;
        qs[l].eb(i, r);
    }

    vector<ll> ans(Q, 0);

    rep(i, K) {
        vector<ll> v;
        for (int j = i; j < N; j += K) v.eb(a[j]);
        int M = sz(v);

        Segment_Tree_Beats<ll> seg(v);

        rep3(j, M - 1, 0) {
            int p = i + j * K;
            each(e, qs[p]) {
                int D = (e.second - p + K - 1) / K;
                ans[e.first] += seg.range_sum(j, j + D);
            }
            if (j >= 1) seg.range_chmin(j, M, b[p - K]);
        }
    }

    printn(ans);
}