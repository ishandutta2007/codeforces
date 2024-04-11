#include <cstdio> //fast io
#include <iostream>
#include <vector>

const int ms=100100;
//const int ms=100;

int n;
int a[ms];


std::vector<int> primes[ms];
bool not_prime[ms];


int freq[ms];

int main()
{
	std::cin >> n;
	for(int i=0;i<n;i++)
	{
		scanf("%i",a+i);
	}

	for(int i=2;i<ms;i++)
	{
		if(not_prime[i])
			continue;
		//std::cout << i << " is prime\n";
		for(int j=i;j<ms;j+=i)
		{
			primes[j].push_back(i);
			not_prime[j]=true;
			//std::cout << j << " has " << i << " on fact\n";
		}
	}

	for(int i=0;i<n;i++)
	{
		int cur=a[i];
		for(int j=0;j<primes[cur].size();j++)
		{
			freq[primes[cur][j]]++;
			//std::cout << "freq[" << primes[cur][j] << "] = " << freq[primes[cur][j]] << '\n';
		}
	}

	int ans=1;
	for(int i=0;i<ms;i++)
		ans=std::max(ans, freq[i]);

	std::cout << ans << '\n';
}