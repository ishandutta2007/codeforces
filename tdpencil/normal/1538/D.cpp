#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9+7, M = (1e9+7), MAXN = 1 * 2e5;
int A[MAXN], C[MAXN];
#include <ext/pb_ds/assoc_container.hpp>
 #include <ext/pb_ds/tree_policy.hpp>
 #include <iterator>
 using namespace __gnu_pbds;

 template <typename T> using oset = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

pair<int, int> factors(int x) {
    pair<int, int> ans = {0, 0};
    if(x == 1) ans.first = 0;
    else ans.first = 1;
    int cur = 0;
    for(int i = 2; i * i <= x; i++) {
        while(x % i == 0) {
             x /= i;
             ++cur;
        }
    }
    ans.second = cur;
    if(x > 1) ans.second++;
    return ans;
}
void solve() {
    int A, B, K;
    cin >> A >> B >> K;
    int common = __gcd(A, B);
    if(A == B && K < 2) {
        cout << "NO\n";
        return;
    }
    if(false ) {
        cout << "YES\n";
    } else {
        int res1 = A, res2 = B;
        pair<int, int> a = factors(res1), b = factors(res2);
        int v = 0;
        if(res1 != common) v++;
        if(res2 != common) v++;
        cerr << "DEBUG: " << a.first << " " << b.first << endl;
        cerr << "DEBUG A: " << a.second << " " << b.second << endl;
        if(K >= v && K <= a.second + b.second) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T = 1; cin >> T;

    while(T--) {
        solve();
    }
}