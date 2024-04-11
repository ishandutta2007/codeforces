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
    int n; cin >> n;
    string s; cin >> s;

    int tmp = 0, sm = 0, smPos = 0;

    rep(i, 0, n) {
        tmp += (s[i] == '(' ? 1 : -1);
        if (tmp < sm) {
            sm = tmp;
            smPos = i+1;
        }
    }

    if (tmp != 0) {
        cout << "0\n1 1\n";
        return;
    }

    rotate(s.begin(), s.begin()+smPos, s.end());

    Vi prefs = {0};
    tmp = 0;

    rep(i, 0, n) {
        tmp += (s[i] == '(' ? 1 : -1);
        prefs.pb(tmp);
    }

    Vi cnt[3];
    rep(i, 0, 3) cnt[i].pb(0);
    each(p, prefs) rep(i, 0, 3) cnt[i].pb(cnt[i].back() + (p == i));

    int best = cnt[0].back()-1;
    int bestL = 0, bestR = 0;
    int last = 0;

    rep(i, 1, n+1) if (prefs[i] == 0) {
        int alt = cnt[1][i] - cnt[1][last];
        if (alt > best) {
            best = alt;
            bestL = last;
            bestR = i-1;
        }
        last = i;
    }

    last = 1;
    rep(i, 2, n+1) if (prefs[i] == 1) {
        if (prefs[i-1] != 0) {
            int alt = cnt[0].back() + cnt[2][i] - cnt[2][last] - 1;
            if (alt > best) {
                best = alt;
                bestL = last;
                bestR = i-1;
            }
        }
        last = i;
    }

    bestL = (bestL+smPos) % n;
    bestR = (bestR+smPos) % n;

    cout << best << '\n';
    cout << bestL+1 << ' ' << bestR+1 << '\n';
}