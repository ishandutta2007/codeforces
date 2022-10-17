#include <iostream>
#include <algorithm>
using namespace std;

int a[1000];
int n;
int happy;

void greedy(int num[], int len) {
	if (len > 0) {
		int cur = num[0];
		int tmp[1000];
		int tlen = 0;
		int ti = 0;
		for (int i = 1; i < len; ++i) {
			if (num[i] > cur) {
				happy++;
				cur = num[i];
			} else {
				tmp[ti++] = num[i];
				tlen++;
			}
		}
		greedy(tmp, tlen);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a + n);
	happy = 0;
	greedy(a, n);
	cout << happy << endl;
	return 0;
}