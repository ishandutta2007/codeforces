#include <iostream>
#include <algorithm>
using namespace std;

bool zsort(int);

int a[1000];
int tmp[1000];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a + n);
	if (zsort(n)) {
		for (int i = 0; i < n; ++i) {
			cout << tmp[i] << ' ';
		}
	} else {
		cout << "Impossible";
	}
	return 0;
}

bool zsort(int n) {
	int i = 0; int j = n - 1;
	int t = 1;
	int k = 0;
	while (t <= n) {
		if (t % 2 == 1) {
			tmp[k++] = a[i++];	
		} else {
			tmp[k++] = a[j--];
		}
		t++;
	}
	return true;
}