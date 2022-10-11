#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <cstring>

typedef long long ll;
typedef std::pair<int, int> ii;

const int MOD = 1e9 + 7;
const int ms = 1 << 18;

int miss[ms + ms];
std::vector<ll> prod[ms + ms];
std::vector<ii> nums[ms + ms];

void upd(int x, int v, int p) {
	x += ms;
	prod[x].push_back(0);
	prod[x].push_back(p);
	nums[x].push_back(ii(v, p));
	for(x /= 2; x > 0; x /= 2) {
		miss[x]--;
		if(miss[x] == 0) {
			int size = nums[x + x].size() + nums[x + x + 1].size();
			nums[x].resize(size);
			prod[x].resize(size + 1);
			prod[x][0] = 0;
			std::merge(nums[x+x].begin(), nums[x+x].end(),
					   nums[x+x+1].begin(), nums[x+x+1].end(),
					   nums[x].begin());
			for(int i = 0; i < size; i++) {
				prod[x][i + 1] = (prod[x][i] + nums[x][i].second) % MOD;
			}
		}
	}
}

int qry(int l, int r, int v) {
	int ans = 0;
	//std::cout << "starting qry " << l << ", " << r << ", " << v << '\n';
	if(l == -1) {
		ans++;
		l = 0;
	}
	for(l += ms, r += ms; l < r; l /= 2, r /= 2) {
		if(l & 1) {
			int idx = std::upper_bound(nums[l].begin(), nums[l].end(), ii(v, 2e9)) - nums[l].begin();
			ans = (ans + prod[l][idx]) % MOD;
			l++;
		}
		if(r & 1) {
			r--;
			int idx = std::upper_bound(nums[r].begin(), nums[r].end(), ii(v, 2e9)) - nums[r].begin();
			ans = (ans + prod[r][idx]) % MOD;
		}
	}
	//std::cout << "qry got " << ans << "\n";
	return ans;
}

int last[1001000];

int main() {
	for(int i = 0; i < ms; i++) {
		miss[i + ms] = 1;
	}
	for(int i = ms - 1; i > 0; i--) {
		miss[i] = miss[i + i] + miss[i + i + 1];
	}
	int n;
	std::cin >> n;
	ll ans = 0;
	memset(last, -1, sizeof last);
	for(int i = 0; i < n; i++) {
		int v;
		scanf("%d", &v);
		int cur = (ll) qry(last[v], i, v) * v % MOD;
		ans = (ans + cur) % MOD;
		upd(i, v, cur);
		last[v] = i;
	}
	std::cout << ans << '\n';
}