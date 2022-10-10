#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy
int N, K, L;
int solve(vi data) {
    ld lo = 0, hi = L+1;
    int countZeros[N+1];
    countZeros[0] = 0;
    F0R(i, N) {
        countZeros[i+1] = countZeros[i];
        if (data[i] == 0) countZeros[i+1]++;
    }
    ld dp[N+1];
    F0R(iter, 40) {
        int used[N+1];
        int value[N+1];
        dp[0] = 0; used[0] = 0;
        value[0] = 0;
        ld cost = (lo+hi)/2;
        FOR(i, 1, N+1) {
            ld moveGain = -1 * cost;
            moveGain += countZeros[i] - countZeros[max(0, i-L)];
            ld def = dp[i-1]; //dp[i] = max increase
            if (dp[max(0, i-L)] + moveGain > def + 1e-10) {
                dp[i] = dp[max(0, i-L)] + moveGain;
                value[i] = value[max(0, i-L)] + min(i, L);
                used[i] = used[max(0, i-L)]+1;
            } else {
                dp[i] = dp[i-1];
                value[i] = value[i-1]; if (data[i-1] == 1) value[i]++;
                used[i] = used[i-1];
            }
        }

        if (used[N] > K) {
            lo = cost;
        } else {
            hi = cost;
        }

    }
    return (countZeros[N] - (long long)(dp[N] + (lo+hi)/2.0 * K + 0.5));
    cout << "BAD" << endl;
    return -1;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    cin >> N >> K >> L;
    string S; cin >> S;
    vi data1, data2;
    F0R(i, sz(S)) {
        if (S[i] >= 'A' && S[i] <= 'Z') {
            data1.pb(1); data2.pb(0);
        } else {
            data1.pb(0); data2.pb(1);
        }
    }

    cout << min(solve(data1), solve(data2)) << endl;
	
	return 0;
}

// read the question correctly (ll vs int)
// template by bqi343