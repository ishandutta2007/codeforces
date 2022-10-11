#include <iostream>
#include <set>
#include <utility>
#include <stack>
#include <map>
#include <cstring>
#include <queue>
#include <vector>

typedef std::pair<int, int> ii;
typedef std::pair<ii, ii> i4;

const int ms = 10100;
const int INF = 0x3f3f3f3f;

int dist[ms][2][3];
std::set<ii> to[2][ms];
std::vector<ii> edges[2][ms];
std::vector<int> fok[2][ms];
std::map<ii, int> wut;

int dij(int start, int end, int hmm)
{
	//std::cout << "hmm is " << hmm << '\n';
	std::priority_queue<i4, std::vector<i4>, std::greater<i4> > hp;
	memset(dist, 0x3f, sizeof dist);
	dist[start][0][0] = 0;
	hp.push(i4(ii(0, start), ii(0, 0)));
	while(!hp.empty())
	{
		int on = hp.top().first.second;
		int dir = hp.top().second.first;
		int payed = hp.top().second.second;
		int cur_dist = hp.top().first.first;
		hp.pop();
		if(cur_dist > dist[on][dir][payed])
			continue;
		//std::cout << "on (" << on << ", " << cur_dist << ", " << dir << ", " << payed << ")\n";
		for(int i = 0; i < edges[dir][on].size(); i++)
		{
			auto a = edges[dir][on][i];
			int to = a.first;
			int to_cost;
			int to_payed;
			int to_dir;
			if(payed == 2 && fok[dir][on][i] != 0)
				continue;
			if(payed == 2 && to == hmm)
				continue;
			if(fok[dir][on][i] == 0)
			{
				if(payed == 2)
				{
					to_cost = 0;
					to_payed = 2;
				}
				else if(payed == 1)
				{
					to_cost = 0;
					to_payed = 1;
				}
				else if(to == hmm)
				{
					to_cost = 1;
					to_payed = 1;
				}
				else if(a.second <= 1)
				{
					to_cost = 0;
					to_payed = 0;
				}
				else
				{
					to_cost = 1;
					to_payed = 1;
				}
				to_dir = dir;
			}
			else if(fok[dir][on][i] == 1)
			{
				if(to == hmm)
				{
					to_payed = 1;
					to_cost = 1;
					to_dir = dir;
				}
				else if(payed == 1)
				{
					to_payed = 0;
					to_cost = 0;
					to_dir = dir;
				}
				else if(a.second <= 2)
				{
					to_payed = 1;
					to_cost = 1;
					to_dir = 1 - dir;
				}
				else
				{
					to_payed = 1;
					to_cost = 1;
					to_dir = dir;
				}
			}
			else
			{
				if(to == hmm)
					continue;
				to_payed = 2;
				to_cost = 1;
				to_dir = dir;
			}
			//to_cost = std::max(0, a.second - 1);
			//to_payed = 0;
			int to_dist = cur_dist + to_cost;
			if(to_dist < dist[to][to_dir][to_payed])
			{
				//std::cout << "from (" << on << ", " << cur_dist << ", " << dir << ", " << payed << ") to (" << to << ", " << to_dist << ", " << dir << ", " << to_payed << ")\n";
				//std::cout << "diff is " << a.second << "\n";
				hp.push(i4(ii(to_dist, to), ii(to_dir, to_payed)));
				dist[to][to_dir][to_payed] = to_dist;
			}
		}
		if(dist[on][1 - dir][0] > cur_dist)
		{
			hp.push(i4(ii(cur_dist, on), ii(1 - dir, 0)));
			dist[on][1 - dir][0] = cur_dist;
		}
	}
	return std::min(std::min(dist[end][0][0], dist[end][0][1]), std::min(dist[end][1][0], dist[end][1][1]));
}

