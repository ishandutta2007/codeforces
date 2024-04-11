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

string partial;
int ones, zeroes;

template<class T> Vi kmp(const T& str) {
    Vi ps; ps.pb(-1);
    each(x, str) {
        int k = ps.back();
        while (k >= 0 && str[k] != x) k = ps[k];
        ps.pb(k+1);
    }
    return ps;
}

bool place(const string& s) {
    int a = 0, b = 0;
    each(c, s) {
        if (c == '1') a++;
        else b++;
    }

    if (a > ones || b > zeroes) return false;
    ones -= a;
    zeroes -= b;
    partial += s;
    return true;
}

void run() {
    string pat, tmp;
    cin >> tmp >> pat;

    if (sz(tmp) < sz(pat)) {
        cout << tmp << '\n';
        return;
    }

    each(c, tmp) {
        if (c == '1') ones++;
        else zeroes++;
    }

    int nest = kmp(pat).back();
    string suf = pat.substr(nest);

    int ans = 0;

    if (place(pat)) {
        ans++;
        while (place(suf)) ans++;
    }

    while (zeroes--) partial.pb('0');
    while (ones--) partial.pb('1');

    deb(ans);
    cout << partial << '\n';
}