#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int p[3];
string s[3];
int q[300000];

string calc (string a, string b) {
	int n = a.size (), m = b.size ();
	int k = n + m + 1;
	string c = a + '$' + b;
	q[0] = -1;
	for (int i = 1; i < k; i++) {
		int t = q[i - 1];
		while (t != -1 && c[t + 1] != c[i]) t = q[t];
		if (c[t + 1] == c[i]) t++;
		q[i] = t;
	}
	for (int i = n + 1; i < k; i++)
		if (q[i] + 1 == n)
			return b;
	return b.substr (0, m - q[k - 1] - 1) + a;
}

int main() {
	int ans = 1e9;
	for (int i = 0; i < 3; i++) {
		p[i] = i;
		cin >> s[i];
	}
	do ans = min (ans, int (calc (calc (s[p[0]], s[p[1]]), s[p[2]]).size ())); while (next_permutation (p, p + 3));
	printf ("%d\n", ans);
	return 0;
}