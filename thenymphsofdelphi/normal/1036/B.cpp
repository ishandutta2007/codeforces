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

int q, n, m, k;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> q;
	while (q--){
		cin >> n >> m >> k;
		if (max(n, m) > k){
			cout << "-1\n";
			continue;
		}
		if (n < m){
		    swap(n, m);
		}
		if ((n + m) % 2 == 1){
		    cout << k - 1 << endl;
		}
		else{
			if ((k - n) % 2 == 1){
			    k -= 2;
			}
			cout << k << endl;
		}
	}
}