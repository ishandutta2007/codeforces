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

const int N = 1e5 + 5, mod = 1e9 + 7, inf = 1e18 + 7;

int n, k, s;
int a[N], b[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    ForE(i, 1, n){
        cin >> a[i];
        s += a[i];
        b[i] = b[i - 1] + a[i];
    }
    if (s % k) return cout << "No", 0;
    vi ans;
    ans.pb(0);
    int t = s / k, idx = 1;
    while (idx <= n){
        while (idx <= n && b[idx] <= t){
            idx++;
        }
        if (b[idx - 1] != t) return cout << "No", 0;
        ans.pb(idx - 1);
        t += s / k;
    }
    if (ans.size() != k + 1) return cout << "No", 0;
    cout << "Yes" << endl;
    For(i, 1, ans.size()) cout << ans[i] - ans[i - 1] << ' ';
}

/*
----------------------------------+
INPUT:                            |
==============================    |
6 3
3 3 1 4 1 6
==============================    |
3 3
1 1 1
==============================    |
3 3
1 1 2
==============================    |
3 1
1 10 100
==============================    |
----------------------------------+
OUTPUT:                           |
==============================    |
Yes
2 3 1 
==============================    |
Yes
1 1 1 
==============================    |
No
==============================    |
Yes
3 
==============================    |
----------------------------------+
*/