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

int nQueries = 60;

int gcd(int a, int b) {
    while (b) {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int findBig() {
    int begin = 0, end = 1e9+1;

    while (begin+1 < end) {
        int a, m = (begin+end) / 2;
        cout << "> " << m-1 << endl;
        cin >> a;
        if (a) begin = m;
        else end = m;
        nQueries--;
    }

    return begin;
}

void run() {
    int n; cin >> n;
    int big = findBig();

    Vi toAsk(n);
    iota(all(toAsk), 1);
    shuffle(all(toAsk), mt19937_64(time(0)));
    if (sz(toAsk) > nQueries) toAsk.resize(nQueries);

    Vi elems = {big};
    each(i, toAsk) {
        cout << "? " << i << endl;
        int x; cin >> x;
        elems.pb(x);
    }

    sort(all(elems));
    int g = elems[1] - elems[0];

    rep(i, 2, sz(elems)) {
        g = gcd(g, elems[i]-elems[i-1]);
    }

    int small = big - g*(n-1);
    cout << "! " <<  small << ' ' << g << endl;
}