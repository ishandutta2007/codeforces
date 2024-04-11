#include <bits/stdc++.h>
using namespace std;

struct chat
{
	int sender;
	bitset<128> mention;
	string dat;
};

map<string, int> mp;
string mp2[155];
vector<chat> chats;
bool visit[155][155];
int n;

bool recur(int idx, int last)
{
	if (visit[idx][last]) return false;
	visit[idx][last] = true;

	if (idx == chats.size())
	{
		for (auto &&c : chats)
		{
			printf("%s%s\n", mp2[c.sender].c_str(), c.dat.c_str());
		}
		return true;
	}

	for (int i = 0; i < n; i++)
	{
		if (chats[idx].mention[i] || last == i) continue;

		chats[idx].sender = i;
		if (recur(idx + 1, i)) return true;
	}

	return false;
}

int main()
{
	int T; scanf("%d", &T); while (T--)
	{
		mp.clear();
		chats.clear();
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			char name[15];
			scanf("%s", name);
			mp2[mp.size()] = name;
			mp.emplace(name, mp.size());
		}

		bitset<128> mask;
		for (int i = 0; i < n; i++) mask[i] = true;
		
		int m;
		scanf("%d ", &m);
		chats.resize(m);
		memset(visit, 0, sizeof(visit));
		bool wrong = false;
		for (int i = 0; i < m; i++)
		{
			char line[1555];
			fgets(line, 1555, stdin);
			int len = strlen(line);
			if (line[len - 1] == '\n') line[--len] = 0;
			int idx = find(line, line + len, ':') - line;

			chat &c = chats[i];
			c.mention.reset();
			if (line[0] == '?') c.sender = -1;
			else
			{
				auto itr = mp.find({ line, line + idx });
				if (itr == mp.end())
				{
					wrong = true;
					c.sender = -1;
				}
				else
				{
					c.sender = itr->second;
				}
			}
			c.dat = string(line + idx);

			for (char *p = strtok(line + idx + 1, ".,!? "); p; p = strtok(nullptr, ".,!? "))
			{
				auto itr = mp.find(p);
				if (itr != mp.end()) c.mention[itr->second] = true;
			}

			if (c.sender != -1)
			{
				for (int j = 0; j < n; j++) if (j != c.sender) c.mention[j] = true;
			}
		}

		if (wrong || recur(0, n) == false)
		{
			printf("Impossible\n");
		}
	}
}