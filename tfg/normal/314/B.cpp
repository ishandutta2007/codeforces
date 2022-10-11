#include <iostream>
#include <vector>

typedef std::vector<std::vector<int> > vii;

vii combine(vii a, vii b) {
	for(int i = 0; i < a.size(); i++) {
		for(int j = 0; j < a[i].size(); j++) {
			a[i][j] += b[i][(j + a[i][j]) % a[i].size()];
		}
	}
	return a;
}

int fexp(vii x, int e) {
	vii ans = x;
	for(int i = 0; i < ans.size(); i++) {
		for(int j = 0; j < ans[i].size(); j++) {
			ans[i][j] = 0;
		}
	}
	for(; e > 0; e /= 2) {
		if(e & 1) {
			ans = combine(ans, x);
		}
		x = combine(x, x);
	}
	return ans[0][0];
}

int main() {
	int b, d;
	std::cin >> b >> d;
	std::string s1, s2;
	std::cin >> s1 >> s2;
	vii base(s1.size());
	for(int i = 0; i < s1.size(); i++) {
		for(int k = 0; k < s2.size(); k++) {
			base[i].push_back(0);
			for(int j = i; j < s1.size(); j++) {
				if(s1[j] == s2[(base[i][k] + k) % s2.size()]) {
					base[i][k]++;
				}
			}
		}
	}
	std::cout << fexp(base, b) / s2.size() / d << '\n';
}