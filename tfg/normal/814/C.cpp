#include <iostream>
#include <string>
#include <cstring>

const int me = 'z' - 'a' + 1;
const int ms = 1510;

int ans[me][ms];

int main()
{
	int n;
	while(std::cin >> n)
	{
		memset(ans, 0, sizeof ans);
		std::string a;
		std::cin >> a;
		//std::cout << "got " << a << "\n";
		for(char i = 'a'; i <= 'z'; i++)
		{
			for(int j = 0; j < n; j++)
			{
				int cost = 0;
				for(int k = j; k < n; k++)
				{
					//std::cout << "on " << i << ", (" << j << ", " << k << ")\n";
					if(a[k] != i)
						cost++;
					ans[i - 'a'][cost] = std::max(ans[i - 'a'][cost], k - j + 1);
				}
			}
		}
		for(int i = 'a'; i <= 'z'; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				ans[i - 'a'][j] = std::max(ans[i - 'a'][j], ans[i - 'a'][j - 1]);
			}
		}
		int q;
		std::cin >> q;
		while(q--)
		{
			char c;
			int x;
			std::cin >> x >> c;
			std::cout << ans[c - 'a'][x] << '\n';
		}
	}
}