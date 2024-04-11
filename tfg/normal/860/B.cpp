#include <iostream>
#include <cstdio>
#include <cstring>

struct node
{
	int to[10];
	int freq = 0;

	node(){memset(to, -1, sizeof to);}
};

const int ms = 70700;

node trie[ms * 10 * 9 / 2];
char buffer[ms][10];
int size = 1;

void include(char *str, int f)
{
	int cur = 0;
	while(*str != 0)
	{
		int idx = *str - '0';
		if(trie[cur].to[idx] == -1)
			trie[cur].to[idx] = size++;
		cur = trie[cur].to[idx];
		trie[cur].freq += f;
		str++;
	}
}

int solve(char *str)
{
	int cur = 0;
	int ans = 0;
	while(*str != 0)
	{
		ans++;
		int idx = *str - '0';
		if(trie[cur].to[idx] == -1)
			trie[cur].to[idx] = size++;
		cur = trie[cur].to[idx];
		str++;
		if(trie[cur].freq == 0)
			return ans;
	}
	return 189735;
}

int main()
{
	//std::ios_base::sync_with_stdio(false);
	//std::cin.tie(0);
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++)
	{
		scanf(" %s", buffer[i]);
		for(int j = 0; j < 9; j++)
			include(&buffer[i][j], +1);
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < 9; j++)
			include(&buffer[i][j], -1);
		int ans = 1289078;
		int pos = -1;
		for(int j = 0; j < 9; j++)
		{
			int cur_ans = solve(&buffer[i][j]);
			if(cur_ans <= ans)
			{
				ans = cur_ans;
				pos = j;
			}
		}
		for(int j = pos; j < pos + ans; j++)
			printf("%c", buffer[i][j]);
		printf("\n");
		for(int j = 0; j < 9; j++)
			include(&buffer[i][j], +1);
	}
}