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

constexpr int N = 500000;
constexpr int SMALL = 750;
int A[N+1];
int sums[SMALL][SMALL];

void run() {
    int q; cin >> q;

    while (q--) {
        int t, x, y; cin >> t >> x >> y;
        if (t == 1) {
            A[x] += y;
            for (int i = 1; i < SMALL; i++) {
                sums[i][x%i] += y;
            }
        } else {
            int ans = 0;
            if (x < SMALL) {
                ans = sums[x][y];
            } else {
                for (int i = y; i <= N; i += x) {
                    ans += A[i];
                }
            }
            cout << ans << '\n';
        }
    }
}