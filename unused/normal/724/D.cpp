#include "bits/stdc++.h"
using namespace std;

char str[100005];
vector<int> pos[26];
bool filled[100005];
int len;
string ans;

int main()
{
	int m;
	scanf("%d%s", &m, str);
	len = strlen(str);

	ans.reserve(len);

	for (int i = 0; i < len; i++)
	{
		pos[str[i] - 'a'].push_back(i);
	}

	for (int i = 0; i < 26; i++)
	{
		int idx = 0;
		bool wrong = false;
		for (int p = m - 1; p < len; p++)
		{
			if (filled[p]) continue;
			while (idx < pos[i].size() && pos[i][idx] + m <= p) idx++;
			if (idx == pos[i].size() || pos[i][idx] > p)
			{
				wrong = true;
				break;
			}
		}

		if (wrong)
		{
			ans += string(pos[i].size(), i + 'a');
			int idx = 0;
			for (int p = m - 1; p < len; p++)
			{
				if (filled[p]) continue;
				while (idx < pos[i].size() && pos[i][idx] + m <= p) idx++;
				if (idx == pos[i].size()) break;
				if (pos[i][idx] > p) continue;
				filled[p] = true;
			}
		}
		else
		{
			int idx = 0;
			for (int p = m - 1; p < len; p++)
			{
				if (filled[p]) continue;
				while (idx < pos[i].size() && pos[i][idx] + m <= p) idx++;
				while (idx < pos[i].size() && pos[i][idx] <= p) idx++;
				idx--;
				bool u = false;
				for (; p < len && pos[i][idx] + m - 1 >= p; p++) filled[p] = u = true;
				if (u) ans += (char)(i + 'a');
				p--;
			}
			break;
		}
	}

	printf("%s", ans.c_str());
}