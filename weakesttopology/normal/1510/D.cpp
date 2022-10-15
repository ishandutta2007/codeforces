#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
constexpr int mod = 10;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, d;
    cin >> n >> d;
    const double inf = 1e300;
    Recovery<int> rec;
    vector<double> dp(mod, -inf);
    vector<Recovery<int>::Node*> last(mod, nullptr);
    dp[1] = 0;
    bool one = false;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a == 1) {
            one = true;
            continue;
        }
        auto dpnxt = dp;
        auto lastnxt = last;
        for (int x = 0; x < mod; ++x) {
            int nx = x * a % mod;
            if (chmax(dpnxt[nx], dp[x] + log(a))) {
                lastnxt[nx] = rec.create(a, last[x]);
            }
        }
        swap(dp, dpnxt), swap(last, lastnxt);
    }
    if (dp[d] < 0 || (dp[d] == 0 && d == 1 && not one)) {
        cout << -1 << endl;
    }
    else {
        auto I = rec.recover(last[d]);
        cout << size(I) << endl;
        for (auto a : I) {
            cout << a << " ";
        }
        cout << endl;
    }
    exit(0);
}