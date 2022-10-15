/**
1 1
**/
#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	int64_t A[2];
	cin >> A[1] >> A[0];
	int64_t n = 1;
	while (true)
	{
		A[n % 2] -= n;
		if (A[n % 2] < 0)
		{
			cout << (n % 2 == 1 ? "Vladik" : "Valera");
			return 0;
		}
		n++;
	}
	return 0;
}