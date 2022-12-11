#include <bits/stdc++.h>
using namespace std;


int main()
{
	cin.sync_with_stdio(false);
	string s1, s2;
	cin >> s1 >> s2;
	if (s1 == s2) printf("-1\n");
	else printf("%zd\n", max(s1.size(), s2.size()));
}