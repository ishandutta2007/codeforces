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

using State = pair<int, Pii>;
constexpr int ALPHA = 26;
constexpr int INF = 1e9;

struct PalTree {
    Vi txt, len{0, -1}, link{1, 0};
    vector<array<int, ALPHA>> to{ {}, {} };
    int last{0};

    Vi diff{0, 0}, slink{0, 0};
    vector<State> series{mp(0, mp(0, 0)), mp(0, mp(0, 0))}, ans{mp(0, mp(0, 0))};

    State choose(State a, State b) {
        if (a.x <= b.x) return a;
        return b;
    }

    int ext(int i) {
        while (len[i]+2 > sz(txt) || txt[sz(txt)-len[i]-2] != txt.back())
            i = link[i];
        return i;
    }

    void add(int x) {
        txt.pb(x);
        last = ext(last);

        if (!to[last][x]) {
            len.pb(len[last]+2);
            link.pb(to[ext(link[last])][x]);
            to[last][x] = sz(to);
            to.emplace_back();

            diff.pb(len.back() - len[link.back()]);
            slink.pb(diff.back() == diff[link.back()] ? slink[link.back()] : link.back());
            series.pb({ INF, {0, 0} });
        }
        last = to[last][x];

        ans.pb({ INF, {0, 0} });

        for (int i=last; len[i] > 0; i=slink[i]) {
            series[i] = ans[sz(ans) - len[slink[i]] - diff[i] - 1];
            if (diff[i] == diff[link[i]])
                series[i] = choose(series[i], series[link[i]]);

            if (sz(txt)%2 == 0) {
                auto alt = series[i];
                alt.x++;
                alt.y.x = alt.y.y;
                alt.y.y = sz(txt);
                ans.back() = choose(ans.back(), alt);
            }
        }

        if (sz(txt)%2 == 0 && txt[sz(txt)-2] == x) {
            auto alt = ans[sz(ans)-3];
            alt.y.x = alt.y.y;
            alt.y.y = sz(txt);
            ans.back() = choose(ans.back(), alt);
        }
    }
};

void run() {
    cin.sync_with_stdio(0); cin.tie(0);
    string A, B; cin >> A >> B;

    PalTree tree;
    rep(i, 0, sz(A)) {
        tree.add(A[i]-'a');
        tree.add(B[i]-'a');
    }

    if (tree.ans.back().x == INF) {
        cout << -1 << endl;
        return;
    }

    cout << tree.ans.back().x << '\n';

    for (State s = tree.ans.back(); s.x > 0; s = tree.ans[s.y.x]) {
        if (s.y.y-s.y.x > 2) {
            int a = s.y.x/2, b = s.y.y/2;
            cout << a+1 << ' ' << b << '\n';
        }
    }
}