#include <iostream>
#include <math.h>

using namespace std;

double parse(string s) {
	double ans = 0.0;
	for (int i = 0; i < s.size(); i ++) {
		if (s[i] == '.') {
			continue;
		}
		ans *= 10;
		ans += s[i] - '0';
	}
	if (s.size() > 3 && s[s.size() - 3] == '.') {
		ans /= 100;
	}
	return ans;
}

int main() {
	double eps = 0.0001;
	double sum = 0;
	string s;
	cin >> s;
	s += "a";
	string now = "";
	bool rec = false;
	for (int i = 0; i < s.size(); i ++) {
		if (s[i] >= 97) {
			if (rec) {
				sum += parse(now);
			}
			rec = false;
			continue;
		}
		if (! rec) {
			now = "";
		}
		rec = true;
		now += s[i];
	}
	long long x = floor(sum);
	string a = "";
	int k = 0;
	while (x > 0) {
		if (k > 0 && k % 3 == 0) {
			a += '.';
		}
		a += '0' + (x % 10);
		x /= 10;
		k ++;
	}
	for (int i = 0; i < a.size() / 2; i ++) {
		swap(a[i], a[a.size() - i - 1]);
	}
	if (a == "") {
		cout << "0";
	}
	else {
		cout << a;
	}
	if (sum - floor(sum) > eps) {
		string add = ".";
		if ((sum - floor(sum)) * 100 < 10) {
			add += "0";
		}
		cout << add << (sum - floor(sum)) * 100 << endl;
	}
	return 0;
}