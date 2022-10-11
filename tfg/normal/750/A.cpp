#include <iostream>

int n, k;

int needed=240;
int on=0;

int main()
{
	std::cin >> n >> k;
	int ans=0;
	for(int i=0;on<=needed-k && i<=n;i++)
	{

		on+=5*i;
		//std::cout << "on " << on << '\n';
		if(on>needed-k)
			break;
		ans=i;
	}
	std::cout << ans << '\n';
}