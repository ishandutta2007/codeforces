#include<bits/stdc++.h>
using namespace std;

// Shortcut

#define int long long
#define endl '\n'
#define eb emplace_back
#define pb push_back
#define pob pop_back
#define mp make_pair
#define upb upper_bound
#define lwb lower_bound
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define Ford(i, r, l) for (int i = r; i > l; i--)
#define FordE(i, r, l) for (int i = r; i >= l; i--)
#define Fora(i, a) for (auto i : a)

// I/O & Debug

#define PrintV(a) for (int iiii = 0; iiii < a.size(); iiii++) cout << a[iiii] << ' ';
#define PrintVl(a) for (int iiii = 0; iiii < a.size(); iiii++) cout << a[iiii] << endl;
#define PrintA(a, n) for (int iiii = 0; iiii < n; iiii++) cout << a[iiii] << ' ';
#define PrintAl(a, n) for (int iiii = 0; iiii < n; iiii++) cout << a[iiii] << endl;
#define Ptest(x) return cout << x, 0;
#define gl(s) getline(cin, s);
#define setpre(x) fixed << setprecision(x)
/*
#define debug(args...){ string _sDEB = #args; replace(_sDEB.begin(), _sDEB.end(), ',', ' '); stringstream _ssDEB(_sDEB); istream_iterator<string> _itDEB(_ssDEB); DEB(_itDEB, args); }
void DEB(istream_iterator<string> it) {}
template<typename T, typename... Args>
void DEB(istream_iterator<string> it, T a, Args... args){
    cout << *it << " = " << a << endl;
    DEB(++it, args...);
}
*/

// Functions

//#define isvowel(a) (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
#define bend(a) a.begin(), a.end()
#define rbend(a) a.rbegin(), a.rend()
#define mset(a) memset(a, 0, sizeof(a));
//mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());

// Data Structure

#define pque priority_queue
#define mts multiset
typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <ld> vld;
typedef vector <string> vs;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ld, ld> pdd;
typedef vector <vi > vvi;
typedef vector <vll > vvll;
typedef vector <pii > vpii;
typedef vector <pll > vpll;

const int N = 1e5 + 5, mod = 1e9 + 7, inf = 1e6 + 7;
ld ldinf = 1e6 + 7.0, ldinf5 = 5.0 + ldinf;

int n, p, q;
map <pii, int> mpp;
vpii a;

int ccw(pii O, pii A, pii B){
	int val = 1ll * (A.fi - O.fi) * (B.se - O.se) - 1ll * (A.se - O.se) * (B.fi - O.fi);
	if (val == 0) return 0;
	if (val > 0) return 1;
	return 2;
}

int cross(pii p, pii q) {return p.fi * q.se - p.se * q.fi;}
int area2(pii a, pii b, pii c) {return cross(a, b) + cross(b, c) + cross(c, a);}

vpii convexhull(vpii a){
    if (a.size() <= 3){
        return a;
    }
    vpii hull = a; sort(bend(hull));
    hull.erase(unique(bend(hull)), hull.end());
    vpii up, dn;
    For(i, 0, hull.size()){
        while (up.size() > 1 && area2(up[up.size() - 2], up.back(), hull[i]) >= 0) up.pob();
        while (dn.size() > 1 && area2(dn[dn.size() - 2], dn.back(), hull[i]) <= 0) dn.pob();
        up.pb(hull[i]);
        dn.pb(hull[i]);
    }
    hull = dn;
    FordE(i, up.size() - 2, 1){
        hull.pb(up[i]);
    }
    return hull;
}

bool liesonsegment(pii p, pii q, pii r){ 
    if (q.fi <= max(p.fi, r.fi) && q.fi >= min(p.fi, r.fi) && q.se <= max(p.se, r.se) && q.se >= min(p.se, r.se)){
        return true; 
    }
    return false;
}

bool ckintersect(pii p1, pii q1, pii p2, pii q2){
    int o1 = ccw(p1, q1, p2);
    int o2 = ccw(p1, q1, q2);
    int o3 = ccw(p2, q2, p1);
    int o4 = ccw(p2, q2, q1);
    if (o1 != o2 && o3 != o4){
        return true;
    }
    if (o1 == 0 && liesonsegment(p1, p2, q1)){
        return true;
    }
    if (o2 == 0 && liesonsegment(p1, q2, q1)){
        return true;
    }
    if (o3 == 0 && liesonsegment(p2, p1, q2)){
        return true;
    }
    if (o4 == 0 && liesonsegment(p2, q1, q2)){
        return true;
    }
    return false;
}

pdd pointintersect(pdd A, pdd B, pdd C, pdd D){
    if (A == B) return A;
    if (C == D) return C;
    ld a1 = B.se - A.se;
    ld b1 = A.fi - B.fi;
    ld c1 = a1 * A.fi + b1 * A.se;
    ld a2 = D.se - C.se;
    ld b2 = C.fi - D.fi;
    ld c2 = a2 * C.fi + b2 * C.se;
    ld dtm = a1 * b2 - a2 * b1;
    if (dtm == 0){
        return {ldinf, ldinf};
    }
    else{
        ld x = (b2 * c1 - b1 * c2) / dtm;
        ld y = (a1 * c2 - a2 * c1) / dtm;
        return {x, y};
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> p >> q;
    int tmptmptmp = max(inf / p, inf / q);
    int pp = tmptmptmp * p + p, qq = tmptmptmp * q + q;
    cout << setpre(6);
    int mxx = 0, mxy = 0;
    For(i, 0, n){
        int x, y;
        cin >> x >> y;
        if (mpp.find({x, y}) == mpp.end()){
            a.pb({x, y});
            mxx = max(mxx, x);
            mxy = max(mxy, y);
            mpp[{x, y}] = 1;
        }
    }
    if (a.size() == 1){
        cout << max(1.0 * p / a[0].fi, 1.0 * q / a[0].se);
        return 0;
    }
    a.pb({mxx, 0});
    a.pb({0, mxy});
    n = a.size();
    vpii hull = convexhull(a);
    //For(i, 0, hull.size()) cout << hull[i].fi << ' ' << hull[i].se << endl;
    vector <pdd > tmp;
    For(i, 0, hull.size()){
        if (ckintersect({0, 0}, {1.0 * pp, 1.0 * qq}, hull[i], hull[(i + 1) % (int)hull.size()])){
            pdd ta = {0.0, 0.0}, tb = {1.0 * pp, 1.0 * qq}, tc = {(ld)(hull[i].fi), (ld)(hull[i].se)}, td = {(ld)(hull[(i + 1) % (int)hull.size()].fi), (ld)(hull[(i + 1) % (int)hull.size()].se)};
            pdd ans = pointintersect(ta, tb, tc, td);
            //cout << i << ' ' << ans.fi << ' ' << ans.se << endl;
            tmp.pb(ans);
        }
    }
    //For(i, 0, tmp.size()) cout << tmp[i].fi << ' ' << tmp[i].se << endl;
    //cout << endl;
    sort(bend(tmp));
    if (tmp.size() == 0) Ptest(max(1.0 * p / inf, 1.0 * q / inf));
    //For(i, 0, tmp.size()) cout << tmp[i].fi << ' ' << tmp[i].se << endl;
    cout << max(1.0 * p / tmp[(int)tmp.size() - 1].fi, 1.0 * q / tmp[(int)tmp.size() - 1].se);
}

/*
==================================+
INPUT:                            |
------------------------------    |
2 1 1000000
2 4
5 2
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
250000.000000
------------------------------    |
==================================+
*/