#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	long long s, x;
	cin >> s >> x;
	long long bs = s, bx = x;
	long long cnt0 = 1, cnt1 = 0;
	while (s || x) {
		long long ds = s & 1, dx = x & 1;
		s >>= 1, x >>= 1;
		long long ncnt0, ncnt1;
		if (dx == 1) {
			if (ds == 0) {
				ncnt1 = cnt1 * 2;
				ncnt0 = 0;
			} else {
				ncnt0 = cnt0 * 2;
				ncnt1 = 0;
			}
		} else {
			if (ds == 0) {
				ncnt0 = cnt0;
				ncnt1 = cnt0;
			} else {
				ncnt0 = cnt1;
				ncnt1 = cnt1;
			}
		}
		cnt0 = ncnt0;
		cnt1 = ncnt1;
	}
	long long ans = cnt0;
	if (bs == bx) {
		ans -= 2;
	}
	cout << ans << endl;
	return 0;
}