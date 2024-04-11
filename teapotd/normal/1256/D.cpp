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

void run() {
    int q; cin >> q;

    while (q--) {
        int n;
        ll k;
        string s;
        cin >> n >> k >> s;

        int nZeroes = 0, nOnes = 0;
        bool ok = 1;

        rep(i, 0, n) {
            if (s[i] == '0') {
                int moves = i-nZeroes;

                if (moves < k) {
                    nZeroes++;
                    k -= moves;
                } else {
                    rep(j, 0, nZeroes) cout << '0';
                    rep(j, 0, nOnes-k) cout << '1';
                    cout << '0';
                    rep(j, 0, k) cout << '1';
                    rep(j, i+1, n) cout << s[j];
                    cout << '\n';
                    ok = 0;
                    break;
                }
            } else {
                nOnes++;
            }
        }

        if (ok) {
            rep(i, 0, nZeroes) cout << '0';
            rep(i, 0, nOnes) cout << '1';
            cout << '\n';
        }
    }
}