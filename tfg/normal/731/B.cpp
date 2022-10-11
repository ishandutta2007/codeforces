#include <cstdio>
#include <iostream>
#include <utility>

typedef long long int ll;
typedef std::pair<int, int> ii;

int a[300300];
int n;

int main()
{
	bool valid=true;
	std::cin >> n;
	for(int i=0;i<n;i++)
		std::cin >> a[i];
	for(int i=0;i<n-1;i++)
	{
		if(a[i]%2==1)
		{
			if(a[i+1]==0)
				valid=false;
			else
			{
				a[i+1]--;
				a[i]--;
			}
		}
	}
	if(a[n-1]%2==1)
		valid=false;
	if(valid)
		std::cout << "YES\n";
	else
		std::cout << "NO\n";
}