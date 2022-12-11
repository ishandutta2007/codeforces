#include <iostream>
#include <vector>

using namespace std;

int k;
vector <int> arr;

bool poss(int len) {
	int now = 0, cnt = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] > len) {
			return false;
		}
		if (now + arr[i] <= len) {
			now += arr[i];
		} else {
			now = arr[i];
			cnt++;
		}
	}
	if (now != 0) {
		cnt++;
	}
	return cnt <= k;
}

int main() {
	string s, now;
	cin >> k;
	while (cin >> now) {
		s += now + ' ';
	}
	s.pop_back();
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ' || s[i] == '-') {
			arr.push_back(cnt + 1);
			cnt = 0;
		} else {
			cnt++;
		}
	}
	arr.push_back(cnt);
	int left = 0, right = s.size(), mid;
	while (right - left > 1) {
		mid = (left + right) / 2;
		if (poss(mid)) {
			right = mid;
		}
		else {
			left = mid;
		}
	}
	cout << right << endl;
	return 0;
}