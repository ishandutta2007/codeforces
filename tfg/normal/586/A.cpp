#include <iostream>

int a[1010];

int main()
{
	int n;
	std::cin >> n;
	int last=-1;
	for(int i=1;i<=n;i++)
	{
		std::cin >> a[i];
		if(a[i])
			last=i;
	}
	int ans=0;
	bool uni=false;
	for(int i=1;i<=last; i++)
	{
		if(!uni && !a[i]) continue;
		if(a[i+1] || a[i+2])
		{
			uni=true;
			ans++;
		}
		else
		{
			uni=false;
			ans++;
		}
	}
	std::cout << ans << '\n';
}