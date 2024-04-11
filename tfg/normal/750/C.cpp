#include <cstdio>
#include <set>
#include <iostream>

const int ms=200200;

int n;

int c[ms], d[ms];
int diff[ms];

std::multiset<int> ratings[2];

std::multiset<int>::iterator it[2];

int main()
{
	scanf("%i",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%i %i",c+i,d+i);
		diff[i]=diff[i-1]+c[i-1];
		ratings[d[i]%2].insert(diff[i]);
	}
	diff[n+1]=diff[n]+c[n];
	if(ratings[0].size()==0)
	{
		std::cout << "Infinity\n";
		return 0;
	}
	else if(ratings[1].size()==0)
	{
		it[0]=ratings[0].end();
		it[0]--;
		std::cout << 1899 - ((*it[0]) - diff[n+1]) << '\n';
		return 0;
	}
	else
	{
		it[0]=ratings[0].end();
		it[0]--;
		it[1]=ratings[1].begin();
		if(*it[0]>=*it[1])
		{
			std::cout << "Impossible\n";
			return 0;
		}
		std::cout << 1899 - ((*it[0]) - diff[n+1]) << '\n';
		return 0;
	}


}