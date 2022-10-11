#include <iostream>
#include <string>

bool space[3030];

bool isVowel(char x)
{
	return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
}

int main()
{
	std::string str;
	std::cin >> str;
	int n = str.size();

	int con = 0;
	bool equal = true;
	for(int i = 0; i < n; i++)
	{
		if(isVowel(str[i]))
		{
			con = 0;
			equal = true;
		}
		else if(str[i] != str[i - con] && con > 3 && equal)
		{
			con = 1;
			equal = true;
			space[i] = true;
		}
		else
		{
			equal = equal && str[i] == str[i - con];
			con++;
			//std::cout << "on " << i << " got " << equal << ", " << con << '\n';
			if(con >= 3 && !equal)
			{
				space[i] = true;
				equal = true;
				con = 1;
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(space[i])
			std::cout << ' ';
		std::cout << str[i];
	}
	std::cout << '\n';
}