#include <string>
#include <iostream>

std::string M[5050];
int n, m;

int main()
{
	std::cin >> n >> m;
	for(int i=0;i<n;i++)
		std::cin >> M[i];

	int firsti, firstj, seci, secj;
	bool found=false;
	int count=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(M[i][j]=='X')
			{
				if(!found)
				{
					found=true;
					firsti=i;
					firstj=j;
				}
				seci=i;
				secj=j;
				count++;
			}
		}
	}
	int count2=0;
	for(int i=firsti;i<=seci;i++)
	{
		for(int j=firstj;j<=secj;j++)
		{
			if(M[i][j]=='X')
				count2++;
		}
	}
	if(count2==count && count==(seci-firsti+1)*(secj-firstj+1))
		std::cout << "YES\n";
	else
		std::cout << "NO\n";

}