#include <stdio.h>
#include <vector>
using namespace std;

vector<int> s1, s2;

int main()
{
	int n;
	scanf("%d", &n);
	bool z1 = false;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		if (tmp) s1.push_back(tmp);
		else z1 = true;
	}

	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		if (tmp) s2.push_back(tmp);
	}

	if (s1.size() != s2.size())
	{
		printf("NO\n");
		return 0;
	}
	int start = 0;
	if (z1)
	{
		while (start < s2.size())
		{
			if (s1[0] == s2[start]) break;
			start++;
		}
		if (start == s2.size())
		{
			printf("NO\n");
			return 0;
		}
	}

	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] != s2[(start + i) % s2.size()])
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
}