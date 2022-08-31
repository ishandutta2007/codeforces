#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int n, m, k;

int main()
{
	cin >> k >> m >> n;
	cout << max(0, k * n * (n + 1) / 2 - m) << endl;

	return 0;
}