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
    int n, q;
    cin >> n;
    int a[n];
    For(i, 0, n) cin >> a[i];
    cin >> q;
    while (q--){
        int x, y;
        cin >> x >> y;
        x--;
        int l = y - 1, r = a[x] - y;
        if (x != 0){
            a[x - 1] += l;
        }
        if (x != n - 1){
            a[x + 1] += r;
        }
        a[x] = 0;
    }
    For(i, 0, n) cout << a[i] << endl;
}

/*
----------------------------------+
INPUT:                            |
==============================    |
5
10 10 10 10 10
5
2 5
3 13
2 12
1 13
4 6
==============================    |
----------------------------------+
OUTPUT:                           |
==============================    |
0
12
5
0
16
==============================    |
----------------------------------+
*/