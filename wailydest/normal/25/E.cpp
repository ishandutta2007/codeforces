#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int z[300001];

void z_function(string &s, int *z, int n) 
{
	z[0] = 0;
	int l = 0, r = 0;
	for (int i = 1; i < n; ++i) {
		z[i] = 0;
		if (i <= r) z[i] = min(r - i + 1, z[i - l]);
		while (z[i] + i < n && s[z[i] + i] == s[z[i]]) ++z[i];
		if (i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}
	}
}

string combine(string &a, string &b) 
{
	int na = a.size();
	int nb = b.size();
	string s = b + '$' + a;
	z_function(s, z, na + nb + 1);
	int common = 0;
	for (int i = nb + 1; i < na + nb + 1 && !common; ++i) {
		if (z[i] == nb) return a;
		if (i + z[i] == na + nb + 1) common = z[i];
	}
	return a + b.substr(common, nb - common);
}

int minlen(string a, string &b, string &c) 
{
	a = combine(a, b);
	a = combine(a, c);
	return a.size();
}

int main() 
{
	char buf[100001];
	string s[3];
	scanf("%s", buf);
	s[0] = buf;
	scanf("%s", buf);
	s[1] = buf;
	scanf("%s", buf);
	s[2] = buf;
	sort(s, s + 3);
	int ans = INT_MAX;
	do {
		ans = min(ans, minlen(s[0], s[1], s[2]));
	} while (next_permutation(s, s + 3));
	printf("%d\n", ans);
	return 0;
}