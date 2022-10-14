#include <bits/stdc++.h>

using namespace std;


typedef long long ll;

#define vt vector
#define all(x) x.begin(), x.end()
#define trav(i, x) for(auto &i : x)
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define eb emplace_back


vector<int> ans;
int l, r;
int n;
bool canDo(int from) {
	deque<int> f;
	for(int i = from; i < n; i++) {
		f.push_back(ans[i]);
	}
	
	vector<int> complete;
	while(f.size()) {
		if(f.front() < f.back()) {
			complete.push_back(f.front());
			f.pop_front();
		} else {
			complete.push_back(f.back());
			f.pop_back();
		}
	}
	
	return is_sorted(all(complete));
}
void solve() {
	scanf("%d", &n);
	ans.resize(n);
	trav(i, ans) scanf("%d", &i);
	l=0,r=n-1;
	int ans = 0;
	while(l < r) {
		int mid = (l+r)/2;
		if(canDo(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	ans = l;
	printf("%d\n", ans);
	
}
int main() {

	int t = 1, i = 1;
	scanf("%d", &t);
	while(t--) {
		// printf("Case #%d: ", i)
		solve();
		i++;
	}
}