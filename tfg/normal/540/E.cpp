#include <iostream>
#include <set>
#include <vector>
#include <map>

class BIT
{
public:
	BIT(int n){bit = std::vector<int>(n, 0);}
	int qry(int x)
	{
		int ans = 0;
		for(; x > 0; x -= x & -x)
			ans += bit[x];
		return ans;
	}
	int upd(int x, int v)
	{
		for(; x < bit.size(); x += x & -x)
			bit[x] += v;
	}
private:
	std::vector<int> bit;
};

int main()
{
	int n;
	std::cin >> n;
	std::set<int> pos;
	std::map<int, int> cur, ord, to;
	while(n--)
	{
		int u, v;
		std::cin >> u >> v;
		if(cur[u] == 0)
		{
			cur[u] = u;
			pos.insert(u);
		}
		if(cur[v] == 0)
		{
			cur[v] = v;
			pos.insert(v);
		}
		std::swap(cur[u], cur[v]);
	}
	n = 1;
	for(auto a:pos)
		ord[a] = n++;
	for(auto a:pos)
		to[cur[a]] = a;
	BIT fw(n + 2);
	long long ans = 0;
	for(auto a:pos)
	{
		int cur_pos = ord[to[a]];
		int bef = fw.qry(cur_pos);
		int aft = ord[a] - bef - 1;
		//std::cout << to[a] << ": on pos " << a << ", got (" << bef << ", " << aft << "), ord is " << cur_pos << "\n";
		ans += aft;
		if(to[a] >= a)
			ans += to[a] - a - (ord[to[a]] - ord[a]);
		else
			ans += a - to[a] - (ord[a] - ord[to[a]]);
		fw.upd(cur_pos, 1);
	}
	std::cout << ans << "\n";
}