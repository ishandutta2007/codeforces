#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>

typedef std::pair<int, int> ii;
typedef long long ll;

struct Bit2D
{
public:
	Bit2D(std::vector<ii> pts)
	{
		std::sort(pts.begin(), pts.end());
		for(auto a : pts)
		{
			if(ord.empty() || a.first != ord.back())
				ord.push_back(a.first);
		}
		fw.resize(ord.size() + 1);
		coord.resize(fw.size());
		for(auto &a : pts)
			std::swap(a.first, a.second);
		std::sort(pts.begin(), pts.end());
		for(auto &a : pts)
		{
			std::swap(a.first, a.second);
			for(int on = std::upper_bound(ord.begin(), ord.end(), a.first) - ord.begin(); on < fw.size(); on += on & -on)
			{
				if(coord[on].empty() || coord[on].back() != a.second);
					coord[on].push_back(a.second);
			}
		}
		for(int i = 0; i < fw.size(); i++)
		{
			fw[i].assign(coord[i].size() + 1, 0);
		}
	}

	void upd(int x, int y, int v)
	{
		//std::cout << "updating (" << x << ", " << y << ", " << v << ")\n";
		for(int xx = std::upper_bound(ord.begin(), ord.end(), x) - ord.begin(); xx < fw.size(); xx += xx & -xx)
		{
			for(int yy = std::upper_bound(coord[xx].begin(), coord[xx].end(), y) - coord[xx].begin(); yy < fw[xx].size(); yy += yy & -yy)
			{
				fw[xx][yy] += v;
			}
		}
	}

	ll qry(int x, int y)
	{
		//std::cout << "taking qry(" << x << ", " << y << ")\n";
		ll ans = 0;
		for(int xx = std::upper_bound(ord.begin(), ord.end(), x) - ord.begin(); xx > 0; xx -= xx & -xx)
		{
			for(int yy = std::upper_bound(coord[xx].begin(), coord[xx].end(), y) - coord[xx].begin(); yy > 0; yy -= yy & -yy)
			{
				ans += fw[xx][yy];
			}
		}
		//std::cout << "got " << ans << "\n";
		return ans;
	}

	ll qry(int x1, int x2, int y1, int y2)
	{
		ll ans = 0;
		ans += qry(x2, y2);
		ans -= qry(x1 - 1, y2);
		ans -= qry(x2, y1 - 1);
		ans += qry(x1 - 1, y1 - 1);
		return ans;
	}
private:
	std::vector<int> ord;
	std::vector<std::vector<ll>> fw, coord;
};

struct query
{
	int type, a, b;
	void read()
	{
		std::cin >> type >> a >> b;
		a--;
		b--;
	}
};

int main()
{
	int n, m;
	std::cin >> n >> m;
	std::vector<ii> pts;
	std::vector<int> a, b;
	for(int i = 0; i < n; i++)
	{
		int temp;
		std::cin >> temp;
		temp--;
		a.push_back(temp);
	}
	b = a;
	std::set<int> position[n + 1];
	for(int i = 0; i < n; i++)
	{
		auto it = position[a[i]].end();
		if(it != position[a[i]].begin())
		{
			it--;
			pts.emplace_back(*it, i);
		}
		position[a[i]].insert(i);
	}
	std::vector<query> qries;
	for(int i = 0; i < m; i++)
	{
		query cur;
		cur.read();
		qries.push_back(cur);
		if(cur.type == 1)
		{
			//change pos a into b
			auto it = position[a[cur.a]].lower_bound(cur.a);
			int l = -1;
			int r = -1;
			if(it != position[a[cur.a]].begin())
			{
				it--;
				l = *it;
				it++;
			}
			it++;
			if(it != position[a[cur.a]].end())
			{
				r = *it;
			}
			it--;
			if(l != -1 && r != -1)
			{
				pts.emplace_back(l, r);
			}
			position[a[cur.a]].erase(cur.a);
			it = position[cur.b].lower_bound(cur.a);
			l = -1;
			r = -1;
			if(it != position[cur.b].end())
			{
				r = *it;
			}
			if(it != position[cur.b].begin())
			{
				it--;
				l = *it;
			}
			if(l != -1)
			{
				pts.emplace_back(l, cur.a);
			}
			if(r != -1)
			{
				pts.emplace_back(cur.a, r);
			}
			if(l != -1 && r != -1)
			{

			}
			a[cur.a] = cur.b;
			position[cur.b].insert(cur.a);
		}
		else
		{
			//get and [a, b]

		}
	}
	a = b;
	Bit2D fw(pts);
	for(int i = 0; i < n; i++)
	{
		position[i].clear();
	}
	for(int i = 0; i < n; i++)
	{
		auto it = position[a[i]].end();
		if(it != position[a[i]].begin())
		{
			it--;
			fw.upd(*it, i, i - *it);
		}
		position[a[i]].insert(i);
	}
	for(int i = 0; i < m; i++)
	{
		query cur = qries[i];
		if(cur.type == 1)
		{
			//change pos a into b
			if(a[cur.a] == cur.b)
				continue;
			auto it = position[a[cur.a]].lower_bound(cur.a);
			int l = -1;
			int r = -1;
			if(it != position[a[cur.a]].begin())
			{
				it--;
				l = *it;
				it++;
			}
			it++;
			if(it != position[a[cur.a]].end())
			{
				r = *it;
			}
			it--;
			if(l != -1)
			{
				fw.upd(l, cur.a, -(cur.a - l));
			}
			if(r != -1)
			{
				fw.upd(cur.a, r, -(r - cur.a));
			}
			if(l != -1 && r != -1)
			{
				fw.upd(l, r, r - l);
			}
			position[a[cur.a]].erase(cur.a);
			it = position[cur.b].lower_bound(cur.a);
			l = -1;
			r = -1;
			if(it != position[cur.b].end())
			{
				r = *it;
			}
			if(it != position[cur.b].begin())
			{
				it--;
				l = *it;
			}
			if(l != -1)
			{
				fw.upd(l, cur.a, cur.a - l);
			}
			if(r != -1)
			{
				fw.upd(cur.a, r, r - cur.a);
			}
			if(l != -1 && r != -1)
			{
				fw.upd(l, r, -(r - l));
			}
			a[cur.a] = cur.b;
			position[cur.b].insert(cur.a);
		}
		else
		{
			//get and [a, b]
			std::cout << fw.qry(cur.a, cur.b, cur.a, cur.b) << '\n';
		}
	}
}