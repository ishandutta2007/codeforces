#include<bits/stdc++.h>
using namespace std;
//#define int long long
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

const int N = 100 + 5, mod = 1e9 + 7, inf = 1e9 + 7;

int n, m, k;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	int ans = 0, x = n + m + n + m - 4;
	while (k--){
	    ans += x;
	    x -= 16;
	}
	cout << ans;
}

/*
----------------------------------+
INPUT:                            |
==============================    |
3 3 1
==============================    |
----------------------------------+
OUTPUT:                           |
==============================    |
8
==============================    |
----------------------------------+
*/