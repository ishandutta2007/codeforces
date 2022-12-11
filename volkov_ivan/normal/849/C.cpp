#include <iostream>
#include <vector>

using namespace std;

vector <int> ans;

int my_low(int k) {
	int left = 0;
	int right = k + 5;
	long long mid;
	while (right - left > 1) {
		mid = (right + left) / 2;
		if ((mid * (mid - 1)) / 2 <= k) {
			left = mid;
		} else {
			right = mid;
		}
	}
	return left;
}

void rec(int k) {
	if (k == 0) {
		return;
	}
	int low = my_low(k);
	ans.push_back(low);
	k -= (low * (low - 1)) / 2;
	rec(k);
}

int main() {
	int k;
	cin >> k;
	if (k == 0) {
		cout << "a" << endl;
		return 0;
	}
	rec(k);
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i]; j++) {
			cout << char('a' + i);
		}
	}
	cout << endl;
	return 0;
}