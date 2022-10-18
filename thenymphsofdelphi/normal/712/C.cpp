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
#define Ptest(a) return cout << a, 0;
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef vector <vi > vvi;
typedef vector <ii > vii;

const int N = 100 + 5, mod = 1e9 + 7, inf = 1e17 + 7;

int x, y;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int a, b, c;
    cin >> x >> y;
    a = y;
    b = y;
    c = y;
    int ans = 0, i = 0;
    while (a != x || b != x || c != x){
        if (i == 0) a = min(x, b + c - 1);
        if (i == 1) b = min(x, c + a - 1);
        if (i == 2) c = min(x, a + b - 1);
        i = (i + 1) % 3;
        ans++;
    }
    cout << ans;
}

/*
----------------------------------+
INPUT:                            |
==============================    |
6 3
==============================    |
----------------------------------+
OUTPUT:                           |
==============================    |
4
==============================    |
----------------------------------+
*/