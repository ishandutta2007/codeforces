#include<bits/stdc++.h>
using namespace std;
#define int long long
#define push_back pb
#define pop_back pob
#define make_pair mp
#define endl "\n"

const int N = 200005, mod = 1000000007, inf = 1000000000000000000;

int a[N], l[N], r[N];

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, j, val, mn = -1;
	cin >> n;
	l[0] = 0;
	r[0] = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		l[i] = a[i] + l[i - 1];
	}
	for (int i = 1; i <= n; i++){
		r[i] = a[n + 1 - i] + r[i - 1];
	}
	for (int i = 0; i <= n; i++){
		val = lower_bound(r, r + n, l[i]) - r;
		if (r[val] == l[i] && val + i <= n){
		    mn = max(mn, l[i]);
		}
		//cout << val << " " << mn << " " << l[i] << endl;
	}
	cout << mn;
}