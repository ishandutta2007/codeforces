#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 0x3f3f3f3f3f3f3f3f;
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
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
        }
        vector<int> I(n);
        iota(begin(I), end(I), 0);
        sort(begin(I), end(I), [&](int i, int j) { return b[i] < b[j]; });
        Recovery<int> rec;
        vector<ll> dp(k + 1, -inf);
        vector<Recovery<int>::Node*> last(k + 1);
        dp[0] = 0;
        for (auto i : I) {
            for (int x = k - 1; x >= 0; --x) {
                if (dp[x] > -inf && chmax(dp[x + 1], dp[x] + (x - (k - 1)) * b[i] + a[i])) {
                    last[x + 1] = rec.create(i, last[x]);
                }
            }
        }
        ll opt = dp[k] + (k - 1) * accumulate(begin(b), end(b), 0LL);
        cerr << "opt == " << opt << endl;
        auto J = rec.recover(last[k]);
        int l = J.back();
        J.pop_back();
        vector<bool> taken(n);
        cout << k + 2 * (n - k) << endl;
        for (auto i : J) {
            taken[i] = true;
            cout << i + 1 << " ";
        }
        taken[l] = true;
        for (int i = 0; i < n; ++i) {
            if (not taken[i]) {
                for (int sgn : {+1, -1}) {
                    cout << sgn * (i + 1) << " ";
                }
            }
        }
        cout << l + 1 << endl;
    }
    exit(0);
}