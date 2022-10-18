#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define mp make_pair
#define pque priority_queue
#define endl '\n'
#define For(i, a, b) for (int i = a; i < b; i++)
#define ForE(i, a, b) for (int i = a; i <= b; i++)
#define Ford(i, a, b) for (int i = a; i > b; i--)
#define FordE(i, a, b) for (int i = a; i >= b; i--)

#define PrintV(x) for (int i = 0; i < x.size(); i++) cout << x[i] << ' ';
#define PrintVl(x) for (int i = 0; i < x.size(); i++) cout << x[i] << endl;
#define Ptest(a) return cout << a << endl, 0;
#define isvowel(a) (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' || a == 'y')

typedef vector <int> vi;
typedef pair <int, int> ii;
typedef vector <vi > vvi;
typedef vector <ii > vii;

const int N = 1e5 + 5, mod = 1e9 + 7, inf = 1e18 + 7;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    int a[n + 1][m + 1], b[n + 1][m + 1];
    string s;
    ForE(i, 1, n){
        cin >> s;
        ForE(j, 1, m){
            a[i][j] = ((s[j - 1] == '*') ? 1 : 0);
        }
    }
    ForE(i, 1, n){
        int cnt = 0;
        ForE(j, 1, m){
            if (a[i][j]) cnt++;
        }
        if (cnt == 1) cout << i << ' ';
    }
    ForE(j, 1, m){
        int cnt = 0;
        ForE(i, 1, n){
            if (a[i][j]) cnt++;
        }
        if (cnt == 1) cout << j << ' ';
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