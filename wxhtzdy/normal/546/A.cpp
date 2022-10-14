#include <bits/stdc++.h>

using namespace std;

int main() {
	long long k, n, w;
	cin >> k >> n >> w;
	w = (w * (w + 1)) / 2;
	cout << max((long long) 0, k * w - n); 
}