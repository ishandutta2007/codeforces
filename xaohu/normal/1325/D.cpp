#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
 
using namespace std;

long long xo, sum;		

int main() {
	cin >> xo >> sum;
	if (xo > sum || (sum - xo) % 2) 
		return cout << "-1\n", 0;
	if (xo == sum) {
		if (!xo)
			return cout << "0\n", 0;
		return cout << "1\n" << xo << "\n", 0;
	}
	long long common = (sum - xo) / 2;
	if ((xo & common) == 0) 
		return cout << "2\n" << common << " " << common + xo << "\n", 0;
	cout << "3\n" << xo << " " << common << " " << common << "\n";
	return 0;
}