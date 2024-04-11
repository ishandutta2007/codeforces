#include <iostream>
#include <string>

std::string a[110];
std::string test;

bool deleted[110];

bool compare(int x)
{
	if(a[x].size()!=test.size()) return false;
	for(int i=0;i<test.size();i++)
	{
		if(test[i]=='?') continue;
		if(test[i]!=a[x][i]) return false;
	}
	return true;
}

bool construct(int x)
{
	if(a[x].size()!=test.size()) return false;
	for(int i=0;i<test.size();i++)
	{
		if(test[i]=='?') continue;
		if(a[x][i]!=test[i]) test[i]='?';
	}
	return true;
}

int main()
{
	int n,m;
	std::cin >> n >> m;
	for(int i=0;i<n;i++)
		std::cin >> a[i];
	int temp;
	for(int i=0;i<m;i++)
	{
		std::cin >> temp;
		temp--;
		deleted[temp]=true;
	}
	test=a[temp];
	bool ans=true;
	for(int i=0;i<n&&ans;i++)
	{
		if(deleted[i])
			ans=construct(i);
	}
	for(int i=0;i<n&&ans;i++)
	{
		if(!deleted[i])
			ans=!compare(i);
	}
	if(!ans)
	{
		std::cout << "No\n";
	}
	else
	{
		std::cout << "Yes\n" << test << std::endl;
	}
}