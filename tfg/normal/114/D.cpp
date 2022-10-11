#include <iostream>
#include <string>
#include <cstring>

const int ms = 2020;

int freq[2][ms];

struct node
{
	int to['z' - 'a' + 1];
	bool p;
	node()
	{
		memset(to, 0, sizeof to);
		p = false;
	}
};

int c = 1;
node trie[ms * ms / 2];

int main()
{
	std::string txt, beg, end;
	std::cin >> txt >> beg >> end;
	for(int i = 0; i + beg.size() <= txt.size(); i++)
	{
		if(beg == txt.substr(i, beg.size()))
			freq[0][i]++;
	}
	for(int i = 0; i + end.size() <= txt.size(); i++)
	{
		if(end == txt.substr(i, end.size()))
			freq[1][i + end.size() - 1]++;
	}
	int ans = 0;
	for(int i = 0; i < txt.size(); i++)
	{
		if(freq[0][i])
		{
			int cur = 0;
			for(int j = i; j < txt.size(); j++)
			{
				if(trie[cur].to[txt[j] - 'a'] == 0)
					trie[cur].to[txt[j] - 'a'] = c++;
				cur = trie[cur].to[txt[j] - 'a'];
				if(freq[1][j] && trie[cur].p == false && j - i + 1 >= end.size() && j - i + 1 >= beg.size())
				{
					trie[cur].p = true;
					ans++;
				}
			}
		}
	}
	std::cout << ans << "\n";
}