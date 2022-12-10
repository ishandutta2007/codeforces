#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <utility>
#include <stack>
#include <set>
#include <algorithm>
#include <bitset>
#include <functional>
#include <ctime>
#include <cassert>
#include <valarray>
#include <unordered_map>
#pragma comment(linker, "/STACK:167772160")

using namespace std;
#pragma region TypeDefs

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef vector< vector<int> > vvint;

#pragma endregion

const int INF = 1e9 + 10;
const ll LINF = (ll) 2e18 + 10;
const ld PI = acos(-1);
const ld eps = 1e-8;
const ld EPS = 1e-12;

const int N = 1e5 + 10;
const int LOGN = 20;

struct Vertex
{
	vector<int> edges;
	int size;
	int anc[LOGN], tin, tout;
	ll sum, height, up_sum;
	Vertex() 
	{
		fill(anc, anc + LOGN, 0);
	}
};

int n, m;
Vertex vertices[N];

int cur_time;
void dfs(int v)
{
	vertices[v].tin = cur_time++;
	vertices[v].size = 1;
	vertices[v].sum = vertices[v].height;
	for (int i = 1; i < LOGN; ++i)
		vertices[v].anc[i] = vertices[vertices[v].anc[i - 1]].anc[i - 1];
	for (auto e : vertices[v].edges)
		if (e != vertices[v].anc[0])
		{
			vertices[e].height = vertices[v].height + 1;
			vertices[e].anc[0] = v;
			dfs(e);
			vertices[v].size += vertices[e].size;
			vertices[v].sum += vertices[e].sum;
		}
	vertices[v].tout = cur_time++;
}

void dfs2(int v, ll up_sum)
{
	vertices[v].up_sum = up_sum;
	for(auto e : vertices[v].edges)
		if (e != vertices[v].anc[0])
		{
			ll new_up_sum = up_sum;
			new_up_sum += vertices[v].sum;
			new_up_sum -= vertices[e].sum;
			new_up_sum -= vertices[v].height * (vertices[v].size - vertices[e].size);
			new_up_sum += vertices[0].size - vertices[e].size;
			dfs2(e, new_up_sum);
		}
}

bool is_anc(int a, int b)
{
	return vertices[a].tin <= vertices[b].tin && vertices[b].tout <= vertices[a].tout;
}

int get_lca(int a, int b)
{
	int now = a;
	for (int h = LOGN - 1; h >= 0; --h)
		if (!is_anc(vertices[now].anc[h], b))
			now = vertices[now].anc[h];
	return vertices[now].anc[0];
}

double ans(int a, int b)
{
	if (vertices[a].height < vertices[b].height)
		swap(a, b);
	if (is_anc(b, a))
	{
		double res = vertices[a].height - vertices[b].height;
		res += (double) vertices[a].sum / vertices[a].size - vertices[a].height;
		for (int h = LOGN - 1; h >= 0; --h)
			if (vertices[vertices[a].anc[h]].height > vertices[b].height)
				a = vertices[a].anc[h];
		res += (double) vertices[a].up_sum / (vertices[0].size - vertices[a].size);
		return res;
	}
	int lca = get_lca(a, b);
	double res = vertices[a].height + vertices[b].height - 2 * vertices[lca].height + 1;
	res += (double) vertices[a].sum / vertices[a].size - vertices[a].height;
	res += (double) vertices[b].sum / vertices[b].size - vertices[b].height;
	return res;
}

void solve()
{
	cin >> n >> m;
	for (int i = 1; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		--a, --b;
		vertices[a].edges.push_back(b);
		vertices[b].edges.push_back(a);
	}
	dfs(0);
	dfs2(0, 0);
	cout << setprecision(9) << fixed;
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		--a, --b;
		cout << ans(a, b) << '\n';
	}
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0), cin.tie(0);

	solve();

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3f", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}