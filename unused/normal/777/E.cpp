#include <bits/stdc++.h>
using namespace std;

struct ring
{
	int a, b, h;
	bool operator<(const ring &rhs) const
	{
		if (b != rhs.b) return b > rhs.b;
		return a > rhs.a;
	}
};

ring dat[100005];

vector<int> coord;

constexpr int TSIZE = 262144;
long long tree[TSIZE * 2 + 1];

long long query(int l, int r)
{
	l += TSIZE; r += TSIZE;
	long long ret = 0;
	while (l <= r)
	{
		if (l & 1) ret = max(tree[l], ret), l++;
		if (!(r & 1)) ret = max(tree[r], ret), r--;
		l >>= 1; r >>= 1;
	}
	return ret;
}

void update(int pos, long long val)
{
	for (pos += TSIZE; pos; pos >>= 1) tree[pos] = max(val, tree[pos]);
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d", &dat[i].a, &dat[i].b, &dat[i].h);
		coord.push_back(dat[i].a);
		coord.push_back(dat[i].b);
	}
	sort(coord.begin(), coord.end());
	coord.erase(unique(coord.begin(), coord.end()), coord.end());

	for (int i = 0; i < n; i++)
	{
		dat[i].a = lower_bound(coord.begin(), coord.end(), dat[i].a) - coord.begin();
		dat[i].b = lower_bound(coord.begin(), coord.end(), dat[i].b) - coord.begin();
	}

	sort(dat, dat + n);

	for (int i = 0; i < n; i++)
	{
		update(dat[i].a, dat[i].h + query(0, dat[i].b - 1));
	}

	printf("%lld\n", tree[1]);
}