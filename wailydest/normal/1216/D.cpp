#include <iostream>
#include <algorithm>
using namespace std;

inline int GCD(int a, int b) {
	while (a && b) {
		if (a > b) a %= b;
		else b %= a;
	}
	return a > 0 ? a : b;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int arr[200000];
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	
	int max = *max_element(arr, arr + n);
	for (int i = 0; i < n; ++i) arr[i] = max - arr[i];
	
	int gcd = arr[0];
	for (int i = 1; i < n; ++i) gcd = GCD(gcd, arr[i]);
	
	long long ppl = 0;
	for (int i = 0; i < n; ++i) ppl += arr[i] / gcd;
	cout << ppl << ' ' << gcd << '\n';
	return 0;
}