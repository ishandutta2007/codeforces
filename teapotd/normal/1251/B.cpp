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
        int cnt[2] = {0, 0}, odd = 0;

        rep(i, 0, n) {
            string s; cin >> s;
            each(c, s) cnt[c=='1']++;
            odd += sz(s)%2;
        }

        while (odd > 0) {
            if (cnt[0] > cnt[1]) swap(cnt[0], cnt[1]);
            if (cnt[0]%2) cnt[0]--;
            else cnt[1]--;
            odd--;
        }

        bool ok = (cnt[0]%2 == 0 && cnt[1]%2 == 0);
        cout << (ok ? n : n-1) << '\n';
    }
}