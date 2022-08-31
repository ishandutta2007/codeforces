#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

string s;
int n;
bool ans;


int main()
{
	cin >> n >> s;

	ans = false;

	for (int l = 0; l < n; l++)
		for (int d = 1; l + 4 * d < n; d++)
		{
			bool ok = true;
			for (int i = 0; i < 5; i++)
				ok &= (s[l + d * i] == '*');
			ans |= ok;
		}
	if (ans)
		printf("yes\n");
	else
		printf("no\n");

	return 0;
}