#include <iostream>
#include <string>
using namespace std;

int n;
string a[500020];
int lcp(string a, string b) {
	for (int i = 0; i < a.size() && i < b.size(); i++) {
		if (a[i] != b[i]) {
			return i;
		}
	}
	return min(a.size(), b.size());
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = n - 2; i >= 0; i--) {
		if (a[i] > a[i + 1]) {
			a[i] = a[i].substr(0, lcp(a[i], a[i + 1]));
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << endl;
	}
	return 0;
}