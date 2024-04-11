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
// testing

constexpr int MAX_N = 7001;

vector<bitset<MAX_N>> singles, invSingles, states;

void computeMasks() {
    singles.resize(MAX_N);
    invSingles.resize(MAX_N);

    rep(i, 1, MAX_N) {
        for (int j = i; j < MAX_N; j += i) {
            singles[j].set(i);
        }
    }

    for (int i = MAX_N-1; i > 0; i--) {
        invSingles[i].set(i);
        for (int j = i*2; j < MAX_N; j += i) {
            invSingles[i] ^= invSingles[j];
        }
    }
}

void run() {
    computeMasks();
    int n, q; cin >> n >> q;
    states.resize(n);

    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int x, v; cin >> x >> v;
            states[x-1] = singles[v];
        } else if (t == 2) {
            int x, y, z; cin >> x >> y >> z;
            states[x-1] = states[y-1] ^ states[z-1];
        } else if (t == 3) {
            int x, y, z; cin >> x >> y >> z;
            states[x-1] = states[y-1] & states[z-1];
        } else if (t == 4) {
            int x, v; cin >> x >> v;
            cout << ((states[x-1] & invSingles[v]).count() % 2);
        }
    }

    cout << endl;
}