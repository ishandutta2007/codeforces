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

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    string wanted;
    rep(i, 0, n/2-k+1) wanted.pb('(');
    rep(i, 0, n/2-k+1) wanted.pb(')');
    rep(i, 1, k) wanted += "()";

    assert(sz(wanted) == n);
    deb(s, wanted);

    int nextOpen = 0;
    int nextClose = 0;
    vector<Pii> ans;

    auto mv = [&](int i, int j) {
        ans.pb({i+1, j+1});
        if (j-i+1 > 3) ans.pb({i+2, j});
        deb(i, j, s, wanted);
        swap(s[i], s[j]);
    };

    rep(i, 0, n) {
        if (s[i] == wanted[i]) continue;

        while (nextOpen < n) {
            if (s[nextOpen] != wanted[nextOpen] && s[nextOpen] == '(') {
                break;
            }
            nextOpen++;
        }

        while (nextClose < n) {
            if (s[nextClose] != wanted[nextClose] && s[nextClose] == ')') {
                break;
            }
            nextClose++;
        }

        if (s[i] == '(') {
            mv(i, nextClose);
        } else {
            mv(i, nextOpen);
        }
    }

    cout << sz(ans) << '\n';
    each(a, ans) cout << a.x << ' ' << a.y << '\n';

    deb(wanted, s);
    assert(wanted == s);
}

void run() {
    int t; cin >> t;
    while (t--) solve();
}