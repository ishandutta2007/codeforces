#include <bits/stdc++.h>
#ifdef LOC
#define deb _deb
#else
#define deb(...)
#endif
#define x  first
#define y second
#define mp make_pair
#define pb push_back
#define sz(x)int((x).size())
#define each(a,x)for(auto&a:(x))
#define all(x)(x).begin(),(x).end()
#define rep(i,b,e)for(int i=(b);i<(e);i++)
#define tem template<class t,class u,class...w>
#define DBP(...)void print(...){DD(#__VA_ARGS__,__VA_ARGS__);}
#define pri(y)tem auto operator<<(t&o,u a)->decltype(y(a),o){return o<<
#define _deb(...)(DD("#, "#__VA_ARGS__,__LINE__,__VA_ARGS__),cerr<<endl)
using ll=long long;pri(a.print)"{",a.print(),o<<"}";}using namespace std;void DD(...){}using Pii=pair<int
,int>;tem void DD(t s,u a,w...k){while(*s&&*s!=',')cerr<<*s++;cerr<<": "<<a<<*s++;DD(s,k...);}pri(all)"["
,[&](){for(auto i : a)o<<i<<", ";}(),o<<"]";}using  Vi=vector<int>;pri(get<1>) "("<<a.x<<", "<<a.y<<")";}
//-----------------------------------------------------------------------------------------------------//

Vi ans;

void brute(unordered_set<int>& nums, int n, int cur) {
	if (n == 0) {
		nums.insert(cur);
		return;
	}

	brute(nums, n-1, cur+1);
	brute(nums, n-1, cur+5);
	brute(nums, n-1, cur+10);
	brute(nums, n-1, cur+50);
}

void precompute() {
	unordered_set<int> nums;
	ans.resize(13);

	rep(n, 1, 13) {
		brute(nums, n, 0);
		ans[n] = sz(nums);
		nums.clear();
	}
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	precompute();

	int n; cin >> n;

	if (n < sz(ans)) {
		cout << ans[n] << endl;
	} else {
		int s = sz(ans);
		ll x = ans[s-1] + ll(n-s+1) * ll(ans[s-1] - ans[s-2]);
		cout << x << endl;
	}
	return 0;
}