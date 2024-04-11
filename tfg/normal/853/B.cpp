#include <iostream>
#include <vector>
#include <utility>

typedef long long ll;
typedef std::pair<ll, ll> ii;

const int ms = 2002000;
const ll INF = 1e16;

int n, m, k;

std::vector<ii> endings[ms], starts[ms];

ll from[ms], end[ms], val[ms];
int step[ms], cur_step = 0;


int main()
{
	std::cin >> n >> m >> k;
	for(int i = 0; i < m; i++)
	{
		int day, u, v, cost;
		scanf("%i %i %i %i", &day, &u, &v, &cost);
		if(u == 0)
			endings[day].push_back(ii(v, cost));
		else
			starts[day].push_back(ii(u, cost));
	}
	cur_step++;
	ll sum = ll(1e7) * n;
	int count = 0;
	for(int i = 1; i <= n; i++)
		val[i] = ll(1e7);
	for(int i = 0; i < ms; i++)
	{
		for(auto a : starts[i])
		{
			sum -= val[a.first];
			val[a.first] = std::min(val[a.first], a.second);
			sum += val[a.first];
			if(step[a.first] != cur_step)
			{
				//std::cout << "got " << a.first << " on start " << i << '\n';
				count++;
				step[a.first] = cur_step;
			}
		}
		if(count == n)
			from[i] = sum;
		else
			from[i] = INF;
	}
	sum = ll(1e7) * n;
	cur_step++;
	count = 0;
	for(int i = 1; i <= n; i++)
		val[i] = ll(1e7);
	for(int i = ms - 1; i >= 0; i--)
	{
		for(auto a : endings[i])
		{
			sum -= val[a.first];
			val[a.first] = std::min(val[a.first], a.second);
			sum += val[a.first];
			if(step[a.first] != cur_step)
			{
				//std::cout << "got " << a.first << " on end " << i << '\n';
				count++;
				step[a.first] = cur_step;
			}
		}
		if(count == n)
			end[i] = sum;
		else
			end[i] = INF;
	}
	ll ans = INF;
	for(int i = 0; i + k + 1 < ms; i++)
		ans = std::min(ans, from[i] + end[i + k + 1]);
	if(ans >= INF)
		ans = -1;
	std::cout << ans << '\n';
}