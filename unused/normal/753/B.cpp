#include <bits/stdc++.h>
using namespace std;


const char str[] = "0123";
pair<int, int> ask(const string &digit)
{
	printf("%s\n", digit.c_str());
	fflush(stdout);
#ifdef ONLINE_JUDGE
	pair<int, int> ret;
	scanf("%d%d", &ret.first, &ret.second);
	return ret;
#else
	pair<int, int> ret;
	for (int i = 0; i < 4; i++)
	{
		if (str[i] == digit[i]) ret.first++;
		else
		{
			for (int j = 0; j < 4; j++)
			{
				if (str[j] == digit[i])
				{
					ret.second++;
					break;
				}
			}
		}
	}
	return ret;
#endif
}

int main()
{
	int no;
	for (int i = '0'; i <= '9'; i++)
	{
		auto ret = ask(string(4, i));
		if (ret.first == 0 && ret.second == 0)
		{
			no = i;
			break;
		}
	}

	string askstr(4, no);
	for (int i = 0; i < 4; i++)
	{
		for (int j = '0'; j <= '9'; j++)
		{
			askstr[i] = j;
			auto ret = ask(askstr);
			if (ret.first == i + 1)
			{
				break;
			}
		}
	}
}