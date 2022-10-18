#include <iostream>
#include <cstdio>
#include <set>
#include <map>
using namespace std;

struct program
{
	int v, u;
	int l;

	program(){}
	program(const int &_v, const int &_u, const int &_l)
		: v(_v), u(_u), l(_l){}

	friend inline bool operator<(const program &lhs, const program &rhs)
	{
		if (lhs.l != rhs.l)
			return lhs.l > rhs.l;
		return lhs.v < rhs.v;
	}
};

int n;

inline program calcPro(const int &v, const int &u)
{
	if (v == 0 && u == n + 1)
		return program(0, n + 1, n);
	if (v == 0)
		return program(0, u, u - 1);
	if (u == n + 1)
		return program(v, n + 1, n - v);
	return program(v, u, (u - v) >> 1);
}

int main()
{
	int m;
	cin >> n >> m;

	set<int> pos;
	map<int, int> car;
	set<program> pro;

	pos.insert(0);
	pos.insert(n + 1);

	pro.insert(program(0, n + 1, n));

	while (m--)
	{
		int t, id;
		scanf("%d %d", &t, &id);

		if (t == 1)
		{
			program t = *pro.begin();
			pro.erase(pro.begin());

			int itsPos;
			if (t.v == 0 && t.u == n + 1)
				itsPos = 1;
			else if (t.v == 0)
				itsPos = 1;
			else if (t.u == n + 1)
				itsPos = n;
			else
				itsPos = (t.v + t.u) >> 1;

			pro.insert(calcPro(t.v, itsPos));
			pro.insert(calcPro(itsPos, t.u));

			car.insert(make_pair(id, itsPos));

			pos.insert(itsPos);

			printf("%d\n", itsPos);
		}
		else
		{
			int itsPos = car[id];
			car.erase(id);

			set<int>::iterator iter = pos.find(itsPos);
			set<int>::iterator prev = (--iter)++;
			set<int>::iterator next = (++iter)--;

			pro.erase(calcPro(*prev, *iter));
			pro.erase(calcPro(*iter, *next));
			pro.insert(calcPro(*prev, *next));

			pos.erase(iter);
		}
	}

	return 0;
}