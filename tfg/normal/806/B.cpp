#include <iostream>
#include <utility>

typedef long double ld;
typedef long long ll;
typedef std::pair<ll, ll> ii;

int n;

int tim[220][6];
int freq[6];

int divid[6] = {32, 16, 8, 4, 2, 1};
ll points[6] = {3000, 2500, 2000, 1500, 1000, 500};

bool can(int use)
{
	//std::cout << "using " << use << "\n";
	ll users = use + n;
	ll diff = 0;
	ii to[6];
	for(int i = 0; i < 6; i++)
		to[i].second = (users) / divid[i];
	to[0].first = 0;
	for(int i = 1; i < 6; i++)
		to[i].first = to[i - 1].second + 1;
	for(int i = 0; i < 5; i++)
	{
		ll max = 500;
		for(int j = 0; j < 6; j++)
		{
			if(to[j].first <= freq[i] && freq[i] <= to[j].second)
				max = std::max(max, points[j]);
		}
		ll min = 3500;
		for(int j = 0; j < 6; j++)
		{
			if(to[j].first <= use + freq[i] && use + freq[i] <= to[j].second)
				min = std::min(points[j], min);
		}
		ll my = 0;
		if(tim[0][i] != -1)
		{
			my = 250 - tim[0][i];
			//std::cout << "i solved, " << my << "\n";
		}
		ll him = 0;
		if(tim[1][i] != -1)
		{
			him = 250 - tim[1][i];
			//std::cout << "he solved, " << him << "\n";
		}
		ll now_diff = 0;
		if(my > him || my == 0)
			now_diff += max * (my - him);
		else
			now_diff += min * (my - him);
		diff += now_diff;
		//std::cout << "on problem " << i << ", diff is " << now_diff << " (" << max << ", " << min << ")\n";
	}
	//std::cout << "\n\n\n";
	return diff > 0;
}

int main()
{
	while(std::cin >> n)
	{
		//std::cout << "n is " << n << '\n';
		for(int i = 0; i < 5; i++)
			freq[i] = 0;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < 5; j++)
			{
				std::cin >> tim[i][j];
				if(tim[i][j] != -1)
					freq[j]++;
			}
		}
		/*int l = 0;
		int r = 1e7;
		while(l != r)
		{
			int mid = (l + r) / 2;
			if(can(mid))
				r = mid;
			else
				l = mid + 1;
		}

		if(can(l))
			std::cout << l << '\n';
		else
			std::cout << "-1\n";*/
		int ans = -1;
		for(int i = 0; i < 1e6; i++)
		{
			if(can(i))
			{
				ans = i;
				break;
			}
		}
		std::cout << ans << '\n';
	}
}