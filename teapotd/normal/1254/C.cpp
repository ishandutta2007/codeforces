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

ll area(int i, int j, int k) {
    cout << "1 " << i+1 << ' ' << j+1 << ' ' << k+1 << endl;
    ll ret; cin >> ret;
    return ret;
}

int sign(int i, int j, int k) {
    cout << "2 " << i+1 << ' ' << j+1 << ' ' << k+1 << endl;
    int ret; cin >> ret;
    return ret;
}

Vi bitonic(vector<pair<ll, int>>& elems) {
    if (elems.empty()) return {};
    Vi before, after;
    sort(all(elems));

    rep(i, 0, sz(elems)-1) {
        int s = sign(0, elems.back().y, elems[i].y);
        (s == 1 ? after : before).pb(elems[i].y);
    }

    before.pb(elems.back().y);
    reverse(all(after));
    before.insert(before.end(), all(after));
    return before;
}

void run() {
    int n; cin >> n;

    vector<pair<ll, int>> before, after;

    rep(i, 2, n) {
        ll a = area(0, 1, i);
        int s = sign(0, 1, i);
        (s == 1 ? after : before).pb({a, i});
    }

    Vi ans1 = bitonic(before);
    Vi ans2 = bitonic(after);

    cout << "0 1 ";
    each(k, ans1) cout << k+1 << ' ';
    cout << "2 ";
    each(k, ans2) cout << k+1 << ' ';
    cout << endl;
}