#include <iostream>
#include <iomanip>
#include <algorithm>

typedef long double ld;
typedef long long ll;

const int ms = 2020;

int n;
double p;
ll x[ms], h;
int right[ms], left[ms];

ld memo[ms][ms][4];
bool visit[ms][ms][4];

// 1 = left to right
// 2 = right to left
ld dp(int l, int r, int mask)
{
	if(l > r)
		return 0;
	ld &ans = memo[l][r][mask];
	if(visit[l][r][mask])
		return ans;
	ans = 0.0;
	visit[l][r][mask] = true;
	if(mask & 2)
		ans += (1 - p) * (dp(right[l] + 1, r, mask | 1)
			 + (std::min(x[right[l]] + h, x[r + 1] - h) - x[l]));
	else
		ans += (1 - p) * (dp(right[l] + 1, r, mask | 1)
			 + (std::min(x[right[l]] + h, x[r + 1]) - x[l]));
			 	//std::cout << "on (" << l << ", " << r << ", " << mask << ") returning " << (double)ans << '\n';
	if(mask & 1)
		ans += p * (dp(l, left[r] - 1, mask | 2)
			 + (x[r] - std::max(x[left[r]] - h, x[l - 1] + h)));
	else
		ans += p * (dp(l, left[r] - 1, mask | 2)
			 + (x[r] - std::max(x[left[r]] - h, x[l - 1])));
			 	//std::cout << "on (" << l << ", " << r << ", " << mask << ") returning " << (double)ans << '\n';
	if(mask & 1)
		ans += p * (dp(l + 1, r, mask ^ 1)
			 + (x[l] - std::max(x[l] - h, x[l - 1] + h)));
	else
		ans += p * (dp(l + 1, r, mask)
			 + (x[l] - std::max(x[l] - h, x[l - 1])));
			 	//std::cout << "on (" << l << ", " << r << ", " << mask << ") returning " << (double)ans << '\n';
	if(mask & 2)
		ans += (1 - p) * (dp(l, r - 1, mask ^ 2)
			 + (std::min(x[r] + h, x[r + 1] - h) - x[r]));
	else
		ans += (1 - p) * (dp(l, r - 1, mask)
			 + (std::min(x[r] + h, x[r + 1]) - x[r]));
			 	//std::cout << "on (" << l << ", " << r << ", " << mask << ") returning " << (double)ans << '\n';
	ans *= 0.5;
	//std::cout << "on (" << l << ", " << r << ", " << mask << ") returning " << (double)ans << '\n';
	return ans;
}

int main()
{
	std::cin >> n >> h >> p;
	for(int i = 1; i <= n; i++)
		std::cin >> x[i];
	x[0] = -ll(1e10);
	x[n + 1] = ll(1e10);
	std::sort(x + 1, x + 1 + n);
	right[n] = n;
	for(int i = n - 1; i > 0; i--)
	{
		if(x[i] + h > x[i + 1])
			right[i] = right[i + 1];
		else
			right[i] = i;
	}
	left[1] = 1;
	for(int i = 2; i <= n; i++)
	{
		if(x[i] - h < x[i - 1])
			left[i] = left[i - 1];
		else
			left[i] = i;
	}
	std::cout << std::fixed << std::setprecision(20) << (double) dp(1, n, 0) << '\n';
}