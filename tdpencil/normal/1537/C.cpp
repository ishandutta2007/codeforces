#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iterator>
using namespace __gnu_pbds;
using namespace std;
template <typename T> using oset = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class Fun>
class y_combinator_result {
    Fun fun_;
    public:
    template<class T>
        explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
        decltype(auto) operator()(Args &&...args) {
            return fun_(std::ref(*this), std::forward<Args>(args)...);
        }
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

#define take_input 0
void solve() {
    int N; cin >> N;
    vector<int> H(N);
    for(auto &h: H)
        cin >> h;

    sort(H.begin(), H.end());

    int pos = -1, mx = 2e9;

    for(int i = 0; i < N - 1; i++) {
        if(H[i + 1] - H[i] < mx) {
            mx = H[i + 1] - H[i];
            pos = i + 1;
        }
    }

    swap(H[pos - 1], H[pos]);

    for(int i = pos; i < N; i++)
        cout << H[i] << " ";

    for(int i = 0; i < pos; i++)
        cout << H[i] << " ";

    cout << "\n";
}

int main() {
    
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;

#ifdef take_input
    cin >> T;
#endif

    for(;T; --T)
        solve();
    
}