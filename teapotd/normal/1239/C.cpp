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

void run() {
    int n, p; cin >> n >> p;
    Vi times(n);
    each(t, times) cin >> t;

    Vi order(n);
    iota(all(order), 0);
    stable_sort(all(order), [&](int l, int r) { return times[l] < times[r]; });

    ll queTime = -1e9, curTime = -1e9;
    priority_queue<ll, vector<ll>, greater<ll>> timeQue;
    queue<pair<int, ll>> que; // index, time
    set<int> seats, want;
    int j = 0;
    vector<ll> ans(n, -1);

    each(t, times) timeQue.push(t);

    while (true) {
        if (j < n && times[order[j]] <= curTime) {
            want.insert(order[j++]);
            continue;
        }

        if (!que.empty()) {
            auto top = que.front();
            if (top.y <= curTime) {
                que.pop();
                seats.erase(top.x);
                continue;
            }
        }

        if (!want.empty()) {
            int top = *want.begin();
            if (seats.empty() || *seats.begin() > top) {
                want.erase(want.begin());
                seats.insert(top);
                ans[top] = queTime = max(queTime+p, curTime+p);
                que.push({top, queTime});
                timeQue.push(queTime);
                continue;
            }
        }

        if (timeQue.empty()) break;
        curTime = timeQue.top();
        timeQue.pop();
    }

    each(a, ans) cout << a << ' ';
    cout << '\n';
}