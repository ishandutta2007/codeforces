#include <stdio.h>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> primes;
bool notprime[1000005];
void getprime()
{
	primes.push_back(2);
	for (int i = 3; i <= 1000000; i += 2)
	{
		if (notprime[i]) continue;
		primes.push_back(i);
		for (int j = 3; i * j <= 1000000; j += 2)
		{
			notprime[i*j] = true;
		}
	}
}

int main()
{
	getprime();

	int n, m;
	scanf("%d%d", &n, &m);

	unordered_set<int> divisors;

	for (int i = 0; m > 1 && i < primes.size(); i++)
	{
		int j = 1;
		while (m % primes[i] == 0)
		{
			m /= primes[i];
			j *= primes[i];
		}
		if (j > 1) divisors.insert(j);

		if (notprime[m]==false)
		{
			divisors.insert(m);
			break;
		}
	}

	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		for (auto it = divisors.begin(); it != divisors.end();)
		{
			if (tmp % *it == 0)
			{
				it = divisors.erase(it);
			}
			else ++it;
		}
	}
	if (divisors.empty()) printf("Yes");
	else printf("No");
}