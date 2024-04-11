#include <iostream>
#include <cstring>
#include <vector>

typedef long long ll;

const ll MOD = ll(1e9) + 7;
const int ms = 51;
const int me = 22;

int n;

int a[ms];

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
	if(a < b || b < 0 || a < 0)
		return 0;
	ll ans = fat[a] * ifat[b] % MOD;
	return ans * ifat[a - b] % MOD;
}


int memo[ms][me][me][2][me][me][2];
int dp(int on, std::vector<int> prv, std::vector<int> nxt)
{
	int max = prv[0];
	int min = prv[0];
	int sum = 0;
	for(int i = 0; i < 3; i++)
	{
		max = std::max(max, std::max(prv[i], nxt[i]));
		min = std::min(min, std::min(prv[i], nxt[i]));
		sum += prv[i] + nxt[i];
	}
	if(max > me || min < 0)
		return 0;
	if(on == n)
	{
		//std::cout << "on " << on << ", (" << prv[0] << ", " << prv[1] << ", " << prv[2] << ") - (" << nxt[0] << ", " << nxt[1] << ", " << nxt[2] << ")\n";
		return sum == 0;
	}
	if(sum == 0)
		return 0;
	int &ans = memo[on][prv[0]][prv[1]][prv[2]][nxt[0]][nxt[1]][nxt[2]];
	if(ans != -1)
		return ans;
	ans = 0;
	if(prv[0] + prv[1] + prv[2] == 0)
		return ans = dp(on, nxt, prv);
	//std::cout << "on " << on << ", (" << prv[0] << ", " << prv[1] << ", " << prv[2] << ") - (" << nxt[0] << ", " << nxt[1] << ", " << nxt[2] << ")\n";
	for(int i = 0; i <= a[on] && i <= prv[0]; i++)
	{
		ll cost1 = comb(prv[0], i);
		for(int j = 0; i + j <= a[on] && j <= prv[1]; j++)
		{
			ll cost2 = cost1 * comb(prv[1], j) % MOD;
			for(int k = 0; i + j + k <= a[on] && k <= prv[2]; k++)
			{
				if(i + j + k != 1)
					continue;
				ll cost3 = cost2 * comb(prv[2], k) % MOD;
				for(int ii = 0; i + j + k + ii <= a[on] && ii <= nxt[0]; ii++)
				{
					ll cost4 = cost3 * comb(nxt[0], ii) % MOD;
					for(int jj = 0; i + j + k + ii + jj <= a[on] && jj <= nxt[1]; jj++)
					{
						ll cost5 = cost4 * comb(nxt[1], jj) % MOD;
						for(int kk = 0; i + j + k + ii + jj + kk <= a[on] && kk <= nxt[2]; kk++)
						{
							ll cost6 = cost5 * comb(nxt[2], kk) % MOD;
							//std::cout << "\non " << on << ", (" << prv[0] << ", " << prv[1] << ", " << prv[2] << ") - (" << nxt[0] << ", " << nxt[1] << ", " << nxt[2] << ")\n";
							
							prv[0] += j - i;
							prv[1] += k - j;
							prv[2] += -k;
							nxt[0] += jj - ii;
							nxt[1] += kk - jj;
							nxt[2] += -kk;
							//std::cout << "cost is " << cost6 << ", (" << i << ", " << j << ", " << k << ", " << ii << ", " << jj << ", " << kk << ")\n";
							if(i + j + k + ii + jj + kk < a[on])
								nxt[a[on] - (i + j + k + ii + jj + kk) - 1]++;
							ans = (ans + cost6 * dp(on + 1, prv, nxt)) % MOD;
							if(i + j + k + ii + jj + kk < a[on])
								nxt[a[on] - (i + j + k + ii + jj + kk) - 1]--;
							prv[0] -= j - i;
							prv[1] -= k - j;
							prv[2] -= -k;
							nxt[0] -= jj - ii;
							nxt[1] -= kk - jj;
							nxt[2] -= -kk;
						}
					}
				}
			}
		}
	}
	//std::cout << "on " << on << ", (" << prv[0] << ", " << prv[1] << ", " << prv[2] << ") - (" << nxt[0] << ", " << nxt[1] << ", " << nxt[2] << ") ans is " << ans << "\n";
	return ans;
}

int main()
{
	fat[0] = ifat[0] = 1;
	for(int i = 1; i < ms; i++)
	{
		fat[i] = fat[i - 1] * i % MOD;
		ifat[i] = fexp(fat[i], MOD - 2);
	}
	std::cin >> n;
	for(int i = 0; i < n; i++)
		std::cin >> a[i];
	memset(memo, -1, sizeof memo);
	a[0]++;
	std::vector<int> prv, nxt;
	prv = nxt = std::vector<int>(3, 0);
	prv[0] = 1;
	std::cout << dp(0, prv, nxt) << '\n';
}