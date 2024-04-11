#include<bits/stdc++.h>
using namespace std;

// Optimization
#pragma optimize ("O3")
#define endl '\n'

// Shortcut

//#define int long long
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
#define m1set(a) memset(a, 1, sizeof(a))
#define mn1set(a) memset(a, -1, sizeof(a))
#define mmset(a) memset(a, 0x3f, sizeof(a))
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

const int N = 2e6 + 5, mod = 1e9 + 7, inf = 1e9 + 7;

int n, m, ans, t;
int a[N], b[10][10];
int aans[10][10][10][10];

int ck(int la, int lb, int x, int y){
    if (la == lb && (x == 0 || y == 0)){
        return 0;
    }
    if (x == 0 && y == 0) return -1;
    int tmp = lb - la;
    if (tmp <= 0) tmp += 10;
    int mn = inf;
    while (tmp < 110){
        int ttmp = tmp % y;
        while (ttmp <= tmp){
            if (x && ttmp % x == 0){
                mn = min(mn, (tmp - ttmp) / y + ttmp / x - 1);
                break;
            }
            ttmp += y;
        }
        if (y && tmp % y == 0) mn = min(mn, tmp / y - 1);
        tmp += 10;
    }
    if (mn == inf) return -1;
    return mn;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    if (s == "0"){
        For(i, 0, 10){
            For(j, 0, 10){
                cout << 0 << ' ';
            }
            cout << endl;
        }
        return 0;
    }
    int n = s.length();
    For(i, 0, n){
        a[i] = s[i] - '0';
    }
    For(i, 0, 10){
        For(j, 0, 10){
            For(k, 0, 10){
                For(l, 0, 10){
                    if (i > j){
                        aans[i][j][k][l] = aans[j][i][k][l];
                    }
                    else{
                        aans[i][j][k][l] = ck(k, l, i, j);
                    }
                }
            }
        }
    }
    For(i, 0, 10){
        For(j, 0, 10){
            if (i > j){
                cout << b[j][i] << ' ';
                continue;
            }
            //cout << i << ' ' << j << endl;
            ans = 0;
            For(k, 1, n){
                int tans = aans[i][j][a[k - 1]][a[k]];
                //cout << tans << ' ';
                if (tans == -1){
                    ans = -1;
                    break;
                }
                ans += tans;
            }
            //cout << endl;
            cout << ans << ' ';
            b[i][j] = ans;
            //cout << endl;
        }
        cout << endl;
    }
}

/*
==================================+
INPUT:                            |
------------------------------    |
0840
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
-1 17 7 7 7 -1 2 17 2 7 
17 17 7 5 5 5 2 7 2 7 
7 7 7 4 3 7 1 7 2 5 
7 5 4 7 3 3 2 5 2 3 
7 5 3 3 7 7 1 7 2 7 
-1 5 7 3 7 -1 2 9 2 7 
2 2 1 2 1 2 2 2 0 1 
17 7 7 5 7 9 2 17 2 3 
2 2 2 2 2 2 0 2 2 2 
7 7 5 3 7 7 1 3 2 7 

------------------------------    |
==================================+
*/