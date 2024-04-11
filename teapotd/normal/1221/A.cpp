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
        int n; cin >> n;
        multiset<int> elems;

        rep(i, 0, n) {
            int k; cin >> k;
            elems.insert(k);
        }

        while (*elems.begin() < 2048 && sz(elems) >= 2) {
            auto fs = elems.begin();
            auto sec = next(fs);

            if (*fs != *sec) {
                elems.erase(fs);
            } else {
                int kek = *fs * 2;
                elems.erase(fs);
                elems.erase(sec);
                elems.insert(kek);
            }
        }

        cout << (*elems.begin() == 2048 ? "YES" : "NO") << '\n';
    }
}