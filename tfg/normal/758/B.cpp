#include <iostream>
#include <string>

std::string str;
int pos[4];
int freq[256];


int main()
{
	std::cin >> str;
	int n=str.size();
	for(int i=0;i<n;i++)
	{
		if(str[i]!='!')
		{
			pos[i%4]=str[i];
		}
	}
	for(int i=0;i<n;i++)
	{
		if(str[i]=='!')
		{
			freq[pos[i%4]]++;
		}
	}
	std::cout << freq['R'] << ' ' << freq['B'] << ' ' << freq['Y'] << ' ' << freq['G'] << '\n';
}