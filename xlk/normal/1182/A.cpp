#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	cin >> n;
	cout << (n & 1 ? 0 : 1 << n / 2) << endl;
	return 0;
}