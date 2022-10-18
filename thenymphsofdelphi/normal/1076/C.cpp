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
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        if (n == 0){
            cout << "Y 0.000000000 0.000000000" << endl;
            continue;
        }
        if (n == 1 || n == 2 || n == 3){
            cout << "N " << endl;
            continue;
        }
        if (n == 4){
            cout << "Y 2.000000000 2.00000000" << endl;
            continue;
        }
        double a, b, l, r, x;
        if (n < 4){
            l = 0.0;
            r = n * 1.0;
        }
        else{
            l = (n - 2) * 1.0;
            r = (n - 1) * 1.0;
        }
        do{
            a = (l + r) / 2.0;
            b = n - a;
            x = a * b;
            //cout << fixed << setprecision(9) << a << ' ' << b << ' ' << x << endl;
            if (x <= n){
                r = a + 0.000001;
            }
            else{
                l = a - 0.000001;
            }
        } while (abs(1.0 * n - x) > 0.0000001);
        cout << "Y ";
        cout << fixed << setprecision(9) << a << ' ' << b << endl;
    }
}

/*
----------------------------------+
INPUT:                            |
==============================    |
7
69
0
1
4
5
999
1000
==============================    |
----------------------------------+
OUTPUT:                           |
==============================    |
Y 67.985071301 1.014928699
Y 0.000000000 0.000000000
N
Y 2.000000000 2.000000000
Y 3.618033989 1.381966011
Y 997.998996990 1.001003010
Y 998.998997995 1.001002005
==============================    |
----------------------------------+
*/