#include<bits/stdc++.h>
using namespace std;

// Shortcut

#define int long long
//#define endl '\n'
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

const int N = 1e3 + 5, M = 20 + 5, mod = 1e9 + 7, inf = 1e18 + 5;

int n, que;
int a[N], final[N], ans[N];
vi que1[M], que2[M];

void cal(int l, int r, int t){
    que = max(que, t);
    if (l == r){
        que1[t].pb(l);
        return;
    }
    int mid = (l + r) >> 1;
    ForE(i, l, mid){
        que1[t].pb(i);
    }
    if ((r - l + 1) & 1){
        cal(l, mid - 1, t + 1);
    }
    else{
        cal(l, mid, t + 1);
        mid++;
    }
    ForE(i, mid, r){
        que2[t].pb(i);
    }
    if ((r - l + 1) & 1){
        cal(mid + 1, r, t + 1);
    }
    else{
        cal(mid, r, t + 1);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    cal(1, n, 0);
    memset(final, 0x3f, sizeof(final));
    ForE(i, 0, que){
        if (que1[i].size()){
            cout << que1[i].size() << endl;
            PrintV(que1[i]);
            cout << endl;
            ForE(j, 1, n){
                cin >> ans[j];
                bool ck = 1;
                For(k, 0, que1[i].size()){
                    if (que1[i][k] == j){
                        ck = 0;
                        break;
                    }
                }
                if (ck){
                    final[j] = min(final[j], ans[j]);
                }
            }
        }
        if (que2[i].size()){
            cout << que2[i].size() << endl;
            PrintV(que2[i]);
            cout << endl;
            ForE(j, 1, n){
                cin >> ans[j];
                bool ck = 1;
                For(k, 0, que2[i].size()){
                    if (que2[i][k] == j){
                        ck = 0;
                        break;
                    }
                }
                if (ck){
                    final[j] = min(final[j], ans[j]);
                }
            }
        }
    }
    cout << -1 << endl;
    ForE(i, 1, n){
        cout << final[i] << endl;
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