#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int me = 11;
const int ms = 23;

template <int mod = 998244353>
struct modBase {
	modBase(int v = 0) : val(v) {}
	int val;
 
	void operator += (modBase<mod> o) { *this = *this + o; }
	void operator -= (modBase<mod> o) { *this = *this - o; }
	void operator *= (modBase<mod> o) { *this = *this * o; }
	modBase<mod> operator * (modBase<mod> o) { return (long long) val * o.val % mod; }
	//modBase<mod> operator / (modBase<mod> o) { return *this * fexp(o, mod - 2); }
	modBase<mod> operator + (modBase<mod> o) { return val + o.val >= mod ? val + o.val - mod : val + o.val; }
	modBase<mod> operator - (modBase<mod> o) { return val - o.val < 0 ? val - o.val + mod : val - o.val; }
};

std::vector<std::string> a[me];

int getSize(int x) {
	if(x < 10) return 1;
	else return 1 + getSize(x / 10);
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	while(n--) {
		std::string str;
		std::cin >> str;
		a[str.size()].push_back(str);
	}
	modBase<> tot;
	for(int i = 0; i < me; i++) {
		for(auto str : a[i]) {
			for(int o = 1; o < me; o++) {
				int freq = (int) a[o].size();
				if(!freq) continue;
				// solve this being first
				modBase<> ans;
				ans = 0;
				for(int j = 0; j < i; j++) {
					ans = ans * 10 + str[j] - '0';
					if(i - j <= o) {
						ans = ans * 10;
					}
				}
				//std::cout << str << " for " << o << " got " << ans.val << '\n';
				tot += ans * freq;
				ans = 0;
				// solve second
				for(int j = 0; j < i; j++) {
					if(i - j <= o) {
						ans = ans * 10;
					}
					ans = ans * 10 + str[j] - '0';
				}
				//std::cout << str << " for " << o << " got " << ans.val << '\n';
				tot += ans * freq;
			}
		}
	}
	std::cout << tot.val << '\n';
}