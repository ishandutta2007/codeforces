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

constexpr int MAX_MEX = 128;
constexpr int MAX_P = 2e5+5;
Vi factor(MAX_P+1);

void sieve() {
    for (int i = 2; i*i <= MAX_P; i++) {
        if (!factor[i]) {
            for (int j = i*i; j <= MAX_P; j += i) {
                if (!factor[j]) factor[j] = i;
            }
        }
    }
    rep(i, 0, MAX_P+1) if (!factor[i]) factor[i] = i;
}

void run() {
    int n, forbidden;
    cin >> n >> forbidden;

    bitset<MAX_P+1> good;
    sieve();

    rep(i, 2, MAX_P+1) if (i != forbidden) {
        int a = i / factor[i];
        good.set(i, factor[a] == a);
    }

    vector<bitset<MAX_P+1>> reach(MAX_MEX);
    Vi grundy;

    rep(i, 0, MAX_P+1) {
        rep(j, 0, MAX_MEX) {
            if (!reach[j][i]) {
                grundy.pb(j);
                break;
            }
        }

        assert(sz(grundy) == i+1);
        reach[grundy.back()] |= good << i;
    }

    int ans = 0;

    rep(i, 0, n) {
        int b, w, r; cin >> b >> w >> r;
        ans ^= grundy[w-b-1];
        ans ^= grundy[r-w-1];
    }

    if (ans) {
        cout << "Alice\nBob\n";
    } else {
        cout << "Bob\nAlice\n";
    }
}