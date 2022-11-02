#define _USE_MATH_DEFINES
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

struct RMQ {
    using T = int;
    static constexpr T ID = INT_MIN;
    T f(T a, T b)  { return max(a, b); }
    vector<vector<T>> s;
    RMQ() {}
    RMQ(const vector<T>& vec) { init(vec); }
    void init(const vector<T>& vec) {
        s = {vec};
        for (int h = 1; h <= sz(vec); h *= 2) {
            s.emplace_back();
            auto& prev = s[sz(s)-2];
            rep(i, 0, sz(vec)-h*2+1) s.back().pb(f(prev[i], prev[i+h]));
        }
    }
    T query(int b, int e) {
        if (b >= e) return ID;
        int k = 31 - __builtin_clz(e-b);
        return f(s[k][b], s[k][e - (1<<k)]);
    }
};

int n;
Vi elems, pos;
RMQ rmq;
int ans = 0;

void solve(int b, int e) {
    if (b+1 >= e) return;
    int val = rmq.query(b, e);
    int mid = pos[val];

    if (mid-b < e-mid-1) {
        rep(i, b, mid) {
            int k = val-elems[i]-1;
            ans += (k >= 0 && k < n && pos[k] > mid && pos[k] < e);
        }
    } else {
        rep(i, mid+1, e) {
            int k = val-elems[i]-1;
            ans += (k >= 0 && k < n && pos[k] >= b && pos[k] < mid);
        }
    }

    solve(b, mid);
    solve(mid+1, e);
}

void run() {
    cin >> n;
    elems.resize(n);
    pos.resize(n);

    rep(i, 0, n) {
        cin >> elems[i];
        elems[i]--;
        pos[elems[i]] = i;
    }

    rmq.init(elems);
    solve(0, n);
    cout << ans << endl;
}