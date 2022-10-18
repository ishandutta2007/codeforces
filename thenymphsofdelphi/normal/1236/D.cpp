#include<bits/stdc++.h>
using namespace std;
 
// Optimization
//#pragma GCC optimize("O3")
#define endl '\n'
 
// Shortcut
 
#define int long long
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
#define mset(a) memset(a, 0, sizeof(a))
#define mset1(a) memset(a, 1, sizeof(a))
#define msetn1(a) memset(a, -1, sizeof(a))
#define msetinf(a) memset(a, 0x3f, sizeof(a))
#define gcd __gcd
#define __builtin_popcount __builtin_popcountll
//mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());
 
// Data Structure
 
#define pque priority_queue
#define mts multiset
#define y0 _y0_
#define y1 _y1_
#define div divi
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
 
const int N = 1e5 + 5, mod = 1e9 + 7, mod1 = 998242353, mod2 = 1e9 + 9, inf = 1e9 + 7;
const ll infll = 1e18 + 7;
 
int n, m, k;
vi row[N], col[N];
 
void cango(int x, int y, int dx, int dy, int &desx, int &desy, int lx, int rx, int ly, int ry){
    if (dx == 0){
        desx = x;
        if (dy == 1){
            auto k = lwb(bend(row[x]), y + 1);
            if (k == row[x].end()){
                desy = m;
            }
            else{
                desy = row[x][k - row[x].begin()] - 1;
            }
            if (desy > ry) desy = ry;
        }
        else{
            auto k = lwb(bend(row[x]), y);
            k--;
            if (k == (--row[x].begin())){
                desy = 1;
            }
            else{
                desy = row[x][k - row[x].begin()] + 1;
            }
            if (desy < ly) desy = ly;
        }
    }
    else{
        desy = y;
        if (dx == 1){
            auto k = lwb(bend(col[y]), x + 1);
            if (k == col[y].end()){
                desx = n;
            }
            else{
                desx = col[y][k - col[y].begin()] - 1;
            }
            if (desx > rx) desx = rx;
        }
        else{
            auto k = lwb(bend(col[y]), x);
            k--;
            if (k == (--col[y].begin())){
                desx = 1;
            }
            else{
                desx = col[y][k - col[y].begin()] + 1;
            }
            if (desx < lx) desx = lx;
        }
    }
}
 
void cnv(int &dx, int &dy){
    if (dx == 0 && dy == 1){
        dx = 1;
        dy = 0;
    }
    else if (dx == 1 && dy == 0){
        dx = 0;
        dy = -1;
    }
    else if (dx == 0 && dy == -1){
        dx = -1;
        dy = 0;
    }
    else{
        dx = 0;
        dy = 1;
    }
    return;
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    ForE(i, 1, k){
        int x, y;
        cin >> x >> y;
        row[x].pb(y);
        col[y].pb(x);
    }
    ForE(i, 1, n){
        sort(bend(row[i]));
    }
    ForE(j, 1, m){
        sort(bend(col[j]));
    }
    int ans = 0;
    int dx = 0, dy = 1;
    int xx = 1, yy = 0, nx = 1, ny = m, lx = 1, rx = n, ly = 1, ry = m;
    do{
        //cout << xx << ' ' << yy << ' ' << dx << ' ' << dy << ' ' << nx << ' ' << ny << endl;
        cango(xx, yy, dx, dy, nx, ny, lx, rx, ly, ry);
        //cout << xx << ' ' << yy << ' ' << dx << ' ' << dy << ' ' << nx << ' ' << ny << endl << endl;
        if (nx == xx && ny == yy) break;
        ans += abs(nx - xx) + abs(ny - yy);
        if (dx == 0 && dy == 1){
            lx = xx + 1;
        }
        if (dx == 0 && dy == -1){
            rx = xx - 1;
        }
        if (dx == 1 && dy == 0){
            ry = yy - 1;
        }
        if (dx == -1 && dy == 0){
            ly = yy + 1;
        }
        xx = nx;
        yy = ny;
        cnv(dx, dy);
    } while (1);
    if (n * m - ans == k) Ptest("Yes");
    cout << "No";
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