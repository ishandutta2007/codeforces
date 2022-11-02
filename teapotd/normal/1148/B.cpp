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

constexpr ll INF = 1e18;

void run() {
    int n, m, k;
    ll ta, tb;
    cin >> n >> m >> ta >> tb >> k;

    vector<ll> A(n), B(m);
    each(a, A) cin >> a;
    each(a, B) cin >> a;

    ll ans = 0;

    if (k >= n || k >= m) {
        ans = INF;
    } else {
        int j = 0;

        rep(i, 0, k+1) {
            ll atB = A[i] + ta;
            while (j < m && B[j] < atB) j++;

            int avail = j+k-i;

            if (avail >= m) {
                ans = -1;
                break;
            }

            ans = max(ans, B[avail] + tb);
        }
    }

    cout << (ans == INF ? -1 : ans) << endl;
}