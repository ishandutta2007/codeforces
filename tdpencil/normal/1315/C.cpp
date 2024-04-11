#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define nl "\n"
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;



template <class T>
bool umin(T &x, T y) {
	if (x > y)
	{
		x = y;
		return 1;
	}
	return 0;
}
template <class T>
bool umax(T &x, T y) {
	if (x < y)
	{
		x = y;
		return 1;
	}
	return 0;
}
bool cmp(int a, int b) {
	return abs(a) > abs(b);
}
void solve() {
	// strategy
	// you want to find the lexiographically minimal permutation
	// so ideally a[i], a[i + 1] minimize a[i + 1] as long as its not used

	set<int> p;
	int n; cin >> n;
	vi a(n);
	rep(i,1,2*n+1) {
		p.insert(i);
	}

	for(int i=0;i<n;i++) {
		cin >> a[i];
		p.erase(a[i]);
	}
	vector<pii> ops;
	for(int i=0;i<n;i++) {
		auto it=p.lower_bound(a[i]);
		if(it==p.end()) {
			cout << -1 << "\n";
			return;
		}
		ops.emplace_back(a[i], *it);
		p.erase(it);
	}

	for(int i=0;i<n;i++) {
		cout << ops[i].first << " " << ops[i].second << " ";
	}
	cout << "\n";


}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    int t = 1;
	cin >> t;
    while(t--) {
        solve();
    }
}