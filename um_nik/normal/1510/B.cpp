#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

struct tedge
{
	int to, f, maxf, cost, o;
};

const int maxn = (1 << 12) + 5;
const int inf = 1e5;

vector<tedge> gr[maxn];
int d[maxn];
bool inq[maxn];
queue<int> q;
char s[20];
int n, m;
int from[maxn];
vector<char> answer;

void addedge(int a, int b, int maxf, int cost)
{
	int sza = gr[a].size();
	int szb = gr[b].size();
	gr[a].pb({b, 0, maxf, cost, szb});
	gr[b].pb({a, 0, 0, -cost, sza});
}

void maxflow(int nn)
{
	while (true)
	{
		for (int i = 0; i < nn; i++)
		{
			d[i] = inf;
			inq[i] = false;
		}
		d[0] = 0;
		inq[0] = true;
		q.push(0);
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			//cout << cur << ' ' << d[cur] << endl;
			inq[cur] = false;
			for (auto e : gr[cur]) if (e.f < e.maxf && d[e.to] > d[cur] + e.cost)
			{
				//cout << "check " << e.to << ' ' << e.maxf << endl;
				d[e.to] = d[cur] + e.cost;
				from[e.to] = e.o;
				if (!inq[e.to])
				{
					q.push(e.to);
					inq[e.to] = true;
				}
			}
		}
		//cout << "flow " << d[nn - 1] << endl;
		if (d[nn - 1] >= 0) break;
		int cur = nn - 1;
		while (cur != 0)
		{
			int nxte = from[cur];
			int nxtv = gr[cur][nxte].to;
			gr[cur][nxte].f--;
			nxte = gr[cur][nxte].o;
			cur = nxtv;
			gr[cur][nxte].f++;
		}
	}
}

int main()
{
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", s);
		int x = 0;
		for (int i = 0; i < m; i++) if (s[i] == '1') x += (1 << i);
		addedge(2 * x, 2 * x + 1, 1, -inf);
	}
	int nn = 2 * (1 << m) + 1;
	for (int mask = 0; mask < (1 << m); mask++)
	{
		addedge(2 * mask, 2 * mask + 1, inf, 0);
		if (mask != 0) addedge(2 * mask + 1, nn - 1, inf, 1);
		for (int i = 0; i < m; i++) if (!(mask & (1 << i)))
		{
			addedge(2 * mask + 1, 2 * (mask | (1 << i)), inf, 1);
		}
	}
	
	maxflow(nn);
	while (true)
	{
		int cur = 0;
		bool bad = false;
		while (cur != nn - 1)
		{
			bool found = false;
			for (auto &e : gr[cur]) if (e.f > 0)
			{
				found = true;
				if ((cur & 1) == 1 && (e.to & 1) == 0 && e.to != nn - 1)
				{
					int a = cur >> 1;
					int b = e.to >> 1;
					answer.pb('0' + __builtin_ctz(a ^ b));
				}
				if (e.to == nn - 1) answer.pb('R');
				e.f--;
				cur = e.to;
				break;
			}
			if (!found)
			{
				bad = true;
				break;
			}
		}
		if (bad) break;
	}
	answer.pop_back();
	printf("%d\n", (int)answer.size());
	for (auto c : answer) printf("%c ", c);
	printf("\n");
    return 0;
}