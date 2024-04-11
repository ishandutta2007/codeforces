#include <iostream>
#include <set>

int a[100100];
bool got[100100];

int main()
{
	int n;
	std::cin >> n;
	std::set<int> perm;
	for(int i = 1; i <= n; i++)
		perm.insert(i);
	for(int i = 1; i <= n; i++)
	{
		std::cin >> a[i];
		if(perm.count(a[i]) == 1)
		{
			got[i] = true;
			perm.erase(a[i]);
		}
	}
	for(int i = 1; i <= n; i++)
	{
		if(!got[i])
		{
			a[i] = *perm.begin();
			perm.erase(perm.begin());
		}
		if(i != 1)
			std::cout << ' ';
		std::cout << a[i];
	}
	std::cout << '\n';
}