#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18, maxn = 10;
pair<int, int> p[3];
vector<pair<pair<int, int>, pair<int, int> > > vec;
long long ans = 1e18;
signed main() {
	for(int i = 0; i < 3; ++ i)
		scanf("%lld%lld", &p[i].first, &p[i].second);
	sort(p, p + 3);
	do {
		int x = p[0].first, y = p[0].second;
		int mnx = min(p[1].first, p[2].first), mxx = max(p[1].first, p[2].first);
		mnx = min(mnx, x), mxx = max(mxx, x);
		long long res = mxx - mnx + abs(p[1].second - y) + abs(p[2].second - y);
		if(ans > res) {
			ans = res;
			vec.clear();
			// vec.push_back({{mnx, mxx}, y});
			if(mnx != mxx)
				vec.push_back({{mnx, y}, {mxx, y}});
			// vec.push_back({{p[1].second, y}, p[1].first});
			if(p[1].second != y)
				vec.push_back({{p[1].first, p[1].second}, {p[1].first, y}});
			// vec.push_back({{p[2].second, y}, p[2].first});
			if(p[2].second != y)
				vec.push_back({{p[2].first, p[2].second}, {p[2].first, y}});
		}
		int mny = min(p[1].second, p[2].second), mxy = max(p[1].second, p[2].second);
		mny = min(mny, y), mxy = max(mxy, y);
		res = mxy - mny + abs(p[1].first - x) + abs(p[2].first - x);
		if(ans > res) {
			ans = res;
			vec.clear();
			// vec.push_back({{mny, mxy}, x});
			if(mny != mxy)
				vec.push_back({{x, mny}, {x, mxy}});
			// vec.push_back({{p[1].first, x}, p[1].second});
			if(x != p[1].second);
				vec.push_back({{p[1].first, p[1].second}, {x, p[1].second}});
			// vec.push_back({{p[2].first, x}, p[2].second});
			if(x != p[2].second);
				vec.push_back({{p[2].first, p[2].second}, {x, p[2].second}});
		}
	}while(next_permutation(p, p + 3));
// cerr << ans << endl;
	// puts("3");
	printf("%lld\n", (int)vec.size());
	for(int i = 0; i < (int)vec.size(); ++ i)
		printf("%lld %lld %lld %lld\n", vec[i].first.first, vec[i].first.second, vec[i].second.first, vec[i].second.second);
}