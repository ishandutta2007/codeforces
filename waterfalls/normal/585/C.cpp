#include <bits/stdc++.h>
using namespace std;

int main() {
	long long x,y;
	cin >> x >> y;
	if (__gcd(x,y)>1) return cout << "Impossible", 0;
	int w = 0;
	while (x!=y) {
		if (x<y) swap(x,y), w = 1-w;
		cout << (x-1)/y << (w?'B':'A');
		x = 1+(x-1)%y;
	}
}