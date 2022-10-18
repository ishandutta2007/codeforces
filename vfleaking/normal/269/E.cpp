#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <exception>
#include <stdexcept>
using namespace std;

const int MaxN = 100000;

class no_solution_error : public exception {};

struct rectstr
{
	int tp1, tp2;
	int p1, p2;

	inline pair<int, int> tp()
	{
		return make_pair(tp1, tp2);
	}
};

int n, m;
rectstr a[MaxN * 2];
int perR[MaxN + 1], perC[MaxN + 1];

int cptotp(char cp)
{
	switch (cp)
	{
		case 'L':
			return 0;
		case 'T':
			return 1;
		case 'R':
			return 2;
		case 'B':
			return 3;
		default:
			return -1;
	}
}

int tpptov(int tp, int p)
{
	switch (tp)
	{
		case 0:
			return p - 1;
		case 1:
			return n + p - 1;
		case 2:
			return n + m + p - 1;
		case 3:
			return n + m + n + p - 1;
		default:
			return -1;
	}
}

inline int rectstrv1(const rectstr &r)
{
	return tpptov(r.tp1, r.p1);
}
inline int rectstrv2(const rectstr &r)
{
	return tpptov(r.tp2, r.p2);
}
inline int rectstrv(const rectstr &r, int c)
{
	if (c == 1)
		return rectstrv1(r);
	else
		return rectstrv2(r);
}
inline int rectstrc(const rectstr &r, int v)
{
	if (rectstrv1(r) == v)
		return 1;
	else
		return 2;
}
inline int rectstrbro(const rectstr &r, int v)
{
	if (rectstrv1(r) != v)
		return rectstrv1(r);
	else
		return rectstrv2(r);
}
inline int rectoppov(int v)
{
	if (v < n + m)
		return v + n + m;
	else
		return v - n - m;
}

inline void solensure(bool b)
{
	if (!b)
		throw no_solution_error();
}

void handle()
{
	solensure(m >= n);

	int cntT[4][4] = {};
	for (int i = 0; i < n + m; i++)
		cntT[a[i].tp1][a[i].tp2]++;
	solensure(cntT[0][1] == cntT[2][3]);
	solensure(cntT[0][3] == cntT[1][2]);

	int lA = cntT[0][1];
	int lB = cntT[0][3];
	int lD = lB - lA;

	int stdcir_n = 0;
	static pair<int, int> stdcirtp[MaxN * 4];
	static int stdnext[MaxN * 4];

	if (m > min(lA, lB) * 2)
	{
		int tp = 1;
		int p = min(lA, lB) + 1;
		do
		{
			if (tp == 0)
			{
				if (p <= lA)
				{
					stdcirtp[stdcir_n++] = make_pair(0, 1);
					tp = 1;
				}
				else
				{
					stdcirtp[stdcir_n++] = make_pair(0, 3);
					p = n + 1 - p;
					tp = 3;
				}
			}
			else if (tp == 1)
			{
				if (p <= lA)
				{
					stdcirtp[stdcir_n++] = make_pair(0, 1);
					tp = 0;
				}
				else if (p <= m - lB)
				{
					stdcirtp[stdcir_n++] = make_pair(1, 3);
					p += lD;
					tp = 3;
				}
				else
				{
					stdcirtp[stdcir_n++] = make_pair(1, 2);
					p = m + 1 - p;
					tp = 2;
				}
			}
			else if (tp == 2)
			{
				if (p <= lB)
				{
					stdcirtp[stdcir_n++] = make_pair(1, 2);
					p = m + 1 - p;
					tp = 1;
				}
				else
				{
					stdcirtp[stdcir_n++] = make_pair(2, 3);
					p = p - n + m;
					tp = 3;
				}
			}
			else if (tp == 3)
			{
				if (p <= lB)
				{
					stdcirtp[stdcir_n++] = make_pair(0, 3);
					p = n + 1 - p;
					tp = 0;
				}
				else if (p <= m - lA)
				{
					stdcirtp[stdcir_n++] = make_pair(1, 3);
					p -= lD;
					tp = 1;
				}
				else
				{
					stdcirtp[stdcir_n++] = make_pair(2, 3);
					p = p - m + n;
					tp = 2;
				}
			}

			tp = (tp + 2) % 4;
		}
		while (!(tp == 1 && p == min(lA, lB) + 1));

		stdnext[0] = -1;
		for (int i = 1, j = -1; i < stdcir_n; i++)
		{
			while (j >= 0 && stdcirtp[i] != stdcirtp[j + 1])
				j = stdnext[j];
			if (stdcirtp[i] == stdcirtp[j + 1])
				j++;
			stdnext[i] = j;
		}
	}

	static int bel[MaxN * 4];
	for (int i = 0; i < n + m; i++)
	{
		bel[rectstrv1(a[i])] = i;
		bel[rectstrv2(a[i])] = i;
	}

	int nCorner = 0;
	int nMid = 0;
	static bool book[MaxN * 4];
	for (int st = 0; st < n + m; st++)
		if (!book[st])
		{
			int cir_n = 0;
			static int cir[MaxN * 4];

			int stV;
			if (a[st].tp() == make_pair(0, 1))
				stV = rectstrv2(a[st]);
			else if (a[st].tp() == make_pair(1, 2))
				stV = rectstrv1(a[st]);
			else if (a[st].tp() == make_pair(1, 3))
				stV = rectstrv1(a[st]);
			else
				continue;

			int curV = stV;
			int curI = st;
			while (true)
			{
				book[curI] = true;
				cir[cir_n++] = curI;
				curV = rectoppov(rectstrbro(a[curI], curV));
				curI = bel[curV];

				if (book[curI])
				{
					solensure(curV == stV);
					break;
				}
			}

			int fstC;
			if (cir_n == 4 && a[cir[0]].tp() == make_pair(1, 2) && a[cir[1]].tp() == make_pair(0, 1)
					&& a[cir[2]].tp() == make_pair(0, 3) && a[cir[3]].tp() == make_pair(2, 3))
			{
				solensure(!perC[a[cir[0]].p1]);
				nCorner++;
				perC[a[cir[0]].p1] = m + 1 - nCorner;
				fstC = 1;
			}
			else if (cir_n == 4 && a[cir[0]].tp() == make_pair(0, 1) && a[cir[1]].tp() == make_pair(1, 2)
					&& a[cir[2]].tp() == make_pair(2, 3) && a[cir[3]].tp() == make_pair(0, 3))
			{
				solensure(!perC[a[cir[0]].p2]);
				nCorner++;
				perC[a[cir[0]].p2] = nCorner;
				fstC = 2;
			}
			else
			{
				solensure(cir_n == stdcir_n);

				int sj = -1;
				for (int i = 0, j = -1; i < cir_n * 2; i++)
				{
					while (j >= 0 && a[cir[i % cir_n]].tp() != stdcirtp[j + 1])
						j = stdnext[j];
					if (a[cir[i % cir_n]].tp() == stdcirtp[j + 1])
						j++;
					if (j == stdcir_n - 1)
					{
						sj = i - stdcir_n + 1;
						break;
					}
				}
				solensure(sj != -1);
				rotate(cir, cir + sj, cir + cir_n);

				if (a[cir[0]].tp() == make_pair(0, 1))
				{
					solensure(!perC[a[cir[0]].p2]);
					nMid++;
					perC[a[cir[0]].p2] = min(lA, lB) + nMid;
					fstC = 2;
				}
				else
				{
					solensure(!perC[a[cir[0]].p1]);
					nMid++;
					perC[a[cir[0]].p1] = min(lA, lB) + nMid;
					fstC = 1;
				}
			}

			for (int i = 0, c = fstC; i + 1 < cir_n; c = rectstrc(a[cir[i + 1]], rectoppov(rectstrv(a[cir[i]], 3 - c))), i++)
			{
				if (a[cir[i]].tp() == make_pair(0, 1))
				{
					if (c == 1)
						perC[a[cir[i]].p2] = perR[a[cir[i]].p1];
					else
						perR[a[cir[i]].p1] = perC[a[cir[i]].p2];
				}
				else if (a[cir[i]].tp() == make_pair(0, 3))
				{
					if (c == 1)
						perC[a[cir[i]].p2] = n + 1 - perR[a[cir[i]].p1];
					else
						perR[a[cir[i]].p1] = n + 1 - perC[a[cir[i]].p2];
				}
				else if (a[cir[i]].tp() == make_pair(1, 2))
				{
					if (c == 1)
						perR[a[cir[i]].p2] = m + 1 - perC[a[cir[i]].p1];
					else
						perC[a[cir[i]].p1] = m + 1 - perR[a[cir[i]].p2];
				}
				else if (a[cir[i]].tp() == make_pair(1, 3))
				{
					if (c == 1)
						perC[a[cir[i]].p2] = perC[a[cir[i]].p1] + lD;
					else
						perC[a[cir[i]].p1] = perC[a[cir[i]].p2] - lD;
				}
				else if (a[cir[i]].tp() == make_pair(2, 3))
				{
					if (c == 1)
						perC[a[cir[i]].p2] = perR[a[cir[i]].p1] + m - n;
					else
						perR[a[cir[i]].p1] = perC[a[cir[i]].p2] - m + n;
				}
			}
		}
}

