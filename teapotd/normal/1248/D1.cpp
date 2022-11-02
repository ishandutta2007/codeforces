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

int score(const string& t) {
    int cur = 0, sm = 100, cnt = 0;
    each(c, t) {
        cur += (c == '(' ? 1 : -1);
        if (cur < sm) {
            sm = cur;
            cnt = 1;
        } else if (cur == sm) {
            cnt++;
        }
    }
    if (cur != 0) return 0;
    return cnt;
}

void run() {
    int n; cin >> n;
    string s; cin >> s;

    int best = score(s);
    int bestL = 0, bestR = 0;

    rep(i, 0, n) rep(j, i+1, n) {
        swap(s[i], s[j]);
        int alt = score(s);
        swap(s[i], s[j]);

        if (alt > best) {
            best = alt;
            bestL = i;
            bestR = j;
        }
    }

    cout << best << '\n';
    cout << bestL+1 << ' ' << bestR+1 << '\n';
}