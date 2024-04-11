#define _USE_MATH_DEFINES/////////////////////////////////////////////////////
#include <bits/stdc++.h>//////////////////////////////////////////////////////
#ifdef LOC////////////////////////////////////////////////////////////////////
#include "debuglib.h"/////////////////////////////////////////////////////////
#else/////////////////////////////////////////////////////////////////////////
#define deb(...)//////////////////////////////////////////////////////////////
#define DBP(...)//////////////////////////////////////////////////////////////
#endif////////////////////////////////////////////////////////////////////////
#define x first///////////////////////////////////////////////////////////////
#define y second//////////////////////////////////////////////////////////////
#define mp make_pair//////////////////////////////////////////////////////////
#define pb push_back//////////////////////////////////////////////////////////
#define sz(x)int((x).size())//////////////////////////////////////////////////
#define each(a,x)for(auto&a:(x))///////////////// by teapotd /////////////////
#define all(x)(x).begin(),(x).end()///////////////////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)////////////////////////////////////
using namespace std;using namespace rel_ops;using ll=int64_t;using Pii=pair///
<int,int>;using ull=uint64_t;using Vi=vector<int>;void run();int main(){cin.//
sync_with_stdio(0);cin.tie(0);cout<<fixed<<setprecision(10);run();return 0;}//
//--------------------------------------------------------------------------//

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }
int cmp(double a, double b, double eps=1e-9) { return (a>b+eps) - (a+eps<b); }

template<class T> Vi kmp(const T& str) {
    Vi ps; ps.pb(-1);
    each(x, str) {
        int k = ps.back();
        while (k >= 0 && str[k] != x) k = ps[k];
        ps.pb(k+1);
    }
    return ps;
}

template<class T>
int match(const T& str, T pat) {
    int n = sz(pat);
    pat.pb(0);
    pat.insert(pat.end(), all(str));
    Vi ps = kmp(pat);
    rep(i, 0, sz(ps)) {
        if (ps[i] == n) return i-2*n-1;
    }
    return -1;
}

Pii diff(string& a, string& b) {
    int from = -1, to = -1;

    rep(i, 0, sz(a)) {
        if (a[i] != b[i]) {
            if (from < 0) from = i;
            to = i+1;
        }
    }
    return {from, to};
}

void nope() {
    cout << "NO\n";
    exit(0);
}

void run() {
    int n; cin >> n;
    vector<string> from(n), to(n);

    each(s, from) cin >> s;
    each(t, to) cin >> t;

    rep(i, 0, n) if (diff(from[i], to[i]).x != -1) {
        swap(from[i], from[0]);
        swap(to[i], to[0]);
        break;
    }

    vector<Pii> diffs(n);
    rep(i, 0, n) diffs[i] = diff(from[i], to[i]);

    while (diffs[0].x > 0) {
        bool ok = 1;
        char s = from[0][diffs[0].x-1], t = to[0][diffs[0].x-1];

        rep(i, 1, n) if (diffs[i].x != -1) {
            if (diffs[i].x == 0 || from[i][diffs[i].x-1] != s || to[i][diffs[i].x-1] != t) {
                ok = 0;
                break;
            }
        }

        if (!ok) break;
        rep(i, 0, n) if (diffs[i].x != -1) diffs[i].x--;
    }

    while (diffs[0].y < sz(from[0])) {
        bool ok = 1;
        char s = from[0][diffs[0].y], t = to[0][diffs[0].y];

        rep(i, 1, n) if (diffs[i].x != -1) {
            if (diffs[i].y == sz(from[i]) || from[i][diffs[i].y] != s || to[i][diffs[i].y] != t) {
                ok = 0;
                break;
            }
        }

        if (!ok) break;
        rep(i, 0, n) if (diffs[i].x != -1) diffs[i].y++;
    }

    string pat = from[0].substr(diffs[0].x, diffs[0].y-diffs[0].x);
    string repl = to[0].substr(diffs[0].x, diffs[0].y-diffs[0].x);

    rep(i, 0, n) {
        if (match(from[i], pat) != diffs[i].x) {
            nope();
        }
    }

    cout << "YES\n";
    cout << pat << '\n';
    cout << repl << '\n';
}