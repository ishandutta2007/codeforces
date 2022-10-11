#include <iostream>
#include <cstring>
#include <cstdio>

typedef long long ll;

const int ms = 300300;
const int MAGIC = 100;

int n;
int a[300300];
int memo[300300][MAGIC];

int dp(int on, int bonus)
{
	if(on == n)
		return 0;
	else if(bonus >= MAGIC)
		return dp(on + 1, bonus - a[on]);
	int &ans = memo[on][bonus];
	if(ans != -1)
		return ans;
	int get = std::min(bonus, a[on]);
	ans = std::min(a[on] + dp(on + 1, a[on] / 10 + bonus), a[on] - get + dp(on + 1, bonus - get));;
	//std::cout << "on (" << on << ", " << bonus << ") = " << ans << "\n";
	return ans;
}

int main()
{
	std::cin >> n;
	memset(memo, -1, sizeof memo);
	for(int i = 0; i < n; i++)
	{
		//a[i] = 2000;
		scanf("%i", a + i);
		a[i] /= 100;
	}
	std::cout << dp(0, 0) * 100LL << '\n';
}