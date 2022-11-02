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

using Mat = array<array<ll, 3>, 3>;

Mat ident() {
    Mat ret;
    ret[0] = {1,0,0};
    ret[1] = {0,1,0};
    ret[2] = {0,0,1};
    return ret;
}

Mat extMat(ll d) {
    Mat ret;
    ret[0] = {1,1,d};
    ret[1] = {0,1,d};
    ret[2] = {0,0,1};
    return ret;
}

Mat mult(const Mat& a, const Mat& b) {
    Mat c;
    rep(i, 0, 3) rep(j, 0, 3) {
        c[i][j] = 0;
        rep(k, 0, 3) c[i][j] += a[i][k] * b[k][j];
    }
    return c;
}

Mat matPow(Mat a, ll e) {
    Mat t = ident();
    while (e) {
        if (e % 2) t = mult(t, a);
        e /= 2; a = mult(a, a);
    }
    return t;
}

ll fullLen(ll last) {
    Mat mat = ident();

    int digits = 1;
    ll ten = 10;

    while (ten <= last) {
        mat = mult(matPow(extMat(digits), ten-ten/10), mat);
        ten *= 10;
        digits++;
    }

    mat = mult(matPow(extMat(digits), last-ten/10+1), mat);
    return mat[0][2];
}

void solve() {
    ll k; cin >> k;
    k--;

    ll begin = 0, end = 1e9;

    while (begin+1 < end) {
        ll mid = (begin+end) / 2;
        if (fullLen(mid) <= k) {
            begin = mid;
        } else {
            end = mid;
        }
    }

    k -= fullLen(begin);

    int digits = 1;
    ll kek = 9;

    while (k >= kek*digits) {
        k -= kek*digits;
        kek *= 10;
        digits++;
    }

    ll num = kek/9 + k/digits;
    ll off = digits - k%digits - 1;
    while (off--) num /= 10;
    num %= 10;
    cout << num << '\n';
}

void run() {
    int q; cin >> q;
    while (q--) solve();
}