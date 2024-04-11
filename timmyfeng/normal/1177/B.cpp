#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long k;
	cin >> k;
	--k;
	long long cur = 9;
	long long base = 1;
	int i = 1;
	while (true) {
		if (k >= cur) {
			k -= cur;
		} else {
			long long num = base + k / i;
			long long place = i - k % i;
			while (place > 1) {
				num /= 10;
				--place;
			}
			cout << num % 10 << '\n';
			return 0;
		}
		cur = cur / i * 10 * (i + 1);
		base *= 10;
		++i;
	}
}