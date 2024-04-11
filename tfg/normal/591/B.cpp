#include <iostream>
#include <string>

int to[256];

int main()
{
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < 256; i++)
		to[i] = i;
	std::string name;
	std::cin >> name;
	while(m--)
	{
		char u, v;
		std::cin >> u >> v;
		for(char i = 'a'; i <= 'z'; i++)
		{
			if(to[i] == u)
				to[i] = v;
			else if(to[i] == v)
				to[i] = u;
		}
	}
	for(int i = 0; i < n; i++)
		name[i] = to[name[i]];
	std::cout << name << '\n';
}