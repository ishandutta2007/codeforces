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

#define mset(a) memset(a, 0, sizeof(a));
#define sortV(a) sort(a.begin(), a.end());
#define sortA(a, n) sort(a, a + n);
#define rvs(s) reverse(s.begin(), s.end());

// Data Structure

#define pque priority_queue
#define mts multiset
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef vector <vi > vvi;
typedef vector <ii > vii;

const int N = 1e5 + 5, mod = 1e9 + 7, inf = 1e18 + 7;

int n;
string s, t, v;
vector <string> a;

void bt(int u){
    if (u == n){
        if (t.length() == 0) return;
        string v = t;
        rvs(v);
        if (v == t) a.pb(t);
        return;
    }
    bt(u + 1);
    t.pb(s[u]);
    bt(u + 1);
    t.pob();
    return;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> s;
    n = s.length();
    bt(0);
    sortV(a);
    cout << a[a.size() - 1];
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