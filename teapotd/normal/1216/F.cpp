#define _USE_MATH_DEFINES////////////////////////////////////////
#include<bits/stdc++.h>//////////////////////////////////////////
#define deb(...)/////////////////////////////////////////////////
#define DBP(...)/////////////////////////////////////////////////
#ifdef LOC///////////////////////////////////////////////////////
#include"debuglib.h"/////////////////////////////////////////////
#endif///////////////////////////////////////////////////////////
#define x first//////////////////////////////////////////////////
#define y second/////////////////////////////////////////////////
#define pb push_back/////////////////////////////////////////////
#define sz(x)int((x).size())/////////////////////////////////////
#define each(a,x)for(auto&a:(x))/////////////////////////////////
#define all(x)(x).begin(),(x).end()//////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)///////////////////////
using namespace std;using ll=long long;using Pii=pair<int,int>;//
using Vi=vector<int>;void run();int main(){cin.sync_with_stdio///
(0);cin.tie(0);cout<<fixed<<setprecision(18);run();return 0;}////
//-------------------------------------------------------------//

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }

struct MaxQueue {
    using T = ll;
    deque<T> Q, M;
    void push(T v) {
        while (!M.empty() && M.back() < v)
            M.pop_back();
        M.pb(v); Q.pb(v);
    }
    void pop() {
        if (M.front() == Q.front()) M.pop_front();
        Q.pop_front();
    }
    T max() const { return M.front(); }
};

void run() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    vector<ll> dp(n+1, 1e18);
    dp[0] = 0;

    deque<pair<ll, int>> que;
    MaxQueue que2;
    que2.push(0);

    rep(i, 0, n) {
        if (s[i] == '1') {
            ll alt = (i-k >= 0 ? -que2.max() : 0) + i+1;
            while (!que.empty() && que.back().x >= alt) {
                que.pop_back();
            }
            que.push_back({alt, i+k+1});
        }

        dp[i+1] = min(dp[i+1], dp[i]+i+1);

        while (!que.empty() && que.front().y <= i) {
            que.pop_front();
        }

        if (!que.empty()) {
            dp[i+1] = min(dp[i+1], que.front().x);
        }

        que2.push(-dp[i+1]);
        while (sz(que2.Q) > k+1) que2.pop();
    }

    cout << dp.back() << endl;
}