#include <iostream>
#include <set>
#include <cstdio>

typedef long long ll;

bool memo[100][100];
bool visit[100][100];
bool dp(int a, int b)
{
	if(a < 0 || b < 0)
		return false;
	if(a == 0 && b == 0)
		return true;
	if(a == 0 || b == 0)
		return false;
	bool &ans = memo[a][b];
	if(visit[a][b])
		return ans;
	ans = false;
	visit[a][b] = true;
	for(int i = 1; i + i <= a; i++)
		ans = ans || dp(a - 2 * i, b - i);
	for(int i = 1; i + i <= b; i++)
		ans = ans || dp(a - i, b - 2 * i);
	return ans;
}

const int ms = 1e6 + 1000;

ll trip(ll x)
{
	ll l = 1, r = 1e6 + 1000;
	while(l != r)
	{
		ll mid = (l + r + 1) / 2;
		if(mid * mid * mid <= x)
			l = mid;
		else
			r = mid - 1;
	}
	return l;
}

int to[ms];

bool solve(ll a, ll b)
{
	ll t = trip(a * b);
	if(t * t * t != a * b)
		return false;
	//std::cout << "debug, t = " << t << "\n";
	std::set<ll> primes;
	while(t != 1)
	{
		primes.insert(to[t]);
		t /= to[t];
	}
	for(auto i : primes)
	{
		int scores[2];
		scores[0] = scores[1] = 0;
		while(a % i == 0)
		{
			scores[0]++;
			a /= i;
		}
		while(b % i == 0)
		{
			scores[1]++;
			b /= i;
		}
		if(!dp(scores[0], scores[1]))
			return false;
	}
	return a + b == 2;
}

int main()
{
	/*for(int i = 0; i < 100; i++)
	{
		for(int j = 0; j < 100; j++)
		{
			std::cout << "(" << i << ", " << j << ") = " << dp(i, j) << "\n";
		}
	}*/
	for(int i = 2; i < ms; i++)
	{
		if(to[i])
			continue;
		for(int j = i; j < ms; j += i)
			to[j] = i;
	}
	int q;
	std::cin >> q;
	while(q--)
	{
		ll a, b;
		//std::cin >> a >> b;
		scanf("%lli %lli", &a, &b);
		if(solve(a, b))
			std::cout << "Yes\n";
		else
			std::cout << "No\n";
	}
}