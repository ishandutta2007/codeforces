#include <bits/stdc++.h>
using namespace std;
int main() {
	long long n, k;
	cin >> n >> k;
	puts(n / k % 2 ? "YES" : "NO");
	return 0;
}