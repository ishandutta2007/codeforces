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
typedef vector <int> 	vi;
typedef pair <int, int> ii;
typedef vector <vi > 	vvi;
typedef vector <ii > 	vii;

const int N = 2e5 + 5, mod = 1e9 + 7, inf = 1e18 + 7;

int n, k;
int a[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    ForE(i, 1, n){
        cin >> a[i];
    }
    int ans = 0, must = 0;
    ForE(i, 1, n + 1){
        if (must > 0){
            ans++;
            a[i] = max(0ll, a[i] - k + must);
        }
        ans += a[i] / k;
        must = a[i] % k;
        //cout << ans << endl;
    }
    cout << ans;
}

/*
----------------------------------+
INPUT:                            |
==============================    |
3 2
3 2 1
==============================    |
5 1
1000000000 1000000000 1000000000 1000000000 1000000000
==============================    |
3 2
1 0 1
==============================    |
4 4
2 8 4 1
==============================    |
----------------------------------+
OUTPUT:                           |
==============================    |
3
==============================    |
5000000000
==============================    |
2
==============================    |
4
==============================    |
----------------------------------+
*/