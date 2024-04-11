#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using D = double;
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

const int maxn = 505;

vector<int> gr[maxn];
bool ban[maxn];
int was[maxn];
bool inc[maxn];
vector<int> cycle;
int sz[maxn];
int backto[maxn];
int ncycles;
int curn;
int ok;
int n;
int sumsz[maxn];
int d[maxn][maxn];
int d2[2][maxn];
queue<int> q;
int QUERY;
int maxpart[maxn];
vector<pair2<int>> edges;

void calcd(int start, int *d)
{
	for (int i = 0; i < n; i++) d[i] = n + 5;
	d[start] = 0;
	q.push(start);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto t : gr[cur]) if (d[t] > d[cur] + 1)
		{
			d[t] = d[cur] + 1;
			q.push(t);
		}
	}
}

int askme(int x)
{
	if (x == QUERY) return -1;
	vector<int> poss;
	//calcd(x, d[0]);
	calcd(QUERY, d2[0]);
	for (auto t : gr[x]) if (d2[0][t] < d2[0][x]) poss.pb(t);
	return poss[rng() % poss.size()];
}

char s[10];

int ask(int x)
{
	//cout << "ask " << x << endl;
	//int res = askme(x);
	//cout << "ret " << res << endl;
	//return res;
	printf("%d\n", x + 1);
	fflush(stdout);
	scanf("%s", s);
	if (s[0] == 'F') return -1;
	int ret;
	scanf("%d", &ret);
	return ret - 1;
}

int find(int cur, int pr)
{
	was[cur] = 1;
	int ret = -1;
	sz[cur] = 1;
	bool wasbig = false;
	for (auto t : gr[cur]) if (t != pr && !ban[t] && was[t] != 2)
	{
		//cout << "go " << cur << ' ' << t << endl;
		if (was[t] == 1)
		{
			assert(ret == -1);
			//cout << "found cycle " << t << endl;
			ret = ncycles++;
			backto[ret] = t;
		} else
		{
			int ret_from_t = find(t, cur);
			sz[cur] += sz[t];
			wasbig |= sz[t] * 2 > curn;
			if (ret_from_t != -1)
			{
				if (backto[ret_from_t] == cur)
				{
					//int szother = cycle[ret_from_t].back().se;
					//cycle[ret_from_t].pb({cur, curn - szother});
				} else
				{
					assert(ret == -1);
					ret = ret_from_t;
				}
			}
		}
	}
	was[cur] = 2;
	if (ret == -1)
	{
		//ret = minic++;
		//cycle[minic].pb({cur, sz[cur]});
	}
	if (!wasbig && sz[cur] * 2 > curn)
	{
		ok = cur;
	}
	//cout << "find " << cur << ' ' << sz[cur] << ' ' << ret << endl;
	return ret;
}

bool calcsz(int cur, int pr)
{
	was[cur] = true;
	bool ret = false;
	sz[cur] = 1;
	for (auto t : gr[cur]) if (t != pr && !ban[t])
	{
		if (was[t] == true)
		{
			if (t == ok) ret = true;
			continue;
		}
		bool ret_from_t = calcsz(t, cur);
		if (!ret_from_t) sz[cur] += sz[t];
		ret |= ret_from_t;
	}
	if (ret) cycle.pb(cur);
	return ret;
}

void markban(int center, int closer)
{
	calcd(center, d2[0]);
	calcd(closer, d2[1]);
	for (int i = 0; i < n; i++) if (!ban[i] && d2[0][i] <= d2[1][i]) ban[i] = true;
	//cout << "markban " << center << ' ' << closer << endl;
	//for (int i = 0; i < n; i++) cout << d[0][i] << ' ' << d[1][i] << ' ' << ban[i] << endl;
}

void solve()
{
	int qs = 0;
	while (true)
	{
		qs++;
		//assert(qs <= 10);
		if (qs > 10)
		{
			while (true);
		}
		curn = 0;
		for (int i = 0; i < n; i++) curn += (ban[i] == 0);
		//cout << "new IT " << curn << endl;
		//for (int i = 0; i < n; i++) cout << ban[i];
		//cout << endl;
		for (int i = 0; i < n; i++) maxpart[i] = 0;
		for (auto e : edges)
		{
			int bad1 = 0;
			int bad2 = 0;
			for (int i = 0; i < n; i++) if (!ban[i])
			{
				if (d[e.se][i] < d[e.fi][i]) bad1++;
				if (d[e.se][i] > d[e.fi][i]) bad2++;
			}
			//cout << d[0][0] << endl;
			//cout << d[e.fi][0] << ' ' << d[e.se][0] << endl;
			//cout << e.fi << ' ' << e.se << ' ' << bad1 << ' ' << bad2 << endl;
			maxpart[e.fi] = max(maxpart[e.fi], bad1);
			maxpart[e.se] = max(maxpart[e.se], bad2);
		}
		int whask = -1;
		for (int i = 0; i < n; i++) if (!ban[i] && (whask == -1 || maxpart[i] < maxpart[whask])) whask = i;
		//for (int i = 0; i < n; i++) cout << i << ' ' << maxpart[i] << endl;
		//assert(maxpart[whask] * 2 <= curn);
		int ret = ask(whask);
		if (ret == -1) break;
		markban(whask, ret);
	}
}

int main()
{
	int npaths;
	scanf("%d%d", &n, &npaths);
	for (int i = 0; i < npaths; i++)
	{
		int l;
		scanf("%d", &l);
		int lst;
		scanf("%d", &lst);
		lst--;
		for (int j = 0; j < l - 1; j++)
		{
			int x;
			scanf("%d", &x);
			x--;
			edges.pb({x, lst});
			gr[x].pb(lst);
			gr[lst].pb(x);
			lst = x;
		}
	}
	
	for (int i = 0; i < n; i++) calcd(i, d[i]);
	
	for (int IT = 0; IT < n; IT++)
	//for (int QUERY = 0; QUERY < n; QUERY++)
	{
		//cout << "new test " << QUERY << endl;
		memset(ban, 0, sizeof ban);
		solve();
	}
	
    return 0;
}