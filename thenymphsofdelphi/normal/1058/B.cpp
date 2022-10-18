#include<bits/stdc++.h>
using namespace std;
#define int		long long
#define double	long double
#define pb		push_back
#define pob		pop_back
#define mp		make_pair
#define fi		first
#define se		second
#define pque	priority_queue
#define endl	'\n'
typedef vector <int> 	vi;
typedef pair <int, int> ii;
typedef vector <vi > 	vvi;
typedef vector <ii > 	vii;

const int N = 1e5 + 5, mod = 1e9 + 7, inf = 1e18 + 7;

int m, d, n, x, y;
int a[N];

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> m >> d;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> x >> y;
		if (x + y < d || x + y > 2 * m - d){
		    cout << "NO\n";
		}
		else if (abs(x - y) > d){
		    cout << "NO\n";
		}
		else{
		    cout << "YES\n";
		}
	}
}

/*

*/