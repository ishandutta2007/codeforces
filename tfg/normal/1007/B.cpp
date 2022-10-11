#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

const int ms = 200200;

int f[ms];

long long gcd(long long a, long long b) {
	return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b) {
	return a * gcd(a, b) / b;
}

int wut[8];
int wtf[8];
long long comb[500][500];
int tmp[3];

struct Info {
	int arr[3];
};

bool operator < (const Info &a, const Info &b) {
	for(int i = 0; i < 3; i++) {
		if(a.arr[i] != b.arr[i]) return a.arr[i] < b.arr[i];
	}
	return false;
}

std::set<Info> all;
std::vector<Info> opt;

Info getInfo() {
	Info ans;
	int s = 0;
	for(int i = 0; i < 3; i++) {
		ans.arr[i] = tmp[i];
	}
	std::sort(ans.arr, ans.arr + 3);
	return ans;
}

long long bf(int on = 0, long long choices = 1) {
	//std::cout << "entering " << on << ", " << choices << std::endl;
	if(on == 3) {
		all.insert(getInfo());
		return choices;
	}
	long long ans = 0;
	for(int i = 1; i < 8; i++) {
		if((i & (1 << on)) != 0) {
			//long long bef = comb[wtf[i] - 1 + wut[i]][wtf[i] - 1];
			wut[i]++;
			//long long aft = comb[wtf[i] - 1 + wut[i]][wtf[i] - 1];
			tmp[on] = i;
			ans += bf(on + 1);
			wut[i]--;
		}
	}
	return ans;
}

long long special(int sum, int k) {
	if(k == 0 && sum > 0) return 0;
	else return comb[sum + k - 1][sum];
}

int main() {
	for(int i = 0; i < 500; i++) {
		for(int j = 1; j <= i; j++) {
			comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
		}
		comb[i][0] = 1;
	}
	bf();
	for(auto v : all) {
		opt.push_back(v);
	}
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	for(int i = 1; i < ms; i++) {
		for(int j = i; j < ms; j += i) {
			f[j]++;
		}
	}
	int t;
	std::cin >> t;
	while(t--) {
		int nums[3];
		for(int i = 0; i < 3; i++) {
			std::cin >> nums[i];
		}
		for(int i = 0; i < 8; i++) {
			wtf[i] = 0;
			for(int j = 0; j < 3; j++) {
				if(i & (1 << j)) {
					wtf[i] = gcd(wtf[i], nums[j]);
				}
			}
			wtf[i] = f[wtf[i]];
		}
		for(int len = 1; len < 8; len += len) {
			for(int i = 0; i < 8; i += 2 * len) {
				for(int j = 0; j < len; j++) {
					wtf[i + j] -= wtf[i + j + len];
				}
			}
		}
		/*for(int i = 0; i < 8; i++) {
			std::cout << "(" << wtf[i] << ", " << wut[i] << ")" << (i == 7 ? '\n' : ' ');
		}*/
		long long ans = 0;
		for(auto v : opt) {
			if(v.arr[0] == v.arr[1] && v.arr[1] == v.arr[2]) {
				ans += special(3, wtf[v.arr[0]]);
			} else if(v.arr[0] == v.arr[1]) {
				ans += (long long) special(2, wtf[v.arr[0]]) * wtf[v.arr[2]];
			} else if(v.arr[1] == v.arr[2]) {
				ans += (long long) special(2, wtf[v.arr[2]]) * wtf[v.arr[0]];
			} else {
				ans += (long long) wtf[v.arr[0]] * wtf[v.arr[1]] * wtf[v.arr[2]];
			}
		}
		std::cout << ans << std::endl;
	}
}