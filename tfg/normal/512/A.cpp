#include <vector>
#include <iostream>

const int ms = 'z' - 'a' + 1;

std::vector<int> edges[ms];
int got[ms], gott[ms];
int degree[ms];
int counter;

void dfs(int on)
{
	if(degree[on] > 0 || gott[on] != -1)
		return;
	gott[on] = counter;
	got[counter++] = on;
	for(auto to : edges[on])
	{
		degree[to]--;
		dfs(to);
	}
}

int main()
{
	int n, m;
	while(std::cin >> n)
	{
		counter = 0;
		for(int i = 0; i < ms; i++)
		{
			edges[i].clear();
			got[i] = gott[i] = -1;
			degree[i] = 0;
		}
		std::vector<std::string> a(n);
		for(int i = 0; i < n; i++)
			std::cin >> a[i];
		bool valid = true;
		for(int i = 1; i < n; i++)
		{
			int on = 0;
			while(on < std::min(a[i].size(), a[i - 1].size()) && a[i][on] == a[i - 1][on])
				on++;
			if(on == a[i - 1].size())
				continue;
			else if(on == a[i].size())
			{
				valid = false;
				break;
			}
			//std::cout << "on (" << a[i - 1] << ", " << a[i] << ") got " << on << "\n";
			int u = a[i - 1][on] - 'a';
			int v = a[i][on] - 'a';
			edges[u].push_back(v);
			degree[v]++;
		}
		for(int i = 0; i < ms; i++)
			dfs(i);
		valid = valid && counter == ms;
		if(!valid)
			std::cout << "Impossible\n";
		else
		{
			/*std::cout << "got answer:\n";
			for(auto str : a)
			{
				for(auto c : str)
				{
					std::cout << (char)(got[c - 'a'] + 'a');
				}
				std::cout << '\n';
			}*/
			//std::cout << "----------------\n";
			for(int i = 0; i < ms; i++)
				std::cout << (char)(got[i] + 'a');
			std::cout << '\n';
		}
	}
}