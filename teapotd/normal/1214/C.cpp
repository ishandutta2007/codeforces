#define _USE_MATH_DEFINES
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

void ans(bool b) {
    cout << (b ? "Yes" : "No") << endl;
    exit(0);
}

void check(string seq) {
    int s = 0;
    each(c, seq) {
        s += (c == '(' ? 1 : -1);
        if (s < 0) return;
    }
    if (s == 0) ans(1);
}

void run() {
    int n; cin >> n;
    string seq; cin >> seq;
    check(seq);

    int close = n+5, open = -1;

    rep(i, 0, n) {
        if (seq[i] == '(') {
            open = max(open, i);
        } else {
            close = min(close, i);
        }
    }

    if (close < n) {
        string alt = seq.substr(0, close) + seq.substr(close+1) + ')';
        check(alt);
    }

    if (open >= 0) {
        string alt = "(" + seq.substr(0, open) + seq.substr(open+1);
        check(alt);
    }

    ans(0);
}