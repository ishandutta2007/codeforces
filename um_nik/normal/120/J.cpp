#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

const int N = 100100;
const int MOD = 100069;

double sqr(double x)
{
	return x * x;
}

struct Point
{
	int x, y;
	int mask;
	int idx;

	Point() : x(), y(), mask(), idx() {}

	void scan(int _idx)
	{
		idx = _idx;
		scanf("%d%d", &x, &y);
		mask = 0;
		if (x < 0)
		{
			x *= -1;
			mask ^= 1;
		}
		if (y < 0)
		{
			y *= -1;
			mask ^= 2;
		}
	}

	double distTo(Point a)
	{
		return sqrt(sqr(x - a.x) + sqr(y - a.y));
	}
};

struct HashTable
{
	vector<int> a[N];

	HashTable() : a() {}

	void set(int hash, int val)
	{
		a[hash].push_back(val);
	}

	vector<int> get(int hash)
	{
		return a[hash];
	}
};

int n;
Point a[N];
double d;
HashTable H;
int ans1, ans2;

int getHash(int x, int y)
{
	return (x ^ (y << 14)) % MOD;
}

void getXY(Point A, int &x, int &y)
{
	x = (int)(A.x / d);
	y = (int)(A.y / d);
}

void reBuild(double nd, int m)
{
	for (int i = 0; i < m; i++)
	{
		int x, y;
		getXY(a[i], x, y);
		int hash = getHash(x, y);
		H.a[hash].clear();
	}
	d = nd;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		getXY(a[i], x, y);
		int hash = getHash(x, y);
		H.set(hash, i);
	}
	return;
}

void printAns()
{
	int m1 = a[ans1].mask;
	int m2 = a[ans2].mask;
	m2 ^= 3;
	m1++;
	m2++;
	ans1 = a[ans1].idx;
	ans2 = a[ans2].idx;
	printf("%d %d %d %d\n", ans1, m1, ans2, m2);
	return;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		a[i].scan(i + 1);
//	random_shuffle(a, a + n);
	d = a[0].distTo(a[1]);
	ans1 = 0, ans2 = 1;
	reBuild(d, 2);
	for (int i = 2; i < n; i++)
	{
//		cerr << i << endl;
		int x, y;
		getXY(a[i], x, y);
		double nd = d;
		int nb = -1;
		for (int dx = -1; dx <= 1; dx++)
			for (int dy = -1; dy <= 1; dy++)
			{
//				cerr << dx << " " << dy << endl;
				int nx = x + dx, ny = y + dy;
				if (nx < 0 || ny < 0) continue;
				int hash = getHash(nx, ny);
				vector<int> tmp = H.get(hash);
				for (int j = 0; j < (int)tmp.size(); j++)
				{
					Point P = a[tmp[j]];
					double dist = P.distTo(a[i]);
					if (dist < nd)
					{
						nd = dist;
						nb = tmp[j];
					}
				}
			}
		if (nd == 0)
		{
			ans1 = nb;
			ans2 = i;
			break;
		}
		int hash = getHash(x, y);
		H.set(hash, i);
		if (nb != -1)
		{
			reBuild(nd, i + 1);
			ans1 = nb;
			ans2 = i;
		}
	}
	printAns();

	return 0;
}