#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <cstdio>

typedef long long ll;

std::map<ll, int> pot;
std::set<ll> pots;

bool ispot(ll x){return x - (x & -x) == 0;}

const int me = 60;

int main()
{
	for(int i = 0; i < me; i++)
		pot[1LL << i] = i;
	for(int i = 0; i < me; i++)
		pots.insert(1LL << i);
	int n;
	while(std::cin >> n)
	{
		std::vector<ll> a(n, 0);
		std::vector<int> freq[2];
		freq[0] = freq[1] = std::vector<int> (me, 0);
		for(int i = 0; i < n; i++)
		{
			//std::cin >> a[i];
			scanf("%lli", &a[i]);
			if(ispot(a[i]))
				freq[0][pot[a[i]]]++;
			else
				freq[1][pot[*pots.lower_bound(a[i])]]++;
		}
		bool got = false;
		for(int i = 1; i <= n && i <= freq[0][0]; i++)
		{
			int missing = n;
			int expand = i;
			int solve = i;
			std::vector<int> cur[2];
			cur[0] = freq[0];
			cur[1] = freq[1];
			bool ans = true;
			for(int j = 0; j < me - 1 && missing && ans; j++)
			{
				missing -= expand;
				cur[0][j] -= expand;
				int use1 = cur[1][j];
				cur[1][j] -= use1;
				solve -= use1;
				int use2 = cur[1][j + 1];
				cur[1][j + 1] -= use2;
				solve -= use2;
				int use3 = cur[0][j];
				cur[0][j] -= use3;
				solve -= use3;
				int use4 = std::max(0, cur[0][j + 1] - expand);
				cur[0][j + 1] -= use4;
				solve -= use4;
				int to_next = std::min(expand, cur[0][j + 1]);
				missing -= use1 + use2 + use3 + use4;
				if(expand < use1 + use2 + use3 + use4)
					ans = false;
				expand = to_next;
				solve = std::min(solve, expand);
			}
			ans = ans && missing == 0 && solve >= 0;
			if(ans)
			{
				if(got)
					//std::cout << ' ';
					printf(" ");
				printf("%i", i);
				//std::cout << i;
				got = true;
			}
		}
		if(!got)
			std::cout << -1;
		std::cout << '\n';
	}
}