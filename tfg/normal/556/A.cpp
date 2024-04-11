#include <iostream>
#include <string>

int main()
{
	int freq[2];
	freq[0]=freq[1]=0;
	int n;
	std::cin >> n;
	std::string str;
	std::cin >> str;
	for(int i=0;i<n;i++)
		freq[str[i]-'0']++;
	std::cout << n-2*std::min(freq[0], freq[1]) << '\n';
}