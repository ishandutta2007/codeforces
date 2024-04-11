#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int psum[505];
int dat[505];
int after[505];

bool dp[505][505];
bool visit[505][505];
int tree[506];

int parent[505];
vector<pair<int, char>> mergelist;

// Returns the sum from index 1 to p, inclusive
int query(int p) {
	int ret = 0;
	for (; p > 0; p -= p & -p) ret += tree[p];
	return ret;
}

// Adds val to element with index pos
void add(int p, int val) {
for (; p <= 500; p += p & -p) tree[p] += val;
}

int getparent(int n)
{
	return n == parent[n] ? n : parent[n] = getparent(parent[n]);
}

// merge b into a
void merge(int a, int b)
{
	int pa = getparent(a);
	int pb = getparent(b);

	if (a > b)
	{
		mergelist.emplace_back(pa - query(pa), 'L');
	}
	else
	{
		mergelist.emplace_back(pa - query(pa), 'R');
	}

	add(max(pa, pb), 1);

	if (pa < pb) swap(pa, pb);
	parent[pa] = pb;
}

bool D(int a, int b)
{
	if (a == b) return true;

	if (visit[a][b] == false)
	{
		visit[a][b] = true;
		dp[a][b] = false;

		for (int k = a; k < b; k++)
		{
			if (D(a, k) == false || D(k + 1, b) == false) continue;
			if (psum[k] - psum[a - 1] != psum[b] - psum[k])
			{
				return dp[a][b] = true;
			}
		}
	}

	return dp[a][b];
}

void E(int a, int b)
{
	if (a == b) return;

	for (int k = a; k < b; k++)
	{
		if (D(a, k) == false || D(k + 1, b) == false) continue;
		int s1 = psum[k] - psum[a - 1];
		int s2 = psum[b] - psum[k];
		if (s1 == s2) continue;

		E(a, k); E(k + 1, b);

		if (s1 > s2)
		{
			merge(a, b);
		}
		else
		{
			merge(b, a);
		}

		return;
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &dat[i]);
		psum[i] = psum[i - 1] + dat[i];
		parent[i] = i;
	}

	int k;
	scanf("%d", &k);
	for (int i = 1; i <= k; i++)
	{
		scanf("%d", &after[i]);
	}

	int pa = 1, pb = 1, sumnow = 0, last = 1;

	vector<pair<int, int>> intervals;

	while (pa <= n && pb <= k)
	{
		sumnow += dat[pa];
		if (sumnow > after[pb])
		{
			printf("NO");
			return 0;
		}
		else if (sumnow == after[pb])
		{
			sumnow = 0;
			// last ~ pa 
			if (D(last, pa) == false)
			{
				printf("NO");
				return 0;
			}
			intervals.emplace_back(last, pa);
			last = pa + 1;
			pb++;
		}

		pa++;
	}

	if (pa <= n || pb <= k)
	{
		printf("NO");
		return 0;
	}

	for (auto &&e : intervals) E(e.first, e.second);
	printf("YES\n");
	for (auto &&e : mergelist) printf("%d %c\n", e.first, e.second);
}