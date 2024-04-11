#include<bits/stdc++.h>
using namespace std;

// Shortcut

//#define int long long
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
typedef vector <vi > vvi;
typedef vector <vll > vvll;
typedef vector <pii > vpii;
typedef vector <pll > vpll;

const int N = 1e2 + 5, mod = 1e9 + 7, inf = 1e9 + 7;

int n, m;
bool a[N][N], ck[N][N];
int x = 1, y = 1, fx, fy;
int chUD = -1, chLR = -1;

bool ckmoveUD(int xx, int yy){
    if ((xx == 1 || a[xx - 1][yy]) && (xx == n || a[xx + 1][yy])) return 1;
    return 0;
}

bool ckmoveLR(int xx, int yy){
    if ((yy == 1 || a[xx][yy - 1]) && (yy == m || a[xx][yy + 1])) return 1;
    return 0;
}

void ckfin(int xx, int yy){
    if (xx == -1 || yy == -1) exit(0);
    if (!a[xx][yy] || (fx == xx && fy == yy)){
        //cout << "NANI";
        exit(0);
    }
}

bool move(char cak, int xx, int yy, int qxx, int qyy){
    if (cak == 'U'){
        xx = max(1, xx - 1);
        return qxx == xx && qyy == yy;
    }
    if (cak == 'D'){
        xx = min(n, xx + 1);
        return qxx == xx && qyy == yy;
    }
    if (cak == 'L'){
        yy = max(1, yy - 1);
        return qxx == xx && qyy == yy;
    }
    if (cak == 'R'){
        yy = min(m, yy - 1);
        return qxx == xx && qyy == yy;
    }
}

vpii ansans;

bool dfs(int xx, int yy){
    ansans.pb({xx, yy});
    if (xx == fx && yy == fy){
        return 1;
    }
    ck[xx][yy] = 0;
    if (ck[xx - 1][yy]){
        if (dfs(xx - 1, yy)) return 1;
    }
    if (ck[xx + 1][yy]){
        if (dfs(xx + 1, yy)) return 1;
    }
    if (ck[xx][yy - 1]){
        if (dfs(xx, yy - 1)) return 1;
    }
    if (ck[xx][yy + 1]){
        if (dfs(xx, yy + 1)) return 1;
    }
    ansans.pob();
    return 0;
}

void createdfs(){
    if (!dfs(x, y)){
        cout << "NANI";
        exit(0);
    }
    return;
}

signed main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    cin >> n >> m;
    if (n == 1 && m == 1){
        return 0;
    }
    ForE(i, 1, n){
        string s;
        cin >> s;
        ForE(j, 1, m){
            if (s[j - 1] == '.'){
                a[i][j] = 1;
                ck[i][j] = 1;
            }
            if (s[j - 1] == '*'){
                a[i][j] = 0;
                ck[i][j] = 0;
            }
            if (s[j - 1] == 'F'){
                a[i][j] = 1;
                ck[i][j] = 1;
                fx = i;
                fy = j;
            }
            //cout << a[i][j];
        }
        //cout << endl;
    }
    int qx, qy;
    if (ckmoveUD(x, y)){
        cout << 'U' << endl << flush;
        cin >> qx >> qy;
        ckfin(qx, qy);
        if (move('U', x, y, qx, qy)){
            chUD = 0;
        }
        else{
            chUD = 1;
            cout << 'D' << endl << flush;
            cin >> qx >> qy;
            ckfin(qx, qy);
        }
    }
    if (ckmoveLR(x, y)){
        cout << 'L' << endl << flush;
        cin >> qx >> qy;
        ckfin(qx, qy);
        if (move('L', x, y, qx, qy)){
            chLR = 0;
        }
        else{
            chLR = 1;
            cout << 'R' << endl << flush;
            cin >> qx >> qy;
            ckfin(qx, qy);
        }
    }
    if (chUD == -1){
        while (!ckmoveUD(x, y)){
            if (chLR == 0){
                cout << 'R' << endl << flush;
            }
            else{
                cout << 'L' << endl << flush;
            }
            cin >> x >> y;
            ckfin(x, y);
        }
        cout << 'U' << endl << flush;
        cin >> qx >> qy;
        ckfin(qx, qy);
        if (move('U', x, y, qx, qy)){
            chUD = 0;
        }
        else{
            chUD = 1;
            cout << 'D' << endl << flush;
            cin >> qx >> qy;
            ckfin(qx, qy);
        }
    }
    if (chLR == -1){
        while (!ckmoveLR(x, y)){
            if (chUD == 0){
                cout << 'D' << endl << flush;
            }
            else{
                cout << 'U' << endl << flush;
            }
            cin >> x >> y;
            ckfin(x, y);
        }
        cout << 'L' << endl << flush;
        cin >> qx >> qy;
        ckfin(qx, qy);
        if (move('L', x, y, qx, qy)){
            chLR = 0;
        }
        else{
            chLR = 1;
            cout << 'R' << endl << flush;
            cin >> qx >> qy;
            ckfin(qx, qy);
        }
    }
    createdfs();
    //For(i, 0, ansans.size()){
    //	cout << ansans[i].fi << ' ' << ansans[i].se << endl;
	//}
    //cout << ansans.size();
    For(i, 1, ansans.size()){
        int ddx = ansans[i].fi - x, ddy = ansans[i].se - y;
        if (ddx == -1 && ddy == 0){
            cout << (chUD == 0 ? 'U' : 'D') << endl << flush;
            cin >> qx >> qy;
            ckfin(qx, qy);
            x = qx;
            y = qy;
        }
        if (ddx == 1 && ddy == 0){
            cout << (chUD == 0 ? 'D' : 'U') << endl << flush;
            cin >> qx >> qy;
            ckfin(qx, qy);
            x = qx;
            y = qy;
        }
        if (ddx == 0 && ddy == -1){
            cout << (chLR == 0 ? 'L' : 'R') << endl << flush;
            cin >> qx >> qy;
            ckfin(qx, qy);
            x = qx;
            y = qy;
        }
        if (ddx == 0 && ddy == 1){
            cout << (chLR == 0 ? 'R' : 'L') << endl << flush;
            cin >> qx >> qy;
            ckfin(qx, qy);
            x = qx;
            y = qy;
        }
    }
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