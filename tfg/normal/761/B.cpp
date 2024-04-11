#include <iostream>

int get[1010];
int second[1010];

int main()
{
	int n,l;
	std::cin >> n >> l;
	for(int i=0;i<n;i++)
	{
		int temp;
		std::cin >> temp;
		get[temp]++;
	}
	for(int i=0;i<n;i++)
		std::cin >> second[i];
		
	for(int i=0;i<l;i++)
	{
		bool flag=true;
		for(int j=0;j<n;j++)
		{
			if(!get[(second[j]+i)%l])
			{
				flag=false;
				break;
			}
		}
		if(flag)
		{
			std::cout << "YES\n";
			return 0;
		}
	}
	std::cout << "NO\n";
}