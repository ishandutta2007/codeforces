#include <iostream>
using namespace std;

int card[5];

int count(int n) {
	int cnt = 0;
	for (int i = 0; i < 5; ++i) {
		if (card[i] == n) {
			cnt++;
		}
	}
	return cnt;
}

int main() {
	int sum = 0;	
	for (int i = 0; i < 5; ++i) {
		cin >> card[i];
		sum += card[i];
	}
	int min = sum;
	int r;
	for (int i = 0; i < 5; ++i) {
		r = 0;
		int cnt = count(card[i]);
		if (cnt <= 3 && cnt > 1) {
			r = sum - card[i] * cnt;
			if (r < min) min = r;
		} else if (cnt > 3) {
			r = sum - card[i] * 3;
			if (r < min) min = r;
		}
	}
	cout << min << endl;
	return 0;
}