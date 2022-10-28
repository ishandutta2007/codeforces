#include <bits/stdc++.h> 
using namespace std;

bool lose(long long s, long long e) {
	if (s > e) {
		return false;
	}

	if (e < s * 2) {
		return true;
	} else if (e % 2) {
		return lose(s, e - 1);
	}

	if (s % 2) {
		if (e < s * 4) {
			return !(e / 2 % 2);
		}
		return e % 4 == 0 && lose(s, e / 4);
	} else {
		if (e < s * 2) {
			return true;
		} else if (e < s * 4) {
			return e / 2 % 2;
		}
		return e % 4 || lose(s, e / 4);
	}
}

bool _lose(int s, int e) {
	if (s * 2 > e) {
		return true;
	}
	bool res = false;
	for (int i : {s + 1, s * 2}) {
		res |= lose(i + 1, e) && lose(i * 2, e) && i * 2 <= e;
	}
	return res;
}

bool win(long long s, long long e) {
	if (s > e) {
		return true;
	}

	if (s % 2) {
		if (e % 2) {
			return false;
		} else if (e < s * 4) {
			return true;
		}
	} else {
		if (e % 2) {
			return true;
		} else if (e < s * 2) {
			return false;
		}
	}
	return win(s, e / 4);
}

bool _win(int s, int e) {

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	array<bool, 2> pre = {true, false};
	while (t--) {
		long long s, e;
		cin >> s >> e;
		
		array<bool, 2> cur = {false, false};
		if (pre[0]) {
			cur[0] |= lose(s, e);
			cur[1] |= win(s, e);
		}
		if (pre[1]) {
			cur[0] |= lose(s * 2, e) && lose(s + 1, e);
			cur[1] |= win(s * 2, e) && win(s + 1, e);
		}
		pre = cur;
	}

	cout << pre[1] << " " << pre[0] << "\n";
}