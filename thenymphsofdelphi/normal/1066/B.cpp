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

int n, r;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> r;
	vi a(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	int ans = 0, lst = -1;
	while (lst < n - 1){
		int pos = -1;
		for (int i = n - 1; i > max(-1ll, lst - r + 1); i--){
			if (a[i] == 1 && i - r <= lst){
				pos = i;
				break;
			}
		}
		if (pos == -1){
			cout << -1;
			return 0;
		}
		ans++;
		lst = pos + r - 1;
	}
	cout << ans;
}

/*
----------------------------------+
INPUT:  						  |
==============================    |
6 2
0 1 1 0 0 1
==============================    |
5 3
1 0 0 0 1
==============================    |
5 10
0 0 0 0 0
==============================    |
10 3
0 0 1 1 0 1 0 0 0 1
==============================    |
----------------------------------+
OUTPUT: 						  |
==============================    |
3
==============================    |
2
==============================    |
-1
==============================    |
3
==============================    |
----------------------------------+
*/