int main()
{
	try
	{
		cin >> n >> m;

		bool hasV = false, hasH = false;
		for (int i = 0; i < n + m; i++)
		{
			char cp1, cp2;
			int p1, p2;
			scanf(" %c %c %d %d", &cp1, &cp2, &p1, &p2);

			a[i].tp1 = cptotp(cp1);
			a[i].tp2 = cptotp(cp2);
			a[i].p1 = p1;
			a[i].p2 = p2;

			if (a[i].tp1 > a[i].tp2)
				swap(a[i].tp1, a[i].tp2), swap(a[i].p1, a[i].p2);

			if (a[i].tp() == make_pair(0, 2))
				hasH = true;
			if (a[i].tp() == make_pair(1, 3))
				hasV = true;
		}
		if (hasH && hasV)
			throw no_solution_error();

		if (hasH)
		{
			for (int i = 0; i < n + m; i++)
			{
				a[i].tp1 ^= 1;
				a[i].tp2 ^= 1;

				if (a[i].tp1 > a[i].tp2)
					swap(a[i].tp1, a[i].tp2), swap(a[i].p1, a[i].p2);
			}
			swap(n, m);
		}

		handle();

		static int pos[MaxN + 1];
		for (int i = 1; i <= n; i++)
			pos[perR[i]] = i;
		for (int i = 1; i <= n; i++)
			perR[i] = pos[i];
		for (int i = 1; i <= m; i++)
			pos[perC[i]] = i;
		for (int i = 1; i <= m; i++)
			perC[i] = pos[i];

		if (!hasH)
		{
			for (int i = 1; i <= n; i++)
				printf("%d ", perR[i]);
			printf("\n");
			for (int i = 1; i <= m; i++)
				printf("%d ", perC[i]);
			printf("\n");
		}
		else
		{
			for (int i = 1; i <= m; i++)
				printf("%d ", perC[i]);
			printf("\n");
			for (int i = 1; i <= n; i++)
				printf("%d ", perR[i]);
			printf("\n");
		}
	}
	catch (no_solution_error &e)
	{
		cout << "No solution" << endl;
	}

	return 0;
}