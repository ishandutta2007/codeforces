#include <stdio.h>
#include <set>
#include <string.h>
#include <string>
using namespace std;

char str[10005];
bool d[10005], e[10005];
set<string> ans;

int main()
{
	scanf("%s", str);
	int len = strlen(str);
	d[len] = e[len] = true;
	for (int i = len - 2; i >= 5; i--)
	{
		if (d[i + 3] || (e[i + 3] && memcmp(str + i, str + i + 3, 3)))
		{
			e[i] = true;
			ans.emplace(str + i, str + i + 3);
		}
		if (e[i + 2] || (d[i + 2] && memcmp(str + i, str + i + 2, 2)))
		{
			d[i] = true;
			ans.emplace(str + i, str + i + 2);
		}
	}

	printf("%d\n", (int)ans.size());
	for (auto &&s : ans) printf("%s\n", s.c_str());
}