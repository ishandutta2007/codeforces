#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<LL, 2>
typedef long long LL;
const LL P = 998244353;
const LL INF = 1e18;
const int N = 3e5 + 5;
mt19937 rng(time(0));

int n;
int h[N], b[N];
LL dp[N];

int main() {
    cin >> n;
    rep(i, 1, n) scanf("%d", h + i);
    rep(i, 1, n) scanf("%d", b + i);

    stack<ar2> stk;
    dp[0] = 0, dp[1] = b[1];
    stk.push({0, 1});
    set<ar2> st;
    st.insert({b[1], 1});
    rep(i, 2, n) {
        LL maxdp = dp[i - 1];
        while (stk.size() && h[i] < h[stk.top()[1]]) {
            ar2 x = stk.top();
            maxdp = max(maxdp, x[0]);
            st.erase({x[0] + b[x[1]], x[1]});
            stk.pop();
            //cerr << x[0] << " " << x[1] << endl;
        }
        stk.push({maxdp, i});
        st.insert({maxdp + b[i], i});

        auto iter = st.end();
        --iter;
        dp[i] = (*iter)[0];
        //cerr << i << " " << maxdp << " " << b[i] <<" "<<dp[i]<< endl;
    }
    cout << dp[n] << endl;
    return 0;
}