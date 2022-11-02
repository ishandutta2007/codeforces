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

Vi compressVec(vector<int*>& vec) {
    sort(all(vec),
        [](int* l, int* r) { return *l < *r; });
    Vi old;
    each(e, vec) {
        if (old.empty() || old.back() != *e)
            old.pb(*e);
        *e = sz(old)-1;
    }
    return old;
}

void run() {
    int n; cin >> n;
    Vi elems(n);
    each(e, elems) cin >> e;

    vector<int*> kek;
    each(e, elems) kek.pb(&e);
    compressVec(kek);

    Vi cnt(n);
    int ans = n+5;

    rep(b, 0, n) {
        int r = 0;
        cnt.assign(n, 0);
        each(e, elems) {
            if (cnt[e]++ == 1) r++;
        }

        if (r == 0) {
            ans = 0;
            break;
        }

        rep(e, b, n) {
            if (--cnt[elems[e]] == 1) {
                r--;
            }
            if (r == 0) {
                ans = min(ans, e-b+1);
                break;
            }
        }
    }

    cout << ans << endl;
}