#include <iostream>
#include <algorithm>
using namespace std;

struct card {
	int v;
	bool taken;
};

int main() {
	int n;
	card c[100];
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> c[i].v;
		sum += c[i].v;
		c[i].taken = false;
	}

	int e = sum / (n / 2);
	for (int i = 0; i < n; ++i) {
		if (!c[i].taken) {
			for (int j = i + 1; j < n; ++j) {
				if (c[j].v == e - c[i].v && !c[j].taken) {
					cout << i + 1 << ' ' << j + 1 << endl;
					c[j].taken = true;
					break;
				}
			}
		}
	}
	return 0;
}