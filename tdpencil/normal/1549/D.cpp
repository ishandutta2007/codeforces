#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


template<class T>
struct RMQ {
    vector<vector<T>> jmp;
    RMQ(const vector<T>& V) : jmp(1, V) {
        for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
            jmp.emplace_back(sz(V) - pw * 2 + 1);
            rep(j,0,sz(jmp[k]))
                jmp[k][j] = __gcd(jmp[k - 1][j], jmp[k - 1][j + pw]);
        }
    }
    T query(int a, int b) {
        assert(a < b); // or return inf if a == b
        int dep = 31 - __builtin_clz(b - a);
        return __gcd(jmp[dep][a], jmp[dep][b - (1 << dep)]);
    }
};
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt; cin >> tt;

    for(; tt; --tt) {
        int N; cin >> N;
        vector<ll> A(N);
        for(auto &i: A)
            cin >> i;
        vector<ll> D(N - 1);
        for(int i = 1; i < N; ++i)
            D[i - 1] = abs(A[i] - A[i-1]);
        RMQ<ll> gcds(D);
        int lo = 0, hi = 1;
        int ans = 1;
        for(; lo < N; ++lo) {
            hi = max(hi, lo + 1);
            while(hi < N && gcds.query(lo, hi) != 1) {
                ++hi;
            }
            --hi;
            ans = max(ans, hi - lo + 1);
        }
        cout << ans << "\n";
    }
}