#include <iostream>

int main()
{
	int a, b;
	std::cin >> a >> b;
	int ans=0;
	while(a>0 && b>0)
	{
		if(a<b)
		{
			a++;
			b-=2;
		}
		else
		{
			a-=2;
			b++;
		}
		ans++;
	}
	if(a<0 || b<0)
		ans--;
	std::cout << ans << '\n';
}