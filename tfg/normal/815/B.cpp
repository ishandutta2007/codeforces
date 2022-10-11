#include <iostream>
#include <cstdio>
#include <vector>

typedef long long ll;

const ll MOD = ll(1e9) + 7;
const int ms = 200200;



ll fexp(ll x, ll e)
{
	ll ans = 1;
	for(; e > 0; e /= 2)
	{
		if(e & 1)
			ans = ans * x % MOD;
		x = x * x % MOD;
	}
	return ans;
}

ll fat[ms];
ll ifat[ms];

ll comb(int a, int b)
{
	//std::cout << "comb of (" << a << ", " << b << ")\n";
	ll ans = fat[a] * ifat[b] % MOD;
	return ans * ifat[a - b] % MOD;
}

// par -> j par = comb(n / 2, j / 2)
// par -> se n / 2 % 2 == 0  negativo, se no  positivo
// par -> comb(n / 2 - 1, j / 2)

// impar -> transforma no par e resolve

ll solve(std::vector<ll> a)
{
	if(a.size() == 1)
		return a[0];
	else if(a.size() % 2 == 1)
	{
		//std::cout << "reducing from " << a.size() << '\n';
		std::vector<ll> nxt;
		for(int i = 0; i + 1 < a.size(); i++)
			nxt.push_back(a[i] + (i % 2 == 0 ? a[i + 1] : -a[i + 1]));
		return solve(nxt);
	}
	else
	{
		ll ans = 0;
		for(int i = 0; i < a.size(); i++)
		{
			ll count;
			if(i % 2 == 0)
				count = comb(a.size() / 2 - 1, i / 2);
			else if(a.size() / 2 % 2 == 1)
				count = comb(a.size() / 2 - 1, i / 2);
			else
				count = -comb(a.size() / 2 - 1, i / 2);
			//std::cout << "count at " << i << " is " << count << '\n';
			ans += count * a[i];
			ans = (ans % MOD + MOD) % MOD;
		}
		return ans;
	}
}

int main()
{
	fat[0] = 1;
	ifat[0] = 1;
	for(int i = 1; i < ms; i++)
	{
		fat[i] = fat[i - 1] * i % MOD;
		ifat[i] = fexp(fat[i], MOD - 2);
	}
	int n;
	std::cin >> n;
	std::vector<ll> a;
	for(int i = 0; i < n; i++)
	{
		ll temp;
		//std::cin >> temp;
		scanf("%lli", &temp);
		a.push_back(temp);
	}
	std::cout << solve(a) << '\n';
}