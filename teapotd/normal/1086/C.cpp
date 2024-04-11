#include<bits/stdc++.h>/////////////////////////////////////////
#define deb(...)////////////////////////////////////////////////
#define DBP(...)////////////////////////////////////////////////
#ifdef LOC//////////////////////////////////////////////////////
#include"debuglib.h"////////////////////////////////////////////
#endif//////////////////////////////////////////////////////////
#define x first/////////////////////////////////////////////////
#define y second////////////////////////////////////////////////
#define pb push_back////////////////////////////////////////////
#define sz(x)int((x).size())////////////////////////////////////
#define each(a,x)for(auto&a:(x))////////////////////////////////
#define all(x)(x).begin(),(x).end()/////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)//////////////////////
using namespace std;using ll=int64_t;using Pii=pair<int,int>;///
using Vi=vector<int>;void run();int main(){cin.sync_with_stdio//
(0);cin.tie(0);cout<<fixed<<setprecision(18);run();return 0;}///
//------------------------------------------------------------//

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }

int alpha, n;
string str, lower, upper;
Vi perm, inv;

bool mapPerm(int i, int j) {
    if (perm[i] || inv[j]) return false;
    perm[i] = j;
    inv[j] = i;
    return true;
}

void unmapPerm(int i) {
    assert(perm[i] && inv[perm[i]] == i);
    inv[perm[i]] = 0;
    perm[i] = 0;
}

bool solve(int i, bool hasLower, bool hasUpper) {
    if (i >= n) return true;

    char cur = str[i];
    char a = char(hasLower ? lower[i] : 'a'-1);
    char b = char(hasUpper ? upper[i] : 'a'+alpha);

    if (perm[cur]) {
        if (perm[cur] < a || perm[cur] > b) return false;
        return solve(i+1, hasLower && perm[cur] == a, hasUpper && perm[cur] == b);
    }

    if (a > b) return false;

    if (a == b) {
        if (mapPerm(cur, a)) {
            bool ok = solve(i+1, hasLower, hasUpper);
            if (!ok) unmapPerm(cur);
            return ok;
        }
        return false;
    }

    rep(chr, a+1, b) {
        if (mapPerm(cur, chr)) {
            bool ok = solve(i+1, 0, 0);
            if (!ok) unmapPerm(cur);
            return ok;
        }
    }

    if (hasLower && mapPerm(cur, a)) {
        bool ok = solve(i+1, 1, 0);
        if (ok) return 1;
        unmapPerm(cur);
    }

    if (hasUpper && mapPerm(cur, b)) {
        bool ok = solve(i+1, 0, 1);
        if (ok) return 1;
        unmapPerm(cur);
    }
    return 0;
}

void handle() {
    cin >> alpha >> str >> lower >> upper;
    perm.assign(256, 0);
    inv.assign(256, 0);
    n = sz(str);

    if (!solve(0, 1, 1)) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

    rep(i, 0, alpha) {
        if (!perm[i+'a']) {
            rep(j, 0, alpha) {
                if (mapPerm(i+'a', j+'a')) break;
            }
            assert(perm[i+'a']);
        }
        cout << char(perm[i+'a']);
    }
    cout << '\n';
}

void run() {
    int t; cin >> t;
    while (t--) handle();
}