#include <iostream>
#include <set>

struct node
{
	int to[2], freq;

	node()
	{
		to[0] = to[1] = -1;
		freq = 0;
	}
};

node trie[300300 * 25];
int c = 1;

int go(int x, int pos = 20, int on = 0)
{
	if(pos == -1)
	{
		int ans = 1 - trie[on].freq;
		trie[on].freq += ans;
		return ans;
	}
	int bit = (x >> pos) & 1;
	//std::cout << "on " << pos << ", got bit " << bit << "\n";
	if(trie[on].to[bit] == -1)
	{
		//std::cout << "created new position on " << c << "\n";
		trie[on].to[bit] = c++;
	}
	int ans = go(x, pos - 1, trie[on].to[bit]);
	trie[on].freq += ans;
	//std::cout << "on " << on << ", got freq " << trie[on].freq << '\n';
	return ans;
}

int solve(int x, int pos = 20, int on = 0)
{
	if(on == -1)
	{
		return 0;
	}
	else if(pos == -1)
	{
		return 1;
	}
	int bit = (x >> pos) & 1;
	//std::cout << "on " << pos << ", got bit " << bit << "\n";
	if(trie[on].to[bit] == -1)
	{
		//std::cout << "didn't find solution transition\n";
		return 0;
	}
	else if(trie[trie[on].to[bit]].freq < (1 << pos))
	{
		//std::cout << "transition to lesser\n";
		return solve(x, pos - 1, trie[on].to[bit]);
	}
	else
	{
		//std::cout << "transition to greater\n";
		return (1 << pos) + solve(x, pos - 1, trie[on].to[1 - bit]);
	}
}

int main()
{
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		int temp;
		std::cin >> temp;
		go(temp);
	}
	int cur = 0;
	for(int i = 0; i < m; i++)
	{
		int temp;
		std::cin >> temp;
		cur ^= temp;
		//std::cout << "query is " << cur << "\n";
		std::cout << solve(cur) << '\n';
	}
}