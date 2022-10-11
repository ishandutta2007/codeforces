#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#include <utility>

typedef long long ll;

int n;
ll k;



const int INF = 2000;
const int ms = 1010;
const int md = 10000;

ll a[ms];
int b[ms];
std::vector<ll> divs;
std::map<ll, int> dude;
std::vector<ll> primes;
std::vector<ll> haha[md];

short int memo[ms][md];
ll sum[ms][md];
bool got[ms][md];

ll gcd(ll a, ll b)
{
	if(!b)
		return a;
	else
		return gcd(b, a%b);
}

int to(int d1, int d2)
{
	ll ans = 1;
	for(int i=0;i<primes.size();i++)
		ans *= std::min(haha[divs.size()-1][i], haha[d1][i] * haha[d2][i]);
	//std::cout << "(" << divs[d1] << ", " << divs[d2] << ") gives " << ans << '\n';
	return dude[ans];
}

short int dp(int on, int d)
{
	//std::cout << "on dp(" << on << ", " << d << ")\n";
	if(d + 1 == divs.size())
		return 0;
	if(on == n)
		return INF;
	short int &ans = memo[on][d];
	if(ans != 0)
		return ans;
	ans = dp(on + 1, d);
	sum[on][d] = sum[on + 1][d];
	int nxt = to(b[on], d);
	short int nxt_ans = 1 + dp(on + 1, nxt);
	ll nxt_sum = sum[on + 1][nxt] + a[on];
	if(ans > nxt_ans || (ans == nxt_ans && nxt_sum < sum[on][d]))
	{
		ans = nxt_ans;
		sum[on][d] = nxt_sum;
		got[on][d] = true;
	}
	//std::cout << "on dp(" << on << ", " << d << ") returns " << ans.first << ", " << ans.second << "\n";
	return ans;
}

int main()
{
	std::cin >> n >> k;
	for(int i=0;i<n;i++)
		std::cin >> a[i];
	if(k == 1)
	{
		ll min = a[0];
		int on = 0;
		for(int i=0;i<n;i++)
		{
			if(a[i] < min)
			{
				min = a[i];
				on = i;
			}
		}
		std::cout << "1\n" << on + 1 << '\n';
		return 0;
	}
	for(ll i=1;i*i<=k;i++)
	{
		if(k % i != 0)
			continue;
		divs.push_back(i);
		if(k / i != i)
			divs.push_back(k / i);
	}
	ll prv = k;
	for(ll i=2;i*i<=k;i++)
	{
		if(k % i != 0)
			continue;
		primes.push_back(i);
		while(k % i == 0)
			k /= i;
	}
	if(k != 1)
		primes.push_back(k);
	std::sort(divs.begin(), divs.end());
	for(int i=0;i<divs.size();i++)
	{
		ll cur = divs[i];
		for(int j=0;j<primes.size();j++)
		{
			haha[i].push_back(1);
			while(cur % primes[j] == 0)
			{
				haha[i].back() *= primes[j];
				cur /= primes[j];
			}
		}
	}
	for(int i=0;i<divs.size();i++)
		dude[divs[i]] = i;
	for(int i=0;i<n;i++)
		b[i] = dude[gcd(prv, a[i])];
		
	/*for(int i=0;i<n;i++)
		std::cout << "(" << a[i] << ", " << b[i] << ") ";
	std::cout << '\n';*/
	if(dp(0, 0) == INF)
	{
		std::cout << "-1\n";
		return 0;
	}
	int d = 0;
	std::vector<int> ans;
	for(int i=0;i<n;i++)
	{
		if(got[i][d])
		{
			ans.push_back(i);
			d = to(b[i], d);
		}
	}
	std::cout << ans.size() << '\n';
	for(int i=0;i<ans.size();i++)
	{
		if(i)
			std::cout << ' ';
		std::cout << ans[i] + 1;
	}
	std::cout << '\n';
}