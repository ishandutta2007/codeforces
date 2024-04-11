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
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        ll s; cin >> s;
        vector<Pii> elems(n);
        each(e, elems) cin >> e.x >> e.y;

        ll begin = 0, end = min(s+1, ll(1e9+5));
        sort(all(elems));
        reverse(all(elems));

        while (begin+1 < end) {
            ll mid = (begin+end) / 2;

            int over = 0;
            ll spent = 0;

            each(e, elems) {
                if (over < (n+1)/2 && e.y >= mid) {
                    spent += max(ll(e.x), mid);
                    over++;
                } else {
                    spent += e.x;
                }
            }

            if (over != (n+1)/2 || spent > s) {
                end = mid;
            } else {
                begin = mid;
            }
        }

        cout << begin << '\n';
    }
}