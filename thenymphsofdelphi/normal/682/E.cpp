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
#define mmset(a) memset(a, 0x3f, sizeof(a));
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
typedef vector <vi > vvi;
typedef vector <vll > vvll;
typedef vector <pii > vpii;
typedef vector <pll > vpll;

const int N = 5e3 + 5, mod = 1e9 + 7, inf = 1e9 + 7;

int n, sss;

struct Point{
    int x, y;
} a[N];

int area(Point p, Point q, Point r){
    ld a1 = sqrtl(1.0 * abs(p.x - q.x) * abs(p.x - q.x) + 1.0 * abs(p.y - q.y) * abs(p.y - q.y));
    ld a2 = sqrtl(1.0 * abs(q.x - r.x) * abs(q.x - r.x) + 1.0 * abs(q.y - r.y) * abs(q.y - r.y));
    ld a3 = sqrtl(1.0 * abs(r.x - p.x) * abs(r.x - p.x) + 1.0 * abs(r.y - p.y) * abs(r.y - p.y));
    ld pp = 0.5 * (a1 + a2 + a3);
    return sqrtl(pp * (pp - a1) * (pp - a2) * (pp - a3));
}

int orientation(Point p, Point q, Point r){
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1: 2;
}

vector <Point> convexHull(){
    if (n < 3){
        return {};
    }
    vector <Point> hull;
    int l = 0;
    For(i, 1, n){
        if (a[i].x < a[l].x){
            l = i;
        }
    }
    int p = l, q;
    do{
        //cout << p << ' ' << l << endl;
        hull.pb(a[p]);
        q = (p + 1) % n;
        For(i, 0, n){
            if (orientation(a[p], a[i], a[q]) == 2){
                q = i;
            }
        }
        p = q;
    } while (p != l);
    return hull;
} 

signed main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    cin >> n >> sss;
    For(i, 0, n){
        cin >> a[i].x >> a[i].y;
    }
    //cout << "NANI" << endl;
    vector <Point> hull = convexHull();
    n = hull.size();
    int ii = 0, jj = 1, kk = 2, mxii = 0, mxjj = 1, mxkk = 2;
    //cout << "NANI" << endl;
    while (1){
        int origjj = jj;
        while (1){
            int origkk = kk;
            while (area(hull[ii], hull[jj], hull[kk]) <= area(hull[ii], hull[jj], hull[(kk + 1) % n])){
                kk = (kk + 1) % n;
                if (kk == origkk){
                    break;
                }
                //cout << ii << ' ' << jj << ' ' << kk << endl;
            }
            if (area(hull[ii], hull[jj], hull[kk]) <= area(hull[ii], hull[(jj + 1) % n], hull[kk])){
                jj = (jj + 1) % n;
                if (jj == origjj){
                    break;
                }
            }
            else{
                break;
            }
        }
        if (area(hull[ii], hull[jj], hull[kk]) > area(hull[mxii], hull[mxjj], hull[mxkk])){
            mxii = ii;
            mxjj = jj;
            mxkk = kk;
        }
        ii = (ii + 1) % n;
        if (ii == jj){
            jj = (jj + 1) % n;
        }
        if (jj == kk){
            kk = (kk + 1) % n;
        }
        if (ii == 0){
            break;
        }
    }
    cout << hull[mxii].x - hull[mxjj].x + hull[mxkk].x << ' ' << hull[mxii].y - hull[mxjj].y + hull[mxkk].y << endl;
    cout << hull[mxjj].x - hull[mxkk].x + hull[mxii].x << ' ' << hull[mxjj].y - hull[mxkk].y + hull[mxii].y << endl;
    cout << hull[mxkk].x - hull[mxii].x + hull[mxjj].x << ' ' << hull[mxkk].y - hull[mxii].y + hull[mxjj].y << endl;
}

/*
==================================+
INPUT:                            |
------------------------------    |

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/