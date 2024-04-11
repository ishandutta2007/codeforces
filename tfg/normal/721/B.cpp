#include <iostream>
#include <string>

int n, k;

int s[150];

std::string str;

int main()
{
	std::cin >> n >> k;
	for(int i=0;i<n;i++)
	{
		std::cin >> str;
		s[(int)str.size()]++;
	}
	for(int i=1;i<150;i++)
		s[i]+=s[i-1];
	std::cin >> str;
	int size=(int)str.size();
	int best=s[size-1];
	int worst=s[size]-1;
	best+=(best/k)*5;
	worst+=(worst/k)*5;
	std::cout << best+1 << ' ' << worst+1 << '\n';
}