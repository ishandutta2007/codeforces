#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iomanip>
#include <cmath>

typedef long long ll;

const int ms = 1010;
const double PI = acos(-1.0);

struct PT
{
	PT(){PT(0, 0);}
	PT(ll x, ll y){this->x = x;this->y = y;}
	bool inside(PT a)
	{
		ll sum = r + a.r;
		return distsq(a) < sum * sum;
	}

	ll distsq(PT a)
	{
		ll dx = x - a.x;
		ll dy = y - a.y;
		return dx * dx + dy * dy;
	}

	void read()
	{
		std::cin >> x >> y >> r;
	}

	void print()
	{
		std::cout << "(" << x << ", " << y << ")";
	}

	ll x, y, r;

	bool operator < (PT a){return r > a.r;}
};

PT pts[ms];

std::vector<int> edges[ms];
ll memo[ms][4];
bool visit[ms][4];
int par[ms];
ll dp(int on, int mask)
{
	ll &ans = memo[on][mask];
	if(visit[on][mask])
		return ans;
	visit[on][mask] = true;
	ans = 0;
	int f = mask % 2 == 1 ? -1 : 1;
	int s = mask / 2 == 1 ? -1 : 1;
	for(int i = 0; i < edges[on].size(); i++)
	{
		int to = edges[on][i];
		ll cost = pts[to].r * pts[to].r;
		dp(to, mask ^ 1);
		dp(to, mask ^ 2);
		/*std::cout << "on (" << on << ", " << mask << ") got ";pts[to].print();
		if(f * cost + dp(to, mask ^ 1) > s * cost + dp(to, mask ^ 2))
			std::cout << " on first, cost" << f << "\n";
		else
			std::cout << " on second, cost " << s << "\n";*/
		ans += std::max(f * cost + dp(to, mask ^ 1), s * cost + dp(to, mask ^ 2));
	}
	return ans;
}

int main()
{
	int n;
	std::cout << std::fixed << std::setprecision(20);
	while(std::cin >> n)
	{
		for(int i = 0; i < n; i++)
			pts[i].read();
		std::sort(pts, pts + n);
		memset(visit, 0, sizeof visit);
		for(int i = 0; i < n; i++)
		{
			par[i] = i;
			for(int j = i - 1; j >= 0 && par[i] == i; j--)
			{
				if(pts[i].inside(pts[j]))
				{
					par[i] = j;
					edges[j].push_back(i);
				}
			}
		}
		ll ans = 0;
		for(int i = 0; i < n; i++)
		{
			if(par[i] == i)
			{
				//pts[i].print();
				ans += pts[i].r * pts[i].r + dp(i, 1);
			}
			edges[i].clear();
		}
		std::cout << (double) ans * PI << '\n';
	}
}