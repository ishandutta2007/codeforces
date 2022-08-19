#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

string s;
int n;
string p = "CODEFORCES";

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cin >> s;
	n = s.length();
	if (n < 10)
	{
		printf("NO\n");
		return 0;
	}
	int idx = 0;
	while(idx < 10 && s[idx] == p[idx]) idx++;
	int id = 0;
	while(id < 10 && s[n - 1 - id] == p[9 - id]) id++;
	if (idx + id >= 10)
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}