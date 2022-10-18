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
	int n, ans, dis;
	cin >> n;
	int a[2 * n + 1];
	for (int i = 1; i <= 2 * n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + 2 * n + 1);
	if (n == 1){
		cout << 0;
		return 0;
	}
	ans = (a[n] - a[1]) * (a[2 * n] - a[n + 1]);
	for (int i = 2; i <= n; i++){
		ans = min(ans, (a[i + n - 1] - a[i]) * (a[2 * n] - a[1]));
	}
	for (int i = n; i <= 2 * n; i++){
		dis = i - n;
		ans = min(ans, (a[i] - a[1]) * (a[2 * n] - a[i - dis]));
	}
	cout << ans;
}