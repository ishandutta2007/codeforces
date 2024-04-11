#include <bits/stdc++.h>
using namespace std;
int n, z, r[100], c[100];
char a;
int main()
{
	cin >> n;
	for (int i = 0; i < n * n; i++) {
		cin >> a;
		if (a == 'C') {
			z += r[i / n]++;
			z += c[i % n]++;
		}
	}
	cout << z << endl;
	return 0;
}