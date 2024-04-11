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

const int N = 10 + 5, mod = 1e9 + 7, inf = 1e18 + 7;

int a[N], b[N];
bool cka[N], ckb[N];
int n, m;

signed main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    For(i, 0, n){
        cin >> a[i];
        cka[a[i]] = 1;
    }
    For(i, 0, m){
        cin >> b[i];
        ckb[b[i]] = 1;
    }
    For(i, 1, 10){
        if (cka[i] && ckb[i]){
            return cout << i, 0;
        }
    }
    sort(a, a + n);
    sort(b, b + m);
    if (a[0] < b[0]) return cout << a[0] << b[0], 0;
    cout << b[0] << a[0];
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