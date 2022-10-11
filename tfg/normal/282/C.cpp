#include <iostream>
#include <string>

std::string str[2];
int size[2], freq[2][2];

int main()
{
	for(int i=0;i<2;i++)
	{
		std::cin >> str[i];
		size[i]=str[i].size();
		for(int j=0;j<size[i];j++)
			freq[i][str[i][j]-'0']++;
		//std::cout << "(" << freq[i][0] << ", " << freq[i][1] << ")\n";
	}
	bool valid=true;
	if(size[0]!=size[1])
		valid=false;
	if((!freq[0][1] || !freq[1][1]) && freq[0][1]!=freq[1][1])
		valid=false;
	if(valid)
		std::cout << "YES\n";
	else
		std::cout << "NO\n";
}