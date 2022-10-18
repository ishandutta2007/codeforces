#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long s64;

const int MaxB = 100000;

const int MaxN = 100000;
const int MaxW = 100000;

template <class T>
inline void relax(T &a, const T &b)
{
	if (b > a)
		a = b;
}

const int MaxBloN = 317;
const int MaxNBlo = 317;

struct Block
{
	int n;
	int a[MaxBloN];
	int r[MaxBloN];
	int sh;
	bool avai[MaxBloN];

	int q_n;
	int q[MaxBloN];

	bool isCon(int i, int j, int k)
	{
		return ((s64)r[j] * a[j] - (s64)r[i] * a[i]) * (a[j] - a[k]) > ((s64)r[k] * a[k] - (s64)r[j] * a[j]) * (a[i] - a[j]);
	}
	
	pair<s64, int> getVal(int i)
	{
		return make_pair((s64)(r[i] + sh) * a[i], a[i]);
	}

	void build()
	{
		for (int i = 0, curR = 0; i < n; i++)
			if (avai[i])
				r[i] = ++curR;

		q_n = 0;
		for (int i = 0; i < n; i++)
			if (avai[i])
			{
				while (q_n >= 2 && !isCon(q[q_n - 2], q[q_n - 1], i))
					q_n--;
				q[q_n++] = i;
			}
		while (q_n >= 2 && getVal(q[q_n - 2]) >= getVal(q[q_n - 1]))
			q_n--;
	}
	void shift()
	{
		sh++;
		while (q_n >= 2 && getVal(q[q_n - 2]) >= getVal(q[q_n - 1]))
			q_n--;
	}
	void setAvai(int p)
	{
		avai[p] = true;
		build();
	}
	pair<s64, int> getMax()
	{
		if (q_n > 0)
			return getVal(q[q_n - 1]);
		else
			return make_pair(0ll, 0);
	}
};

int main()
{
	int n, w;
	int maxB = 0;
	static pair<int, int> ap[MaxN];
	static vector<int> botB[MaxB + 2];

	cin >> n >> w;
	for (int i = 0; i < n; i++)
		scanf("%d %d", &ap[i].first, &ap[i].second);
	sort(ap, ap + n, greater< pair<int, int> >());

	for (int i = 0; i < n; i++)
		botB[ap[i].second].push_back(i), relax(maxB, ap[i].second);

	int bloN = (int)ceil(sqrt(n));
	int nBlo = (n + bloN - 1) / bloN;
	static Block blo[MaxNBlo];

	for (int i = 0; i < n; i++)
		blo[i / bloN].a[blo[i / bloN].n++] = ap[i].first;
	for (int i = 0; i < nBlo; i++)
		blo[i].build();

	int nF = n;
	for (int cb = 0; cb <= maxB + 1; cb++)
	{
		pair<s64, int> res(0, 0);
		for (int i = 0; i < nBlo; i++)
			relax(res, blo[i].getMax());
		res.first += (s64)nF * cb * w;
		cout << res.first << " " << res.second << endl;

		for (vector<int>::iterator it = botB[cb].begin(); it != botB[cb].end(); it++)
		{
			int p = *it;
			blo[p / bloN].setAvai(p % bloN);
			for (int i = p / bloN + 1; i < nBlo; i++)
				blo[i].shift();
			nF--;
		}
	}

	return 0;
}