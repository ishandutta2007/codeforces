#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9 + 7;

template <class T>
T fexp(T x, long long e) {
	T ans(1);
	for(; e > 0; e /= 2) {
		if(e & 1) ans = ans * x;
		x = x * x;
	}
	return ans;
}

template <int mod = MOD>
struct modBase {
	modBase(int v = 0) : val((v%mod+mod)%mod) {}
	int val;

	modBase<mod> operator * (modBase<mod> o) { return (long long) val * o.val % mod; }
	modBase<mod> operator / (modBase<mod> o) { return *this * fexp(o, mod - 2); }
	modBase<mod> operator + (modBase<mod> o) { return val + o.val > mod ? val + o.val - mod : val + o.val; }
	modBase<mod> operator - (modBase<mod> o) { return val - o.val < 0 ? val - o.val + mod : val - o.val; }
};

template <int mod = MOD>
void gaussianElimination(std::vector<std::vector<modBase<mod>>> &a) {
	int n = (int) a.size();
	int m = (int) a[0].size();
	int c = 0;
	for(int i = 0; i < m; i++) {
		bool valid = false;
		for(int ii = c; ii < n; ii++) {
			if(a[ii][i].val != 0) {
				std::swap(a[ii], a[c++]);
				valid = true;
				break;
			}
		}
		if(!valid) {
			continue;
		}
		modBase<mod> l = modBase<mod>(1) / a[c-1][i];
		for(int j = 0; j < m; j++) {
			a[c-1][j] = a[c-1][j] * l;
		}
		for(int ii = 0; ii < n; ii++) {
			if(ii != c-1) {
				l = a[ii][i];
				for(int j = 0; j < m; j++) {
					a[ii][j] = a[ii][j] - a[c-1][j] * l;
				}
			}
		}
	}

}

int mat[4][4];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::vector<int> a;
	for(int i = 0; i < 4; i++) {
		for(int j = i+1; j < 4; j++) {
			std::cin >> mat[i][j];
			mat[j][i] = mat[i][j];
			a.push_back(mat[i][j]);
		}
	}
	std::vector<std::vector<int>> wtf;
	for(int i = 1; i < 8; i++) {
		std::vector<int> cur;
		for(int j = 0; j < 4; j++) {
			for(int k = j+1; k < 4; k++) {
				int b1 = (i>>j)&1;
				int b2 = (i>>k)&1;
				cur.push_back(b1^b2);
			}
		}
		wtf.push_back(cur);
	}
	int ans = 1e9;
	std::vector<int> kek;
	for(int i = 0; 1; i++) {
		std::vector<std::vector<modBase<>>> syst(6, std::vector<modBase<>>(7, 0));
		for(int j = 1; j < (int) wtf.size(); j++) {
			for(int k = 0; k < 6; k++) {
				syst[k][j-1] = wtf[j][k];
			}
		}
		bool valid = true;
		for(int j = 0; j < 6; j++) {
			syst[j][6] = a[j] - i * wtf[0][j];
			valid = valid && a[j] - i * wtf[0][j] >= 0;
		}
		if(!valid) break;
		gaussianElimination(syst);
		int sum = i;
		for(int j = 0; j < 6; j++) {
			valid = valid && syst[j][j].val == 1 && syst[j][6].val <= (int)1e5;
			sum += syst[j][6].val;
		}
		if(valid && sum < ans) {
			ans = sum;
			kek.clear();
			kek.push_back(i);
			for(int j = 0; j < 6; j++) {
				kek.push_back(syst[j][6].val);
			}
		}
	}
	if(kek.empty()) {
		std::cout << "-1\n";
	} else {
		std::vector<std::string> strs(4);
		for(int i = 1; i < 8; i++) {
			while(kek[i-1]--) {
				for(int j = 0; j < 4; j++) {
					strs[j] += char('a'+(i>>j)%2);
				}
			}
		}
		std::cout << ans << '\n';
		for(auto str : strs) {
			std::cout << str << '\n';
		}
	}
}