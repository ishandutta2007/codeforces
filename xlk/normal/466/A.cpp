#include <bits/stdc++.h>
using namespace std;
int n, m, a, b;
int main()
{
	cin >> n >> m >> a >> b;
	cout << min(n * a, min(n / m * b + n % m * a, n / m * b + b)) << endl;
	return 0;
}