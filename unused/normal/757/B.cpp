#include <bits/stdc++.h>
using namespace std;

bool notprime[100005];
vector<int> primes;
int cnt[100005];
vector<int> divisor[100005];

void getprime()
{
	notprime[1] = true;
	divisor[1].push_back(1);

	for (int i = 2; i <= 100000; i++)
	{
		if (notprime[i]) continue;
		primes.push_back(i);
		divisor[i].push_back(i);
		for (int j = i * 2; j <= 100000; j += i)
		{
			notprime[j] = true;
			divisor[j].push_back(i);
		}
	}
}

int main()
{
	getprime();
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		for (int t : divisor[tmp]) cnt[t]++;
	}

	printf("%d\n", max(*max_element(cnt + 2, cnt + 100001), 1));
}