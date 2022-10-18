#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define forl(i, a, b) for (int i = a; i < b; i++)
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

int n, s, a, b, c;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	while (n--){
	    cin >> s >> a >> b >> c;
	    int ans = s / c;
	    ans += (ans / a) * b;
	    cout << ans << endl;
	}
}

/*
----------------------------------+
INPUT:  						  |
==============================    |
2
10 3 1 1
1000000000 1 1000000000 1
==============================    |
----------------------------------+
OUTPUT: 						  |
==============================    |
13
1000000001000000000
==============================    |
----------------------------------+
*/