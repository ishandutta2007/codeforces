#include <iostream>
#include <map>
#include <cstring>
#include <cstdio>
#include <utility>
#include <algorithm>

typedef long long ll;

const int ms = 500500;

int t[ms], x[ms];

struct BIT {
	ll bit[ms];

	ll qry(int x) {
		ll ans = 0;
		for(; x > 0; x -= x & -x) {
			ans += bit[x];
		}
		return ans;
	}

	void upd(int x, ll v) {
		for(; x < ms; x += x & -x) {
			bit[x] += v;
		}
	}

	BIT() {
		memset(bit, 0, sizeof bit);
	}
};

BIT fw[2];
int vals[ms];
int pos[ms];
std::pair<int, int> nums[ms];

int main() {
	int q;
	std::cin >> q;
	int c = 0;
	for(int i = 0; i < q; i++) {
		scanf("%i", t + i);
		//std::cout << "on query " << i << " type is " << t[i] << "\n";
		if(t[i] == 1) {
			scanf("%i", x + i);
			nums[c++] = std::pair<int, int>(x[i], i);
		}
	}
	std::sort(nums, nums + c);
	for(int i = 0; i < c; i++) {
		pos[nums[i].second] = i + 1;
	}
	int m = 0;
	int val = 0;
	for(int i = 0; i < q; i++) {
		if(t[i] == 1) {
			m = std::max(pos[i] + 1, m);
			val = std::max(val, x[i]);
			//std::cout << m << '\n';
			fw[0].upd(pos[i], 1);
			fw[1].upd(pos[i], x[i]);
		} else {
			int l = 0, r = m - 1;
			while(l != r) {
				int mid = (l + r) / 2;
				if((double)(fw[1].qry(mid) + val) / (fw[0].qry(mid) + 1) >= (double)(fw[1].qry(mid + 1) + val) / (fw[0].qry(mid + 1) + 1)) {
					l = mid + 1;
				} else {
					r = mid;
				}
			}
			printf("%.10f\n", (double)val - (double)(val + fw[1].qry(l)) / (1 + fw[0].qry(l)));
			//std::cout << val - (double)(val + fw[1].qry(l)) / (1 + fw[0].qry(l)) << '\n';
		}
	}
}