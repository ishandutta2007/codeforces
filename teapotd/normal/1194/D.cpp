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

bool brute(int n, int k) {
    vector<bool> win(n+1, 0);
    rep(i, 1, n+1) {
        win[i] = !win[i-1];
        win[i] = win[i] || (i >= 2 && !win[i-2]);
        win[i] = win[i] || (i >= k && !win[i-k]);
        //deb(n, k, i, win[i]);
    }
    return win.back();
}

bool fast(int n, int k) {
    if (k%3 == 0) {
        n %= k+1;
    }
    return n == k || n%3 != 0;
}

void run() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        bool ans = fast(n, k);
        cout << (ans ? "Alice\n" : "Bob\n");
    }
}