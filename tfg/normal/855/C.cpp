#include <iostream>
#include <vector>

typedef long long ll;

const int ms = 100100;
const ll MOD = 1e9 + 7;

std::vector<int> edges[ms];

ll n, m, x, k;
ll types[3];
ll memo[3][ms][11];
bool visit[3][ms];

ll trans[11];
ll temp[11];

void init()
{
	for(int i = 0; i <= x; i++)
		trans[i] = 0;
}

void incl(int v1, int p1)
{
	for(int i = 0; i <= x; i++)
		trans[i] = (trans[i] + memo[v1][p1][i]) % MOD;
}

void combine(int v1, int p1)
{
	for(int i = 0; i <= x; i++)
		temp[i] = 0;
	for(int i = 0; i <= x; i++)
	{
		for(int j = 0; i + j <= x; j++)
		{
			temp[i + j] = (temp[i + j] + memo[v1][p1][i] * trans[j]) % MOD;
		}
	}
	for(int i = 0; i <= x; i++)
		memo[v1][p1][i] = temp[i];
}

void dp(int val, int on, int par = -1)
{
	if(visit[val][on])
		return;
	visit[val][on] = true;
	if(val == 0 || val == 2)
		memo[val][on][0] = types[val];
	else
		memo[val][on][1] = types[val];
	/*std::cout << "starting (" << val << ", " << on << ") =";
	for(int i = 0; i <= x; i++)
		std::cout << ' ' << memo[val][on][i];
	std::cout << '\n';*/
	for(auto to : edges[on])
	{
		if(to == par)
			continue;
		for(int j = 0; j < 3; j++)
			dp(j, to, on);
		init();
		//if(1)
		incl(0, to);
		if(val == 0)
			incl(1, to);
		if(val == 0 || val == 2)
			incl(2, to);
		combine(val, on);
	}
	/*std::cout << "finished (" << val << ", " << on << ") =";
	for(int i = 0; i <= x; i++)
		std::cout << ' ' << memo[val][on][i];
	std::cout << '\n';*/
}


int main()
{
	std::cin >> n >> m;
	for(int i = 1; i < n; i++)
	{
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	std::cin >> k >> x;
	types[0] = k - 1;
	types[1] = 1;
	types[2] = m - k;
	ll ans = 0;
	for(int i = 0; i < 3; i++)
	{
		dp(i, 0);
		for(int j = 0; j <= x; j++)
		{
			ans = (ans + memo[i][0][j]) % MOD;
		}
	}
	std::cout << ans << '\n';
}