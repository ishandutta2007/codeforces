#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(v) int(v.size())
#define vt vector
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()

constexpr ll mod = 1e9+7;
template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
 
    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};
 
template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
 
void io(const string s="") {
	if(s != "") {
		freopen((s+".in").c_str(), "r", stdin);
		freopen((s+".out").c_str(), "w", stdout);
	} else {
		ios_base::sync_with_stdio(false); cin.tie(0);
	}
}
constexpr int mxN = 2e5;
int dp[361][361];

void gogo() {
	int n, k, d; cin >> n >> k >> d;
	vt<int> a(n);
	for(auto &i : a)
		cin >> i;

	int l = 0, r = 0;
	set<int> c;
	map<int, int> cnt;
	while( r < d - 1) {
		c.insert(a[r]);
		cnt[a[r]]++;
		++r;
	}
	int ans = mxN;
	while(r < n) {
		c.insert(a[r]);
		cnt[a[r]]++;
		ans = min(ans, (int)c.size());
		cnt[a[l]]--;
		if(cnt[a[l]] == 0) {
			c.erase(a[l]);
		}
		r++;
		l++;
	}

	cout << ans << "\n";
}
int main() {
	int t; cin >> t;
	for(; t > 0; --t)
		gogo();
}