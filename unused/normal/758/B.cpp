#include <bits/stdc++.h>
using namespace std;

char str[1000];
char perm[5] = "RYBG";
int cnt[256];

int main()
{
	scanf("%s", str);

	sort(perm, perm + 4);
	do
	{
		memset(cnt, 0, sizeof(cnt));
		bool wrong = false;
		for (int i = 0; str[i]; i++)
		{
			if (str[i] == '!') cnt[perm[i % 4]]++;
			else if (str[i] != perm[i % 4])
			{
				wrong = true;
				break;
			}
		}
		if (wrong == false)
		{
			printf("%d %d %d %d", cnt['R'], cnt['B'], cnt['Y'], cnt['G']);
			return 0;
		}
	} while (next_permutation(perm, perm + 4));
}