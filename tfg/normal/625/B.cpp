#include <string>
#include <iostream>

std::string a, b;

bool exists(int x)
{
	for(int i=0;i<b.size();i++)
	{
		if(x+i>=a.size())
			return false;
		if(a[x+i]!=b[i])
			return false;
	}
	return true;
}

int main()
{
	std::cin >> a >> b;
	int ans=0;
	for(int i=0;i<a.size();i++)
	{
		if(exists(i))
		{
			ans++;
			a[i+(int)b.size()-1]='#';
		}
	}
	std::cout << ans << std::endl;
}