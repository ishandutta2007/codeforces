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
#define Ford(i, a, b) for (int i = a; i > b; i--)
#define PrintV(x) for (int i = 0; i < x.size(); i++) cout << x[i] << ' ';
typedef vector <int> 	vi;
typedef pair <int, int> ii;
typedef vector <vi > 	vvi;
typedef vector <ii > 	vii;

const int N = 2e5 + 5, mod = 1e9 + 7, inf = 1e18 + 7;

int a[N], b[N];
int n, ans;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    b[0] = 0;
    For(i, 1, n + 1){
        cin >> a[i];
        b[i] = b[i - 1] + a[i];
    }
    //cout << "S\tI J T\n";
    For(i, 1, n + 1){
        For(j, i, n + 1){
            int t = j - i + 1, s = b[j] - b[i - 1];
            if (s > 100 * t){
                //cout << s << ' ' << i << ' ' << j << ' ' << t << endl;
                ans = max(ans, t);
            }
        }
    }
    cout << ans;
}

/*
----------------------------------+
INPUT:                            |
==============================    |
5
100 200 1 1 1
==============================    |
5
1 2 3 4 5
==============================    |
2
101 99
==============================    |
----------------------------------+
OUTPUT:                           |
==============================    |
3
==============================    |
0
==============================    |
1
==============================    |
----------------------------------+
*/