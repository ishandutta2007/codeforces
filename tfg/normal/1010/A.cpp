#include <iostream>
#include <iomanip>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cout << std::fixed << std::setprecision(20);
	int n, m;
	int ones = 0;
	std::cin >> n >> m;
	std::vector<int> a(n);
	std::vector<int> b(n);
	std::vector<long double> r(n + 1, 1);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		if(a[i] == 1) ones++;
	}
	for(int i = 0; i < n; i++) {
		std::cin >> b[i];
		if(b[i] == 1) ones++;
	}
	long double ans = m;
	for(int i = 0; i < n; i++) {
		if(a[i] != 1) {
			ans *= (long double) (a[i]) / (a[i] - 1);
		}
		if(b[i] != 1) {
			ans *= (long double) (b[i]) / (b[i] - 1);
		}
	}
	if(ones) {
		std::cout << "-1\n";
	} else {
		std::cout << ans - m << std::endl;
	}
	/*for(int i = 0; i < n; i++) {
		r[i + 1] = r[i];
		if(a[i] != 1) {
			r[i + 1] *= (long double) (a[i]) / (a[i] - 1);
		}
		if(b[i] != 1) {
			r[i + 1] *= (long double) (b[i]) / (b[i] - 1);
		}
	}
	long double ans = 2e9;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i == j) continue;
			int get = 0;
			if(b[i] == 1) get++;
			if(a[j] == 1) get++;
			if(get < ones) continue;
			std::cout << "trying " << i << ", " << j << std::endl;
			long double cur_ans = m;
			int ll = std::min(i, j);
			int rr = std::max(i, j);
			cur_ans *= r[ll];
			cur_ans *= r[rr] / r[ll+1];
			cur_ans *= r[n] / r[rr+1];
			cur_ans *= (long double) (a[i]) / (a[i] - 1);
			cur_ans *= (long double) (b[j]) / (b[j] - 1);
			ans = std::min(ans, cur_ans);
			std::cout << "result is " << (double) cur_ans << std::endl;
		}
	}
	if(ans < 1.1e9) {
		std::cout << (double) ans << std::endl;
	} else {
		std::cout << "-1\n";
	}*/
}