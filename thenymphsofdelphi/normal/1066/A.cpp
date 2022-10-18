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
typedef vector <int> 	vi;
typedef pair <int, int> ii;
typedef vector <vi > 	vvi;
typedef vector <ii > 	vii;

const int N = 1e5 + 5, mod = 1e9 + 7, inf = 1e18 + 7;

int t, n, v, l, r;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--){
	    cin >> n >> v >> l >> r;
	    int ans = n / v;
	    l = l + v - 1;
	    l = (l / v) * v;
	    r = (r / v) * v;
	    ans -= (r - l) / v + 1;
	    cout << ans << endl;
	}
}

/*
----------------------------------+
INPUT:  						  |
==============================    |
4
10 2 3 7
100 51 51 51
1234 1 100 199
1000000000 1 1 1000000000
==============================    |
----------------------------------+
OUTPUT: 						  |
==============================    |
3
0
1134
0
==============================    |
----------------------------------+
*/