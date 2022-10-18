#include<bits/stdc++.h>
using namespace std;

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
#define For(indx, a, b) for (int indx = a; indx < b; indx++)
#define ForE(indx, a, b) for (int indx = a; indx <= b; indx++)
#define Ford(indx, a, b) for (int indx = a; indx > b; indx--)
#define FordE(indx, a, b) for (int indx = a; indx >= b; indx--)
#define Fora(indx, a) for (auto indx : a)

#define PrintV(x) for (int indx = 0; indx < x.size(); indx++) cout << x[indx] << ' ';
#define PrintVl(x) for (int indx = 0; indx < x.size(); indx++) cout << x[indx] << endl;
#define Ptest(x) return cout << x, 0;
#define Pmtest(x) cout << x << endl; continue;
#define isvowel(x) (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'y')
#define gl(x) getline(cin, x)
#define mset(x) memset(x, 0, sizeof(x));

#define pque priority_queue
#define mts multiset
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef vector <vi > vvi;
typedef vector <ii > vii;

const int N = 2e5 + 5, mod = 998244353, inf = 1e18 + 7;

int a[N], b[N], c[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    ForE(i, 1, n / 2){
        cin >> a[i];
        if (a[i] % 2 == 0 && a[i] % 4 != 0) Ptest("No");
        if (a[i] <= 2) Ptest("No");
        b[i * 2] = a[i];
    }
    ForE(i, 1, n / 2){
        bool ck = 0;
        ForE(j, 1, sqrt(a[i])){
            if (a[i] % j == 0){
                int k = a[i] / j;
                if ((k - j) % 2 == 0){
                    int x = (k - j) / 2, y = k - x;
                    if (x * x <= c[i * 2 - 2] || x * x == 0 || y * y == 0){
                        continue;
                    }
                    b[i * 2 - 1] = x * x - c[i * 2 - 2];
                    c[i * 2 - 1] = x * x;
                    c[i * 2] = y * y;
                    ck = 1;
                }
            }
        }
        if (!ck) Ptest("No");
    }
    cout << "Yes" << endl;
    ForE(i, 1, n){
        cout << b[i] << ' ';
    }
}

/*
==================================+
INPUT:                            |
------------------------------    |
6
5 11 44

------------------------------    |
2
9900

------------------------------    |
6
314 1592 6535

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
Yes
4 5 16 11 64 44

------------------------------    |
Yes
100 9900

------------------------------    |
No

------------------------------    |
==================================+
*/