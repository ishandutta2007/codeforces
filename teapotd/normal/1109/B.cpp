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

string str;

void check(string alt, int k) {
    if (alt == str || sz(alt) != sz(str)) return;
    rep(i, 0, sz(str)) if (alt[i] != alt.rbegin()[i]) return;
    cout << k << endl;
    exit(0);
}

void run() {
    cin >> str;
    int n = sz(str);
    rep(i, 1, n) check(str.substr(i) + str.substr(0, i), 1);
    rep(i, 1, n/2+1) check(str.substr(n-i) + str.substr(i, n-i*2) + str.substr(0, i), 2);
    cout << "Impossible" << endl;
}