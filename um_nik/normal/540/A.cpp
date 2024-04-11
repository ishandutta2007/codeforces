#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

int n;
string s, p;
int ans;

int main()
{
	cin >> n >> s >> p;
	for (int i = 0; i < n; i++)
	{
		int x = abs( (int)(s[i] - p[i]) );
		ans += min(x, 10 - x);
	}
	printf("%d\n", ans);

	return 0;
}