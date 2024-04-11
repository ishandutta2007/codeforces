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

Vi getCnt(const string& s) {
    Vi cnt(26);
    each(c, s) cnt[c-'a']++;
    return cnt;
}

ll countInversions(Vi perm, int k) {
    ll ret = 0, cont = 1;
    Vi odd;
    while (cont) {
        odd.assign(k+1, 0);
        cont = 0;
        rep(i, 0, sz(perm)) {
            if (perm[i] % 2) odd[perm[i]]++;
            else ret += odd[perm[i]+1];
            cont += perm[i] /= 2;
        }
    }
    return ret;
}

ll countInversions(const string& s) {
    Vi tmp(sz(s));
    rep(i, 0, sz(s)) tmp[i] = s[i]-'a';
    return countInversions(tmp, 26);
}

bool solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    Vi cs = getCnt(s), ct = getCnt(t);

    if (cs != ct) {
        return 0;
    }

    each(i, cs) {
        if (i >= 2) {
            return 1;
        }
    }

    ll a = countInversions(s);
    ll b = countInversions(t);
    return a%2 == b%2;
}

void run() {
    int q; cin >> q;

    while (q--) {
        cout << (solve() ? "YES\n" : "NO\n");
    }
}