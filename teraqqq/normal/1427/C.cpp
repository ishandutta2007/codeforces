#include <bits/stdc++.h>

#define F first
#define S second

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rsz resize

#define pq_min(T) priority_queue<T, vector<T>, greater<T>>
#define pq_max(T) priority_queue<T, vector<T>, less<T>>

using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
using vpi = vector<pi>;
using ld = long double;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return b > a ? a = b, true : false; }


const int INF = 1e9;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int r, n; cin >> r >> n;
    vi dp(n+1, -INF), x(n+1), y(n+1), t(n+1);
    x[0] = y[0] = 1; dp[0] = t[0] = 0; int res = 0;
    for(int i = 1, j = 0, u = -INF; i <= n; ++i) {
        cin >> t[i] >> x[i] >> y[i];
        while(t[j] + 2*r <= t[i]) ckmax(u, dp[j++]);
        dp[i] = u + 1;
        for(int r = j; r < i; ++r)
            if(abs(x[i]-x[r]) + abs(y[i]-y[r]) <= t[i] - t[r])
                ckmax(dp[i], dp[r]+1);

        //cout << dp[i] << endl;
        ckmax(res, dp[i]);
    }
    cout << res << '\n';
}