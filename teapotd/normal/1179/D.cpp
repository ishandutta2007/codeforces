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

constexpr ll INF = 2e18;

struct Hull {
    using T = ll; // Or change to double

    struct Line {
        T a, b, end;
        T intersect(const Line& r) const {
            // Version for double:
            //if (r.a-a < EPS) return b>r.b?INF:-INF;
            //return (b-r.b) / (r.a-a);
            if (a==r.a) return b > r.b ? INF : -INF;
            ll u = b-r.b, d = r.a-a;
            return u/d + ((u^d) >= 0 || !(u%d));
        }
    };

    vector<Line> S;
    Hull() { S.pb({ 0, -INF, INF }); }

    // Insert f(x) = ax+b; time: amortized O(1)
    void push(T a, T b) {
        Line l{a, b, INF};
        while (true) {
            T e = S.back().end=S.back().intersect(l);
            if (sz(S) < 2 || S[sz(S)-2].end < e)
                break;
            S.pop_back();
        }
        S.pb(l);
    }

    // Query max(f(x) for each f): time: O(lg n)
    T query(T x) {
        auto t = *upper_bound(all(S), x,
            [](int l, const Line& r) {
                return l < r.end;
            });
        return t.a*x + t.b;
    }
};

int n;
vector<Vi> G;
Vi sub;
vector<ll> dp;
ll best = 0;

ll ch2(ll k) {
    return k*(k-1) / 2;
}

void dfs(int v, int p) {
    sub[v] = 1;
    each(e, G[v]) if (e != p) {
        dfs(e, v);
        sub[v] += sub[e];
    }

    Hull hull;
    dp[v] = ch2(sub[v]);
    bool f = 0;

    sort(all(G[v]), [&](int l, int r) {
        return sub[l] > sub[r];
    });

    each(e, G[v]) if (e != p) {
        ll alt = dp[e] + ch2(sub[v]-sub[e]);
        dp[v] = min(dp[v], alt);

        ll kek = dp[e] + ch2(n-sub[e]);
        best = min(best, kek);

        ll d = n - sub[e];
        ll x = -2*d+1;
        ll y = d*(d-1) + dp[e]*2;

        if (f) {
            ll k = -hull.query(sub[e]);
            k += ll(sub[e]) * sub[e];
            k /= 2;
            k += dp[e];
            best = min(best, k);
        } else {
            f = 1;
        }

        hull.push(-x, -y);
    }
}

void run() {
    cin >> n;
    G.resize(n);
    sub.resize(n);
    dp.resize(n);

    rep(i, 1, n) {
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    best = ch2(n);
    dfs(0, -1);

    ll ans = ch2(n)*2 - best;
    cout << ans << '\n';
}