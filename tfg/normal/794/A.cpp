#include <iostream>

typedef long long ll;

const int ms = 100100;

int n, a, b, c;

int main()
{
	while(std::cin >> a >> b >> c >> n)
	{
		int ans = 0;
		while(n--)
		{
			int x;
			std::cin >> x;
			if(b < x && x < c)
				ans++;
		}
		std::cout << ans << '\n';
	}
}