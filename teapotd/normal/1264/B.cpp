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
#define mp make_pair/////////////////////////////////////////////
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

void nope() {
    cout << "NO" << endl;
    exit(0);
}

vector<Vi> get(int zero, int one, int nZeroes, int nOnes) {
    vector<Vi> ret;
    ret.emplace_back();

    rep(i, 0, nZeroes) {
        ret.back().pb(one);
        ret.back().pb(zero);
    }
    ret.back().pb(one);

    nOnes -= nZeroes+1;

    rep(i, 0, nOnes) {
        ret.pb({one});
    }

    return ret;
}

void run() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (b < a-1) nope();
    if (c < d-1) nope();

    Vi ans;

    if (b == a-1) {
        if (c > 0 || d > 0) nope();
        rep(i, 0, b) {
            ans.pb(0);
            ans.pb(1);
        }
        ans.pb(0);
    } else if (c == d-1) {
        if (a > 0 || b > 0) nope();
        rep(i, 0, c) {
            ans.pb(3);
            ans.pb(2);
        }
        ans.pb(3);
    } else if (b == a) {
        if (c > d+1) nope();
        rep(i, 0, b) {
            ans.pb(0);
            ans.pb(1);
        }
        rep(i, 0, d) {
            ans.pb(2);
            ans.pb(3);
        }
        if (c == d+1) ans.pb(2);
    } else if (c == d) {
        if (b > a+1) nope();
        rep(i, 0, c) {
            ans.pb(3);
            ans.pb(2);
        }
        rep(i, 0, a) {
            ans.pb(1);
            ans.pb(0);
        }
        if (b == a+1) ans.pb(1);
    } else {
        assert(b >= a+1 && c >= d+1);

        vector<Vi> low = get(0, 1, a, b);
        vector<Vi> high = get(3, 2, d, c);

        if (sz(low) > sz(high)) {
            low.swap(high);
        }

        if (sz(high)-sz(low) > 1) {
            nope();
        }

        rep(i, 0, sz(low)) {
            each(k, high[i]) ans.pb(k);
            each(k, low[i]) ans.pb(k);
        }

        if (sz(high) > sz(low)) {
            each(k, high.back()) ans.pb(k);
        }
    }

    int cnt[4] = {};
    each(k, ans) cnt[k]++;

#ifdef LOC
    deb(ans);
    assert(sz(ans) == a+b+c+d);
    rep(i, 1, sz(ans)) {
        assert(abs(ans[i]-ans[i-1]) == 1);
    }

    assert(cnt[0] == a);
    assert(cnt[1] == b);
    assert(cnt[2] == c);
    assert(cnt[3] == d);
#endif

    if (sz(ans) != a+b+c+d) {
        nope();
    }

    rep(i, 1, sz(ans)) {
        if (abs(ans[i]-ans[i-1]) != 1) {
            nope();
        }
    }

    if (cnt[0] != a || cnt[1] != b || cnt[2] != c || cnt[3] != d) {
        nope();
    }

    cout << "YES\n";
    each(k, ans) cout << k << ' ';
    cout << endl;
}