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

int cmp(string a, string b){
    if (a == b) return 0;
    if (a == "rock"){
        if (b == "scissors") return 1;
        else return -1;
    }
    if (a == "scissors"){
        if (b == "paper") return 1;
        else return -1;
    }
    if (a == "paper"){
        if (b == "rock") return 1;
        else return -1;
    }
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string a, b, c;
    cin >> a >> b >> c;
    if (a == b && b == c) Ptest('?');
    if (a != b && b != c && c != a) Ptest('?');
    if (cmp(a, b) == 0){
        if (cmp(a, c) == -1) Ptest('S');
    }
    if (cmp(b, c) == 0){
        if (cmp(b, a) == -1){
            Ptest('F');
        }
    }
    if (cmp(c, a) == 0){
        if (cmp(c, b) == -1) Ptest('M');
    }
    cout << '?';
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