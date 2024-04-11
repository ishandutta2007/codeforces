#include <iostream>

using namespace std;

int main() {
	//freopen("/Users/ivanvolkov/Desktop/inp.in", "r", stdin);
	long long n;
	cin >> n;
	long long i = 2, res = -1;
	while (i * i <= n) {
		if (n % i == 0) {
			res = i;
			break;
		}
		i++;
	}
	if (res == -1) {
		cout << 1 << endl;
		return 0;
	}
	cout << 1 + (n - res) / 2 << endl;	
	return 0;
}