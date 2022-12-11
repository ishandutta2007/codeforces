#include <iostream>
#include <ctime>
#include <time.h>

using namespace std;

long long b1 = 127, b2 = 131, M1 = 1e9 + 7, M2 = 1e9 + 9;
const int MAX_N = 1e6 + 7;
long long h1[MAX_N], h2[MAX_N], pow1[MAX_N], pow2[MAX_N];

long long mod(long long x, long long m) {
	x %= m;
	if (x < 0) x += m;
	return x;
}

pair <long long, long long> get_substr_h(int l, int r) {
	return make_pair(mod(h1[r] - h1[l - 1] * pow1[r - l + 1], M1), mod(h2[r] - h2[l - 1] * pow2[r - l + 1], M2));
}

int main() {
	srand(time(0));
	if (rand() % 2) swap(b1, b2);
	pow1[0] = pow2[0] = 1;
	for (int i = 1; i < MAX_N; i++) {
		pow1[i] = (pow1[i - 1] * b1) % M1;
		pow2[i] = (pow2[i - 1] * b2) % M2;
	}
	string s, t;
	cin >> s >> t;
	h1[0] = h2[0] = 0;
	for (int i = 1; i <= t.length(); i++) {
		h1[i] = (h1[i - 1] * b1 + (t[i - 1] - 'a' + 1)) % M1;
		h2[i] = (h2[i - 1] * b2 + (t[i - 1] - 'a' + 1)) % M2;
	}
	long long ans = 0, one = 0, zero = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '0') zero++;
		else one++;
	}
	for (long long l = 1; l < t.length(); l++) {
		if ((l * zero < t.length()) && ((((int) t.length()) - l * zero) % one == 0)) {
			int r = (((int) t.length()) - l * zero) / one;
			pair <long long, long long> eq_h_zero = make_pair(-1, -1), eq_h_one = make_pair(-1, -1);	
			int now_pos = 1;
			bool flag = 1;
			for (int i = 0; i < s.length(); i++) {
				if (s[i] == '0') {
					if (eq_h_zero == make_pair(-1ll, -1ll)) {
						eq_h_zero = get_substr_h(now_pos, now_pos + l - 1);
						now_pos += l;
						continue;
					}
					if (get_substr_h(now_pos, now_pos + l - 1) != eq_h_zero) {
						flag = 0;
						break;
					}
					now_pos += l;
				} else {
					if (eq_h_one == make_pair(-1ll, -1ll)) {
						eq_h_one = get_substr_h(now_pos, now_pos + r - 1);
						now_pos += r;
						continue;
					}
					if (get_substr_h(now_pos, now_pos + r - 1) != eq_h_one) {
						flag = 0;
						break;
					}
					now_pos += r;
				}
			}
			if (eq_h_zero == eq_h_one) flag = 0;
			if (flag) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}