#include <string>
#include <iostream>

int n;
std::string m[110];

int main()
{
	std::cin >> n;
	for(int i=0;i<n;i++)
		std::cin >> m[i];
	long long int ans=0;
	for(int i=0;i<n;i++)
	{
		long long int c1,c2;
		c1=c2=0;
		for(int j=0;j<n;j++)
		{
			if(m[i][j]=='C')
				c1++;
			if(m[j][i]=='C')
				c2++;
		}
		ans+=(c1*c1-c1)/2;
		ans+=(c2*c2-c2)/2;
	}
	std::cout << ans << '\n';
}