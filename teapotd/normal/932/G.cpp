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

constexpr int MOD = 1e9+7;
constexpr int ALPHA = 26;

struct PalTree {
    Vi txt;
    Vi len{0, -1};
    Vi link{1, 0};
    vector<array<int, ALPHA>> to{ {}, {} };
    int last{0};

    Vi diff{0, 0};
    Vi slink{0, 0};
    Vi series{0, 0};
    Vi ans{1};

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
            series.pb(0);
        }

        last = to[last][x];
        ans.pb(0);
        int& kek = ans.back();

        for (int i=last; len[i] > 0; i=slink[i]) {
            series[i] = ans[sz(ans) - len[slink[i]] - diff[i] - 1];

            if (diff[i] == diff[link[i]]) {
                series[i] += series[link[i]];
                if (series[i] >= MOD) series[i] -= MOD;
            }

            if (sz(txt) % 2 == 0) {
                kek += series[i];
                if (kek >= MOD) kek -= MOD;
            }
        }
    }
};

void run() {
    string s; cin >> s;
    PalTree tree;

    rep(i, 0, sz(s)/2) {
        tree.add(s[i]-'a');
        tree.add(s[sz(s)-i-1]-'a');
    }

    ll ans = tree.ans.back() % MOD;
    cout << ans << endl;
}