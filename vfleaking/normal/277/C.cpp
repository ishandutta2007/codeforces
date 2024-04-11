#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MaxNCut = 100000;

// adjust
template <class T>
inline bool relax(T &a, const T &b)
{
	if (b > a)
	{
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool tension(T &a, const T &b)
{
	if (b < a)
	{
		a = b;
		return true;
	}
	return false;
}

struct cut
{
	int le, ri;
	int pos;

	cut(){}
	cut(const int &_le, const int &_ri, const int &_pos)
		: le(_le), ri(_ri), pos(_pos){}

	friend inline bool operator<(const cut &lhs, const cut &rhs)
	{
		if (lhs.pos != rhs.pos)
			return lhs.pos < rhs.pos;
		return lhs.le < rhs.le;
	}
};

int main()
{
	int n, m, nCut;

	int nVert = 0;
	static cut vert[MaxNCut];  // vertical
	static int vertEm[MaxNCut];

	int nHori = 0;
	static cut hori[MaxNCut];  // horizontal
	static int horiEm[MaxNCut];
	
	cin >> n >> m >> nCut;
	for (int i = 0; i < nCut; i++)
	{
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		if (x1 == x2)
		{
			if (y1 > y2)
				swap(y1, y2);
			hori[nHori++] = cut(y1, y2, x1);
		}
		else // y1 == y2
		{
			if (x1 > x2)
				swap(x1, x2);
			vert[nVert++] = cut(x1, x2, y1);
		}
	}

	sort(vert, vert + nVert);
	sort(hori, hori + nHori);

	int sg = 0;
	int nEmVert = m - 1;
	int vertEmNum = 1;
	for (int i = 0, j = 0; i < nVert; i = j)
	{
		while (j < nVert && vert[i].pos == vert[j].pos)
			j++;

		if (vertEmNum == vert[i].pos)
			vertEmNum++;

		vertEm[i] = 0;
		int ri = 0;
		for (int k = i; k < j; k++)
		{
			if (vert[k].le > ri)
				vertEm[i] += vert[k].le - ri;
			relax(ri, vert[k].ri);
		}
		vertEm[i] += n - ri;

		nEmVert--;
		sg ^= vertEm[i];
	}
	if (nEmVert & 1)
		sg ^= n;

	int nEmHori = n - 1;
	int horiEmNum = 1;
	for (int i = 0, j = 0; i < nHori; i = j)
	{
		while (j < nHori && hori[i].pos == hori[j].pos)
			j++;

		if (horiEmNum == hori[i].pos)
			horiEmNum++;

		horiEm[i] = 0;
		int ri = 0;
		for (int k = i; k < j; k++)
		{
			if (hori[k].le > ri)
				horiEm[i] += hori[k].le - ri;
			relax(ri, hori[k].ri);
		}
		horiEm[i] += m - ri;

		nEmHori--;
		sg ^= horiEm[i];
	}
	if (nEmHori & 1)
		sg ^= m;

	if (sg == 0)
	{
		cout << "SECOND" << endl;
		return 0;
	}
	cout << "FIRST" << endl;

	for (int i = 0, j = 0; i < nVert; i = j)
	{
		while (j < nVert && vert[i].pos == vert[j].pos)
			j++;
		
		int t = vertEm[i] - (sg ^ vertEm[i]);
		if (t <= 0)
			continue;

		int cur = 0;
		int ri = 0;
		for (int k = i; k < j; k++)
		{
			if (vert[k].le > ri)
			{
				int delta = vert[k].le - ri;
				if (cur + delta >= t)
				{
					cout
						<< 0 << " " << vert[i].pos << " "
						<< ri + (t - cur) << " " << vert[i].pos << endl;
					return 0;
				}
				cur += vert[k].le - ri;
			}
			relax(ri, vert[k].ri);
		}

		cout
			<< 0 << " " << vert[i].pos << " "
			<< ri + (t - cur) << " " << vert[i].pos << endl;
		return 0;
	}
	if (nEmVert & 1)
	{
		int t = n - (sg ^ n);
		if (t > 0)
		{
			cout
				<< 0 << " " << vertEmNum << " "
				<< t << " " << vertEmNum << endl;
			return 0;
		}
	}

	for (int i = 0, j = 0; i < nHori; i = j)
	{
		while (j < nHori && hori[i].pos == hori[j].pos)
			j++;
		
		int t = horiEm[i] - (sg ^ horiEm[i]);
		if (t <= 0)
			continue;

		int cur = 0;
		int ri = 0;
		for (int k = i; k < j; k++)
		{
			if (hori[k].le > ri)
			{
				int delta = hori[k].le - ri;
				if (cur + delta >= t)
				{
					cout
						<< hori[i].pos << " " << 0 << " "
						<< hori[i].pos << " " << ri + (t - cur) << endl;
					return 0;
				}
				cur += hori[k].le - ri;
			}
			relax(ri, hori[k].ri);
		}
		cout
			<< hori[i].pos << " " << 0 << " "
			<< hori[i].pos << " " << ri + (t - cur) << endl;
		return 0;
	}
	if (nEmHori & 1)
	{
		int t = m - (sg ^ m);
		if (t > 0)
		{
			cout
				<< horiEmNum << " " << 0 << " "
				<< horiEmNum << " " << t << endl;
			return 0;
		}
	}

	return 0;
}