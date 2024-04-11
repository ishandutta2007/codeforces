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
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef vector <vi > vvi;
typedef vector <ii > vii;

const int N = 2e5 + 5, mod = 1e9 + 7, inf = 1e18 + 7;

int n;
int a[N], b[N], c[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    For(i, 0, n){
        cin >> a[i];
        c[a[i]] = i + 1;
    }
    int m = 0;
    For(i, 0, n){
        int x; cin >> x;
        cout << max(0ll, c[x] - m) << ' ';
        m = max(c[x], m);
    }
}

/*
----------------------------------+
INPUT:                            |
==============================    |
3
1 2 3
2 1 3

==============================    |
----------------------------------+
OUTPUT:                           |
==============================    |
2 0 1 

==============================    |
----------------------------------+
*/