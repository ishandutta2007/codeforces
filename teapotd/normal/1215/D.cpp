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

void answer(bool win) {
    cout << (win ? "Monocarp" : "Bicarp") << endl;
    exit(0);
}

void run() {
    int n; cin >> n;
    string s; cin >> s;

    int diff = 0, plus = 0, minus = 0;

    rep(i, 0, n/2) {
        if (s[i] != '?') {
            diff += s[i]-'0';
        } else {
            plus++;
        }
    }

    rep(i, n/2, n) {
        if (s[i] != '?') {
            diff -= s[i]-'0';
        } else {
            minus++;
        }
    }

    int m = min(plus, minus);
    plus -= m;
    minus -= m;

    if (diff < 0) {
        diff *= -1;
        swap(plus, minus);
    }

    if (plus > 0) {
        answer(1);
    } else if (minus > 0) {
        if (minus*9/2 != diff) {
            answer(1);
        } else {
            answer(0);
        }
    } else {
        answer(diff != 0);
    }
}