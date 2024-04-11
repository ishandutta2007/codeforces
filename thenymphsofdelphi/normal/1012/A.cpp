#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define mp make_pair
#define endl '\n'
#define pque priority_queue
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef vector <ii > vii;

const int mod = 1000000007;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, ans = 1e18, dis;
	cin >> n;
	int a[2 * n];
	for (int i = 0; i < 2 * n; i++){
		cin >> a[i];
	}
	sort(a, a + 2 * n);
	if (n == 1){
		cout << 0;
		return 0;
	}
	for (int i = 0; i < n; i++){
		dis = a[i + n - 1] - a[i];
		if (i == 0){
			ans = min(ans, dis * (a[2 * n - 1] - a[n]));
		}
		else{
			ans = min(ans, dis * (a[2 * n - 1] - a[0]));
		}
	}
	for (int i = n - 1; i < 2 * n; i++){
		dis = i - n + 1;
		ans = min(ans, (a[i] - a[0]) * (a[2 * n - 1] - a[i - dis]));
	}
	cout << ans;
}