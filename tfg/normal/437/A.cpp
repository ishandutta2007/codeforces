#include <iostream>
#include <string>

int size[4];

int main()
{
	for(int i=0;i<4;i++)
	{
		std::string str;
		std::cin >> str;
		size[i]=str.size()-2;
	}

	int anss=0;
	char ans;
	for(int i=0;i<4;i++)
	{
		int shorter=0, longer=0;
		for(int j=0;j<4;j++)
		{
			if(i==j)
				continue;
			if(2*size[i]<=size[j])
				shorter++;
			else if(2*size[j]<=size[i])
				longer++;
		}
		if(shorter==3 || longer==3)
		{
			anss++;
			ans='A'+i;
		}
	}
	if(anss!=1)
		ans='C';
	std::cout << ans << '\n';
}