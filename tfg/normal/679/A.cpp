#include <iostream>
#include <vector>
#include <utility>

typedef std::pair<int, int> ii;

const int ms=101;

bool np[ms];

std::vector<int> primes;
std::vector<ii> fact;

bool qry(int x)
{
	std::cout << x << std::endl;
	std::string str;
	std::cin >> str;
	return str[0]=='y';
}

int main()
{
	for(int i=2;i<ms;i++)
	{
		if(np[i])
			continue;
		primes.push_back(i);
		for(int j=i+i;j<ms;j+=i)
			np[j]=true;
	}
	int got=1;
	int i;
	for(i=0;i<primes.size() && primes[i]<10;i++)
	{
		int cur=primes[i];
		if(qry(cur))
		{
			if(got!=1 || qry(cur*cur))
			{
				std::cout << "composite" << std::endl;
				return 0;
			}
			got*=cur;

		}
	}
	if(got==1)
	{
		std::cout << "prime" << std::endl;
		return 0;
	}
	for(;i<primes.size() && got*primes[i]<100;i++)
	{
		int cur=primes[i];
		if(qry(cur))
		{
			std::cout << "composite" << std::endl;
			return 0;
		}
	}
	std::cout << "prime" << std::endl;
	return 0;
}