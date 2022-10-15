#include<bits/stdc++.h>
using namespace std;
const int N(444444);
int p[N], c[N], d1[N], d2[N], cst[N];
int main() {
	int n, k, s, t;
	scanf("%d%d%d%d", &n, &k, &s, &t);
	for(int i(1); i <= n; i++) {
		scanf("%d%d", &p[i], &c[i]);
	}
	int lst(0);
	vector<int> vec;
	int mn(0);
	for(int i(1); i <= k; i++) {
		int x;
		scanf("%d", &x);
		vec.push_back(x);
	}
	vec.push_back(0);
	vec.push_back(s);
	sort(vec.begin(), vec.end());
	int le(1), ri(2 * s + 1);
	while(le != ri) {
		int mid((long long)le + ri >> 1);
		long long tim(0);
		for(int i(0); i + 1 < (int)vec.size(); i++) {
			int x(vec[i + 1] - vec[i]);
			if(mid < x) {
				tim = 2e9 + 1;
				break;
			}
			tim += (mid >= 2 * x ? x : (mid - x) + 2 * (x - (mid - x)));
		}
		if(tim > t) {
			le = mid + 1;
		}else {
			ri = mid;
		}
	}
	int ans;
	if(t < s) {
		ans = -1;
	}else {
		ans = 2e9;
		for(int i(1); i <= n; i++) {
			if(c[i] >= le) {
				ans = min(ans, p[i]);
			}
		}
		if(ans == 2e9) {
			ans = -1;
		}
	}
	cout << ans <<endl;
}