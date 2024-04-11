#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i <= b; i++)
 
using namespace std;
 
const int N = 300111;
 
int n, q, a[N], l[N], r[N], ans[N], cnt[N], p[N];
 
int main() {
	cin >> n >> q;
	rep(i,1,n) cin>>a[i];
	rep(i,1,q) {
		cin>>l[i]>>r[i];
		if(r[i] - l[i] <= 800) {
			rep(j,l[i],r[i]) 
				ans[i]=max(ans[i], ++cnt[a[j]]);
			rep(j,l[i],r[i])
				cnt[a[j]]--;
		}
	}
	rep(i,1,n)cnt[a[i]]++;
	rep(i,1,n) {
		if(cnt[i] >= 400) {
			memset(p, 0, sizeof p);
			rep(j,1,n)
				p[j] = p[j-1] + (a[j] == i);
			rep(j,1,q)
				ans[j] = max(ans[j], p[r[j]] - p[l[j] - 1]);
		}
	}
	rep(i,1,q) cout << max(1, ans[i] - (r[i] - l[i] + 1 - ans[i])) << endl;
	return 0;
}