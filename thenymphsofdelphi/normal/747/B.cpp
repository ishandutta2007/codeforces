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

int a, t, g, c;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    if (n % 4 != 0) Ptest("===");
    string s;
    cin >> s;
    For(i, 0, n){
        if (s[i] == 'A') a++;
        if (s[i] == 'T') t++;
        if (s[i] == 'G') g++;
        if (s[i] == 'C') c++;
    }
    if (a > n / 4) Ptest("===");
    if (t > n / 4) Ptest("===");
    if (g > n / 4) Ptest("===");
    if (c > n / 4) Ptest("===");
    int i = 0;
    while (a < n / 4){
        if (s[i] == '?'){
            s[i] = 'A';
            a++;
        }
        i++;
    }
    while (t < n / 4){
        if (s[i] == '?'){
            s[i] = 'T';
            t++;
        }
        i++;
    }
    while (g < n / 4){
        if (s[i] == '?'){
            s[i] = 'G';
            g++;
        }
        i++;
    }
    while (c < n / 4){
        if (s[i] == '?'){
            s[i] = 'C';
            c++;
        }
        i++;
    }
    cout << s;
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