#include <iostream>
#include <string>
#include <vector>

int size=0;
std::vector<std::string> b;
std::string a[5050];

std::string get()
{
	return b[size++];
}

int main()
{
	for(char i='A';i<='z';i++)
	{
		for(char j='a';j<='z';j++)
		{
			std::string cur="";
			cur+=i;
			cur+=j;
			b.push_back(cur);
		}
	}
	int n, k;
	std::cin >> n >> k;
	for(int i=k;i<=n;i++)
	{
		std::string now;
		std::cin >> now;
		if(now=="NO")
		{
			if(a[i-k+1].size()==0)
			{
				a[i-k+1]=get();
			}
			a[i]=a[i-k+1];
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(i!=1)
			std::cout << ' ';
		if(a[i].size()==0)
			a[i]=get();
		std::cout << a[i];
	}
	std::cout << '\n';
}