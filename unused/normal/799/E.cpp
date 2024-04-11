#include <bits/stdc++.h>
using namespace std;

int c[200005];
int flag[200005];

vector<int> coord;
vector<int> A, B, AB, X;

constexpr int TSIZE = 262144;
pair<long long, int> tree[TSIZE * 2];
constexpr long long INF = 1e18;

void add(int pos)
{
	tree[pos + TSIZE].second++;
	tree[pos + TSIZE].first += coord[pos];

	for (pos += TSIZE; pos >>= 1;)
	{
		tree[pos].first = tree[pos << 1].first + tree[pos << 1 | 1].first;
		tree[pos].second = tree[pos << 1].second + tree[pos << 1 | 1].second;
	}
}

void sub(int pos)
{
	tree[pos + TSIZE].second--;
	tree[pos + TSIZE].first -= coord[pos];

	for (pos += TSIZE; pos >>= 1;)
	{
		tree[pos].first = tree[pos << 1].first + tree[pos << 1 | 1].first;
		tree[pos].second = tree[pos << 1].second + tree[pos << 1 | 1].second;
	}
}

long long query(int total)
{
	if (total == 0) return 0;
	if (tree[1].second < total) return INF;

	int node = 1;
	long long ret = 0;
	while (node < TSIZE)
	{
		if (tree[node << 1].second >= total)
		{
			node = node << 1;
		}
		else
		{
			total -= tree[node << 1].second;
			ret += tree[node << 1].first;
			node = node << 1 | 1;
		}
	}
	return ret + total * coord[node - TSIZE];
}

int crd(int t)
{
	return lower_bound(coord.begin(), coord.end(), t) - coord.begin();
}

int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n;i++) scanf("%d", &c[i]);
	int a; scanf("%d", &a); for (int i = 0; i < a; i++) { int t; scanf("%d", &t); flag[t] |= 1; }
	int b; scanf("%d", &b); for (int i = 0; i < b; i++) { int t; scanf("%d", &t); flag[t] |= 2; }

	coord = { c + 1,c + 1 + n };
	sort(coord.begin(), coord.end());
	coord.erase(unique(coord.begin(), coord.end()), coord.end());

	for (int i = 1; i <= n; i++)
	{
		if (flag[i] == 0) X.push_back(c[i]);
		if (flag[i] == 1) A.push_back(c[i]);
		if (flag[i] == 2) B.push_back(c[i]);
		if (flag[i] == 3) AB.push_back(c[i]);
	}

	sort(X.begin(), X.end());
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	sort(AB.begin(), AB.end());
	if (AB.size() > m) AB.resize(m);

	for (int t : X) add(crd(t));
	for (int t : A) add(crd(t));
	for (int t : B) add(crd(t));

	long long ans = INF;
	long long base = accumulate(AB.begin(), AB.end(), 0LL);
	AB.push_back(0);
	int last = 0;

	for (int i = AB.size() - 1; i >= 0; i--)
	{
		base -= AB[i];

		int sub = max(0, k - i);
		int x = m - i - 2 * sub;
		if (x < 0) break;

		while (last < sub)
		{
			if (last == A.size() || last == B.size()) goto outloop;
			base += A[last] + B[last];
			::sub(crd(A[last]));
			::sub(crd(B[last]));
			++last;
		}

		ans = min(ans, base + query(x));
	}

outloop:

	if (ans == INF) printf("-1\n");
	else printf("%lld\n", ans);
}