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

void nope() {
    cout << ":(" << endl;
    exit(0);
}

void run() {
    int n; cin >> n;
    string s; cin >> s;

    int sum = 0, quot = 0;

    each(c, s) {
        if (c == '(') sum++;
        else if (c == ')') sum--;
        else quot++;
    }

    if ((quot-sum) % 2) {
        nope();
    }

    int open = (quot-sum) / 2;
    int close = quot-open;

    if (open < 0 || close < 0) {
        nope();
    }

    int cnt = 0;

    rep(i, 0, n) {
        char& c = s[i];

        if (c == '?') {
            c = (open > 0 ? '(' : ')');
            open--;
        }

        cnt += (c == '(' ? 1 : -1);
        if (i+1 < n && cnt <= 0) nope();
    }

    if (cnt != 0) {
        nope();
    }
    cout << s << endl;
}