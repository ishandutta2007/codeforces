#include <bits/stdc++.h>

using namespace std;

int main() {                                 
	int n, k;
	cin >> n >> k;
	int res = 1;
	int curr = n;
	while ((curr - k) % 10 != 0 && curr % 10 != 0) {
	 	curr += n;
	 	res++;
 	}
 	cout << res;
}