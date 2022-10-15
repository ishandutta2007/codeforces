#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// K > floor(log(n))
template<int K, typename T, typename Op>
struct SparseTable {
    int n;
    Op op;
    vector<array<T, K>> st;
    vector<int> log;
    SparseTable(const vector<T>& a, Op op = Op()) : n((int)size(a)), op(op), st(n), log(n + 1) {
        for (int x = 2; x <= n; ++x) log[x] = 1 + log[x >> 1];
        assert(log[n] < K);
        for (int i = 0; i < n; ++i) st[i][0] = a[i];
        for (int x = 1; x <= log[n]; ++x)
            for (int i = 0; i + (1 << x) <= n; ++i)
                st[i][x] = op(st[i][x - 1], st[i + (1 << (x - 1))][x - 1]);
    }
    T query(int l, int r) const {
        assert(l <= r);
        int x = log[r - l + 1];
        return op(st[l][x], st[r - (1 << x) + 1][x]);
    }
};
template<typename T>
struct MinFunctor {
    T operator()(T x, T y) const { return min(x, y); }
};
template<int K, typename T>
using RMQ = SparseTable<K, T, MinFunctor<T>>;
template<typename T>
bool chmin(T& x, T y) { return y < x ? (x = y, true) : false; }
template<typename T>
bool chmax(T& x, T y) { return x < y ? (x = y, true) : false; }
template<typename T>
struct Recovery {
    struct Node {
        T value;
        Node* prev;
        Node(T value, Node* prev) : value(value), prev(prev) { }
    };
    deque<Node> states;
    Node* create(T value, Node* prev) {
        return &states.emplace_back(value, prev);
    } 
    vector<T> recover(Node* last) {
        vector<T> res;
        while (last != nullptr) {
            res.push_back(last->value);
            last = last->prev;
        }
        reverse(begin(res), end(res));
        return res;
    }
};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> k(n);
    vector<array<int, 2>> L(n), R(n);
    for (int i = 0; i < n; ++i) {
        cin >> k[i];
        for (int t : {0, 1}) cin >> L[i][t];
        for (int t : {0, 1}) cin >> R[i][t];
    }
    L.push_back({0, m}), R.push_back({0, m});
    auto op = [](auto I, auto J) {
        return array<int, 2>{max(I[0], J[0]), min(I[1], J[1])};
    };
    constexpr int K = 20;
    SparseTable<K, array<int, 2>, decltype(op)> st[2] = {{L, op}, {R, op}};
    vector<bool> goodL(n), goodR(n);
    for (int i = 0; i < n; ++i) {
        goodL[i] = (L[i][0] <= k[i] && k[i] <= L[i][1]);
        goodR[i] = (R[i][0] <= k[i] && k[i] <= R[i][1]);
    }
    RMQ<K, bool> stgood[2] = {{goodL}, {goodR}};
    array<int, 2> mx{-1, -1};
    using Rec = Recovery<array<int, 2>>;
    Rec rec;
    array<Rec::Node*, 2> last{};
    for (int t : {0, 1}) {
        for (int i = 0; i <= n; ++i) {
            if ((i == 0 || stgood[t ^ 1].query(0, i - 1)) && st[t].query(0, i)[0] == 0) mx[t] = i;
            else break;
        }
        last[t] = rec.create({t, -1}, nullptr);
    }
    for (int i = 0; i < n; ++i) {
        array<int, 2> nxt{-1, -1};
        for (int t : {0, 1}) {
            if (mx[t ^ 1] < i) continue;
            auto check = [&](int j) {
                if (i + 1 < j && not stgood[t ^ 1].query(i + 1, j - 1)) return false;
                auto [l, r] = st[t].query(i, j);
                return l <= k[i] && k[i] <= r;
            };
            if (not check(i)) continue;
            int l = i, r = n + 1;
            while (l + 1 < r) {
                int m = (l + r) / 2;
                check(m) ? l = m : r = m;
            }
            nxt[t] = l;
        }
        auto tmp = last;
        for (int t : {0, 1}) {
            if (chmax(mx[t], nxt[t])) {
                last[t] = rec.create({t, i}, tmp[t ^ 1]);
            }
        }
    }
    int b = mx[0] >= mx[1] ? 0 : 1;
    if (mx[b] < n) {
        cout << "No" << endl;
    }
    else {
        auto I = rec.recover(last[b]);
        vector<int> ans(n, -1);
        for (auto [t, i] : I) {
            if (i != -1) ans[i] = t;
            if (i + 1 < n) ans[i + 1] = t ^ 1;
        }
        cout << "Yes" << endl;
        for (int i = 0, cur = 0; i < n; ++i) {
            if (ans[i] == -1) ans[i] = cur;
            cur = ans[i];
            cout << ans[i] << "\n "[i + 1 < n];
        }
    }
    exit(0);
}