#include <iostream>
#include <string>
#include <set>

std::string str;
std::set<std::string> hmm;

int main()
{
	std::cin >> str;
	int n=str.size();
	for(int i=0;i<n;i++)
	{
		std::string wot="";
		for(int j=0;j<n;j++)
			wot+=str[(i+j)%n];
		hmm.insert(wot);
	}
	std::cout << (int)hmm.size() << '\n';
}