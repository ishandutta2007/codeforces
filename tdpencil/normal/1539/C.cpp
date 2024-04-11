#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iterator>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int MAXN = 1e6, M = 1e9+7, inf = -2e9;
// #define runcase LOL
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ull> vul;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<array<int, 2>> var2;
typedef vector<array<int, 3>> var3;
typedef pair<ll, ll> pl;
typedef vector<pl> vpl;

#define FOR(j, V) for(int j = 0; j < V; j++)
#define DOR(tt, X) for(int tt = X; tt >= 0; --tt)
#define pb push_back
#define all(X) X.begin(),X.end()
#define vt vector
#define sz(X) int(X.size())
// template insertion spaces


 
template <typename T> using oset = tree<T, null_type, std::less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(int test_case = 0)
{
    ll N, K, X;
    cin >> N >> K >> X;

    vl a(N);
    for(auto &A: a)
        cin >> A;

    priority_queue<ll, vl, greater<ll>> gaps;
    sort(a.begin(), a.end());

    ll ans = 1;

    for(int i = 0; i < N - 1; i++) {
        if(a[i + 1] - a[i] > X) {
            ++ans;
            gaps.push((a[i + 1] - a[i] - 1) / X);
        }
    }

    while(!gaps.empty()) {
        ll splits = gaps.top();
        gaps.pop();
        if(K - splits < 0)
            break;
        K -= splits;
        --ans;
    }
    cout << ans << "\n";

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    // precalc();
    int T = 1;
#ifdef runcase
    cin >> T;
#endif

    for(int nt = 0, i; nt < T; nt++) {
        solve(nt);
        ++i;
    }
}