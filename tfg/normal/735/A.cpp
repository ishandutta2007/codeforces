#include <iostream>
#include <string>
#include <cstdlib>

std::string str;
int n, k;

int main()
{
	std::cin >> n >> k >> str;
	int start,end;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='G')
			start=i;
		else if(str[i]=='T')
			end=i;
	}
	if(abs(start-end)%k!=0)
	{
		std::cout << "NO\n";
		return 0;
	}
	if(start<end)
	{
		for(int i=start+k;i<end;i+=k)
		{
			if(str[i]=='#')
			{
				std::cout << "NO\n";
				return 0;
			}
		}
	}
	else
	{
		for(int i=start-k;i>end;i-=k)
		{
			if(str[i]=='#')
			{
				std::cout << "NO\n";
				return 0;
			}
		}
	}
	std::cout << "YES\n";
}