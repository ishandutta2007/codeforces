#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef long long s64;

const s64 INF = 1000000000000000000ll;

const int MaxN = 50000;

template <class T>
inline void tension(T &a, const T &b)
{
	if (b < a)
		a = b;
}

struct task
{
	int id;
	int t;
	int rest, p;

	friend inline bool operator<(const task &lhs, const task &rhs)
	{
		return lhs.p < rhs.p;
	}
};

inline bool cmpByT(const task &lhs, const task &rhs)
{
	return lhs.t < rhs.t;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	static task a[MaxN + 1];

	int sp;

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d %d", &a[i].t, &a[i].rest, &a[i].p);
		a[i].id = i;
	}

	sort(a + 1, a + n + 1, cmpByT);

	s64 spET;
	cin >> spET;

	for (int i = 1; i <= n; i++)
		if (a[i].p == -1)
			sp = i;

	static s64 et[MaxN + 1];
	priority_queue<task> q;
	for (int i = 1; i < sp; i++)
	{
		q.push(a[i]);
		s64 curT = a[i].t;
		while (!q.empty() && curT < a[i + 1].t)
		{
			task cur = q.top();
			q.pop();
			int delta = min((s64)cur.rest, a[i + 1].t - curT);
			cur.rest -= delta;
			curT += delta;
			if (cur.rest > 0)
				q.push(cur);
		}
	}

	vector<pair<int, int> > seg;
	for (int i = 1; i <= n; i++)
		if (i != sp)
			seg.push_back(make_pair(a[i].p, 0));
	for (int i = sp; i <= n && a[i].t < spET; i++)
	{
		if (i != sp)
			q.push(a[i]);
		s64 curT = a[i].t;
		s64 deadT = spET;
		if (i < n)
			tension(deadT, (s64)a[i + 1].t);
		while (!q.empty() && curT < deadT)
		{
			task cur = q.top();
			q.pop();
			int delta = min((s64)cur.rest, deadT - curT);
			seg.push_back(make_pair(cur.p, delta));
			cur.rest -= delta;
			curT += delta;
			if (cur.rest > 0)
				q.push(cur);
		}
		if (curT < deadT)
			seg.push_back(make_pair(0, (int)(deadT - curT)));
	}

	sort(seg.begin(), seg.end());

	int seg_new_n = 0;
	for (int i = 0, j = 0; i < (int)seg.size(); i = j)
	{
		while (j < (int)seg.size() && seg[i].first == seg[j].first)
			j++;
		for (int k = i + 1; k < j; k++)
			seg[i].second += seg[k].second;
		seg[seg_new_n++] = seg[i];
	}
	seg.resize(seg_new_n);

	s64 spRest = a[sp].rest;
	int spPI = 0;
	while (spPI < (int)seg.size() && spRest > 0)
	{
		spRest -= seg[spPI].second;
		spPI++;
	}
	a[sp].p = seg[spPI - 1].first + 1;
	while (spPI < (int)seg.size() && a[sp].p == seg[spPI].first)
		a[sp].p++, spPI++;

	cout << a[sp].p << endl;

	while (!q.empty())
		q.pop();
	for (int i = 1; i <= n; i++)
	{
		q.push(a[i]);
		s64 curT = a[i].t;
		s64 deadT = i < n ? a[i + 1].t : INF;
		while (!q.empty() && curT < deadT)
		{
			task cur = q.top();
			q.pop();
			int delta = min((s64)cur.rest, deadT - curT);
			cur.rest -= delta;
			curT += delta;
			if (cur.rest > 0)
				q.push(cur);
			else
				et[cur.id] = curT;
		}
	}

	for (int i = 1; i <= n; i++)
		cout << et[i] << " ";
	cout << endl;

	return 0;
}