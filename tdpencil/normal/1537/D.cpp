#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int MAXN = 1e6, M = 1e9+7, inf = -2e9;
#define runcase LOL
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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iterator>
using namespace __gnu_pbds;
 
template <typename T> using oset = tree<T, null_type, std::less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int dp[MAXN];
bool sieve[MAXN];


void precalc() {
    for(int i = 2; i < MAXN; i++) {
        if(sieve[i])
            continue;
        for(ll j = (ll)i  * i; j < MAXN; j += i) {
            sieve[j] = 1; 
        }
    }

    for(int i = 1; i < MAXN; i++) {
        if(i <= 3 || !sieve[i])
            continue;
        int x = i;
        int ans = 0;
        for(int j = 2; j * j <= x; j++) {
            if(x % j == 0) {
                ans = max(ans, dp[i - j] ^ 1);
                ans = max(ans, dp[i - (i / j)] ^ 1);
            }
        }
        dp[i] = ans;
    }




}
void solve(int test_case = 0)
{
    int N; cin >> N;
    if(N == 1) {
        cout << "Bob";
    }
    else if(__builtin_popcount(N) == 1) {
        if(__builtin_ctz(N) % 2) {
            cout << "Bob";
        } else {
            cout << "Alice";
        }
        
    } else {
        if(N%2) {
            cout << "Bob";
        } else {
            cout << "Alice";
        }
    }

    cout << "\n";
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    precalc();
    int T = 1;
#ifdef runcase
    cin >> T;
#endif

    for(int nt = 0, i; nt < T; nt++) {
        solve(nt);
        ++i;
    }
}