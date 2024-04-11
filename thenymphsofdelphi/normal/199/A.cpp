#include<bits/stdc++.h>
using namespace std;

// Shortcut

#define int long long
#define ld long double
#define endl '\n'
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

#define PrintV(a) for (int i = 0; i < a.size(); i++) cout << a[i] << ' ';
#define PrintVl(a) for (int i = 0; i < a.size(); i++) cout << a[i] << endl;
#define PrintA(a, n) for (int i = 0; i < n; i++) cout << a[i] << ' ';
#define PrintAl(a, n) for (int i = 0; i < n; i++) cout << a[i] << endl;
#define Ptest(x) return cout << x, 0;
#define gl(s) getline(cin, s);

// Functions

#define bend(a) a.begin(),a.end()
#define mset(a) memset(a, 0, sizeof(a));
#define sortV(a) sort(bend(a));
#define sortA(a, n) sort(a, a + n);
#define rev(s) reverse(bend(a));

// Data Structure

#define pque priority_queue
#define mts multiset
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef vector <vi > vvi;
typedef vector <ii > vii;

const int N = 1e5 + 5, mod = 1e9 + 7, inf = 1e18 + 7;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    if (n == 0) Ptest("0 0 0");
    if (n == 1) Ptest("0 0 1");
    if (n == 2) Ptest("0 1 1");
    int a[50];
    a[0] = 0;
    a[1] = 1;
    For(i, 2, 50){
        a[i] = a[i - 1] + a[i - 2];
    }
    For(i, 4, 50){
        if (a[i] == n) return cout << a[i - 4] << ' ' << a[i - 3] << ' ' << a[i - 1] << endl, 0;
    }
}

/*
----------------------------------+
INPUT:                            |
==============================    |

==============================    |
----------------------------------+
OUTPUT:                           |
==============================    |

==============================    |
----------------------------------+
*/