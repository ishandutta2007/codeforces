#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	long long a, b, ans;
	cin >> a >> b;
	for (long long k = 0; k <= max(a, b); k++) {
		long long s = k * (k + 1) / 2;
		if (s > a + b) {
			ans = k - 1;
			break;
		}
		if (k == max(a, b)) {
			ans = k;
			break;
		}
	}
	vector <long long> fi, se;
	bool swapped = 0;
	if (b > a) {
		swap(a, b);
		swapped = 1;
	}
	long long now = ans;
	while (a >= now && now >= 1) {
		fi.push_back(now);
		a -= now;
		now--;
	}
	long long add = -1;
	if (a != 0 && now != 0) {
		add = a;
		fi.push_back(add);
	}
	while (now > 0) {
		if (now != add) se.push_back(now);
		now--;
	}
	if (swapped) swap(fi, se);
	cout << fi.size() << endl;
	for (long long elem : fi) cout << elem << ' ';
	cout << endl;
	cout << se.size() << endl;
	for (long long elem : se) cout << elem << ' ';
	cout << endl;
	return 0;
}