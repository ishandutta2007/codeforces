#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <chrono>
#include <random>
#include <bitset>
#include <functional>
#include <array>
#include <limits>

using namespace std;

int main() {
	int n;
	cin >> n;
	int l = 1;
	int len = n - 1;
	int k = 0;
	// k * n + l <= x < k * n + r 
	while (len > 1) {
		int lenM = len / 2;
		int c = n - (l + lenM);
		cout << "+ " << c << endl;
		int newK;
		cin >> newK;
		if (newK == k) {
			l += c;
			len = lenM;
		} else {
			k = newK;
			l = 0;
			len = len - lenM;
		}
	}
	cout << "! " << k * n + l << endl;
	return 0;
}