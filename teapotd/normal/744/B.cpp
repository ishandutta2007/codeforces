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

int n;

#ifdef LOC

vector<Vi> _hidden;

void init() {
    n = 3;
    _hidden = { {0,3,2}, {5,0,7}, {4,8,0} };
}

void answer(const Vi& ans) {
    Vi expected(n, INT_MAX);
    rep(i, 0, n) rep(j, 0, n) if (i != j) expected[i] = min(expected[i], _hidden[i][j]);
    deb(ans, expected);
    deb(ans == expected);
    exit(0);
}

Vi ask(const Vi& cols) {
    assert(!cols.empty());
    Vi ans(n, INT_MAX);
    rep(i, 0, n) each(j, cols) ans[i] = min(ans[i], _hidden[i][j]);
    return ans;
}

#else

void init() {
    cin >> n;
}

void answer(const Vi& ans) {
    cout << "-1\n";
    each(a, ans) cout << a << ' ';
    cout << endl;
    exit(0);
}

Vi ask(const Vi& cols) {
    cout << sz(cols) << '\n';
    each(c, cols) cout << c+1 << ' ';
    cout << endl;
    Vi ans(n);
    each(a, ans) cin >> a;
    return ans;
}

#endif

Vi doAsk(const Vi& cols) {
    if (cols.empty()) {
        return Vi(n, INT_MAX);
    }
    return ask(cols);
}

void run() {
    init();

    Vi lookup[10][2];

    rep(b, 0, 10) rep(v, 0, 2) {
        Vi query;
        rep(i, 0, n) if (((i >> b) & 1) == v) {
            query.pb(i);
        }
        lookup[b][v] = doAsk(query);
    }

    Vi ans(n, INT_MAX);

    rep(i, 0, n) {
        rep(b, 0, 10) {
            ans[i] = min(ans[i], lookup[b][(~i>>b)&1][i]);
        }
    }

    answer(ans);
}