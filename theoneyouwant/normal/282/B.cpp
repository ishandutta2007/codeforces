#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, t = 0, a, b; 
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		if (t + a <= 500)
			t += a,
			cout << 'A';
		else
			t -= b, cout << 'G';
	}
	cout << endl;
	return 0;
}