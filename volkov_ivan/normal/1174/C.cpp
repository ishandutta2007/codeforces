#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 7;

bool is_prime(int n) {
	int i = 2;
	while (i * i <= n) {
		if (n % i == 0) return 0;
		i++;
	}
	return 1;
}

int to_num[MAX_N];

int fact(int n) {
	int i = 2;
	while (i * i <= n) {
		if (n % i == 0) return i;
		i++;
	}
	return n;
}

int main() {
	//freopen("Desktop/input.txt", "r", stdin);
	int n;
	cin >> n;
	int c = 1;
	for (int i = 2; i <= n; i++) {
		if (is_prime(i)) {
			to_num[i] = c++;
		}
	}
	for (int i = 2; i <= n; i++) {
		cout << to_num[fact(i)] << ' ';
	}
	cout << endl;
	return 0;
}