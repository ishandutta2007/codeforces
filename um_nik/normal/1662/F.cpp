#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
    #define eprintf(...) {fprintf(stderr, __VA_ARGS__); fflush(stderr);}
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

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 200005;
const int mxtreesize = 1 << 18;
const int inf = 1e9;

int treel[2 * mxtreesize + 10], treer[2 * mxtreesize + 10];
int n;
int d[maxn];
int p[maxn];
queue<int> q;
int start, finish;

void find(int *tree, int cur, int cl, int cr, int l, int r, int th, int dd)
{
	if (cl > r || cr < l) return;
	if (cl >= l && cr <= r && tree[cur] < th) return;
	if (cl == cr)
	{
		if (d[cl] > dd)
		{
			d[cl] = dd;
			q.push(cl);
		}
		tree[cur] = -inf;
		return;
	}
	int cm = (cl + cr) / 2;
	find(tree, cur * 2, cl, cm, l, r, th, dd);
	find(tree, cur * 2 + 1, cm + 1, cr, l, r, th, dd);
	tree[cur] = max(tree[cur * 2], tree[cur * 2 + 1]);
}

void solve()
{
	scanf("%d%d%d", &n, &start, &finish);
	start--, finish--;
	for (int i = 0; i < n; i++) scanf("%d", &p[i]);
	int treesize = 1;
	while (treesize < n) treesize *= 2;
	for (int i = 0; i < n; i++)
	{
		treel[treesize + i] = i + p[i];
		treer[treesize + i] = p[i] - i;
	}
	treel[treesize + start] = -inf;
	treer[treesize + start] = -inf;
	for (int i = n; i < treesize; i++)
	{
		treel[treesize + i] = -inf;
		treer[treesize + i] = -inf;
	}
	for (int i = treesize - 1; i > 0; i--)
	{
		treel[i] = max(treel[2 * i], treel[2 * i + 1]);
		treer[i] = max(treer[2 * i], treer[2 * i + 1]);
	}
	for (int i = 0; i < n; i++) d[i] = inf;
	d[start] = 0;
	q.push(start);
	while (!q.empty())
	{
		int i = q.front();
		q.pop();
		//~ cout << i << ' ' << d[i] << endl;
		find(treel, 1, 0, treesize - 1, i - p[i], i - 1, i, d[i] + 1);
		find(treer, 1, 0, treesize - 1, i + 1, i + p[i], -i, d[i] + 1);
	}
	printf("%d\n", d[finish]);
}

int main()
{
	int NT;
	scanf("%d", &NT);
	for (int T = 0; T < NT; T++) solve();
    return 0;
}