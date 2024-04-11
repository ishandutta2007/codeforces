#include <iostream>

int n;

int wtf[100][2];

int main()
{
	int got=0;
	std::cin >> n;
	for(int i=0;i<3;i++)
	{
		std::cin >> wtf[i][0] >> wtf[i][1];
		got+=wtf[i][0];
	}
	for(int i=0;i<3;i++)
	{
		int cur_got=std::min(n-got, wtf[i][1]-wtf[i][0]);
		got+=cur_got;
		if(i)
			std::cout << ' ';
		std::cout << wtf[i][0] + cur_got;
	}
	std::cout << '\n';
}