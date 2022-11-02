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

template<class T> Vi kmp(const T& str) {
    Vi ps; ps.pb(-1);
    each(x, str) {
        int k = ps.back();
        while (k >= 0 && str[k] != x) k = ps[k];
        ps.pb(k+1);
    }
    return ps;
}

template<class T>
int match(const T& str, T pat) {
    int n = sz(pat), ret = 0;
    pat.pb(-1);
    pat.insert(pat.end(), all(str));
    Vi ps = kmp(pat);
    rep(i, 0, sz(ps)) {
        if (ps[i] == n) ret++;
    }
    return ret;
}

void run() {
    int n, m; cin >> n >> m;
    vector<Vi> inters(n);

    rep(i, 0, m) {
        int a, b; cin >> a >> b;
        a--; b--;
        if (a > b) swap(a, b);
        inters[a].pb(b-a);
        inters[b].pb(n-b+a);
    }

    Vi pat;

    each(vec, inters) {
        sort(all(vec));
        each(e, vec) pat.pb(e);
        pat.pb(0);
    }

    Vi dst = pat;
    dst.insert(dst.end(), all(pat));

    if (match(dst, pat) > 2) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}