int main()
{
	int n, m, k;
	std::cin >> n >> m >> k;
	for(int i = 0; i < k; i++)
	{
		int r, c;
		std::cin >> r >> c;
		r++;
		c++;
		to[0][r].insert(ii(c, i));
		to[1][c].insert(ii(r, i));
		wut[ii(r, c)] = i;
	}
	to[0][n + 1].insert(ii(m + 1, k));
	to[1][m + 1].insert(ii(n + 1, k));
	for(int i = 2; i < ms - 2; i++)
	{
		int prv = -1, coord = 0;
		for(auto a : to[0][i])
		{
			if(prv != -1)
			{
				//std::cout << "adding edge on row " << i << ", from " << prv << " to " << a.second << "\n";
				edges[0][a.second].push_back(ii(prv, a.first - coord));
				edges[0][prv].push_back(ii(a.second, a.first - coord));
				fok[0][a.second].push_back(0);
				fok[0][prv].push_back(0);
			}
			prv = a.second;
			coord = a.first;
			auto it = to[0][i - 1].lower_bound(ii(coord, -1));
			if(it != to[0][i - 1].end())
			{
				edges[0][a.second].push_back(ii(it->second, it->first - a.first + 1));
				edges[0][it->second].push_back(ii(a.second, it->first - a.first + 1));
				fok[0][a.second].push_back(1);
				fok[0][it->second].push_back(1);
			}
			it = to[0][i + 1].lower_bound(ii(coord, -1));
			if(it != to[0][i + 1].end())
			{
				edges[0][a.second].push_back(ii(it->second, it->first - a.first + 1));
				edges[0][it->second].push_back(ii(a.second, it->first - a.first + 1));
				fok[0][a.second].push_back(1);
				fok[0][it->second].push_back(1);
			}
			it = to[0][i + 2].lower_bound(ii(coord, -1));
			if(it != to[0][i + 2].end())
			{
				edges[0][a.second].push_back(ii(it->second, it->first - a.first + 1));
				edges[0][it->second].push_back(ii(a.second, it->first - a.first + 1));
				fok[0][a.second].push_back(2);
				fok[0][it->second].push_back(2);
			}
			it = to[0][i - 2].lower_bound(ii(coord, -1));
			if(it != to[0][i - 2].end())
			{
				edges[0][a.second].push_back(ii(it->second, it->first - a.first + 1));
				edges[0][it->second].push_back(ii(a.second, it->first - a.first + 1));
				fok[0][a.second].push_back(2);
				fok[0][it->second].push_back(2);
			}
		}
		prv = -1, coord = 0;
		for(auto a : to[1][i])
		{
			if(prv != -1)
			{
				//std::cout << "adding edge on col " << i << ", from " << prv << " to " << a.second << "\n";
				edges[1][a.second].push_back(ii(prv, a.first - coord));
				edges[1][prv].push_back(ii(a.second, a.first - coord));
				fok[1][a.second].push_back(0);
				fok[1][prv].push_back(0);
			}
			prv = a.second;
			coord = a.first;
			auto it = to[1][i - 1].lower_bound(ii(coord, -1));
			if(it != to[1][i - 1].end())
			{
				edges[1][a.second].push_back(ii(it->second, it->first - a.first + 1));
				edges[1][it->second].push_back(ii(a.second, it->first - a.first + 1));
				fok[1][a.second].push_back(1);
				fok[1][it->second].push_back(1);
			}
			it = to[1][i + 1].lower_bound(ii(coord, -1));
			if(it != to[1][i + 1].end())
			{
				edges[1][a.second].push_back(ii(it->second, it->first - a.first + 1));
				edges[1][it->second].push_back(ii(a.second, it->first - a.first + 1));
				fok[1][a.second].push_back(1);
				fok[1][it->second].push_back(1);
			}
			it = to[1][i + 2].lower_bound(ii(coord, -1));
			if(it != to[1][i + 2].end())
			{
				edges[1][a.second].push_back(ii(it->second, it->first - a.first + 1));
				edges[1][it->second].push_back(ii(a.second, it->first - a.first + 1));
				fok[1][a.second].push_back(2);
				fok[1][it->second].push_back(2);
			}
			it = to[1][i - 2].lower_bound(ii(coord, -1));
			if(it != to[1][i - 2].end())
			{
				edges[1][a.second].push_back(ii(it->second, it->first - a.first + 1));
				edges[1][it->second].push_back(ii(a.second, it->first - a.first + 1));
				fok[1][a.second].push_back(2);
				fok[1][it->second].push_back(2);
			}
		}
	}
	int ans = dij(wut[ii(2, 2)], k, wut.count(ii(n + 1, m + 1)) == 0 ? k : -1);
	if(ans >= INF)
		ans = -1;
	std::cout << ans << '\n';
}