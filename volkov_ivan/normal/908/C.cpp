#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>
#include <algorithm>

using namespace std;

vector <pair <long double, long double> > last;
const int MAX_N = 1000, INF = 1e9 + 7;
int xx[MAX_N + 1];
int r;

long double intersect(long double x1, long double x2, long double y) {
	long double smth = 4 * r * r - (x1 - x2) * (x1 - x2);
	if (smth < 0) return -INF;
	return y + sqrt(smth);
}

int main() {
	int n;
	cin >> n >> r;
	for (int i = 0; i < n; i++) {
		cin >> xx[i];
	}
	long double now_y;
	for (int i = 0; i < n; i++) {
		now_y = r;
		for (int j = 0; j < i; j++) {
			if (intersect(last[j].first, xx[i], last[j].second) > now_y) {
				now_y = intersect(last[j].first, xx[i], last[j].second);
			}
		}
		last.push_back(make_pair(xx[i], now_y));
	}
	cout.precision(12);
	for (pair <long double, long double> elem : last) {
		cout << fixed << elem.second << endl;
	}
	return 0;
}