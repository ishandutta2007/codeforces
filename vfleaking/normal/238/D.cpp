#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <locale>
#include <cassert>
#include <climits>
using namespace std;

const int MaxD = 10;
const int MaxN = 100000;

template <class T>
inline void tension(T &a, const T &b)
{
	if (b < a)
		a = b;
}

inline int getint()
{
	char c;
	while (c = getchar(), !isdigit(c));
	
	int res = c - '0';
	while (c = getchar(), isdigit(c))
		res = res * 10 + c - '0';
	return res;
}

inline bool isdir(char c)
{
	return c == '<' || c == '>';
}

int n, q;

int book[1 + MaxN + 1];
int fstCnt[1 + MaxN + 1][MaxD];
int sndCnt[1 + MaxN + 1][MaxD];
int curCnt[MaxD];
int next[1 + MaxN + 1], prev[1 + MaxN + 1];
char pro[1 + MaxN + 1];

void pro_del(int p)
{
	next[prev[p]] = next[p];
	prev[next[p]] = prev[p];
}

void run(int p)
{
	char last = '?';
	int lp;
	char d = '>';
	while (p != 0 && p != n + 1)
	{
		if (book[p] == 0)
		{
			copy(curCnt, curCnt + MaxD, fstCnt[p]);
			book[p] = 1;
		}

		if (isdigit(pro[p]))
		{
			last = pro[p];
			lp = p;

			curCnt[pro[p] - '0']++;
			if (pro[p] == '0')
			{
				if (book[p] == 2)
					pro_del(p);
				else
					pro[p] = 'X';
			}
			else
				pro[p]--;
		}
		else if (isdir(pro[p]))
		{
			d = pro[p];
			if (isdir(last))
			{
				if (book[lp] == 2)
					pro_del(lp);
				else
					pro[lp] = 'X';
			}

			last = pro[p];
			lp = p;
		}

		if (d == '<' && book[p] == 1)
		{
			book[p] = 2;
			copy(curCnt, curCnt + MaxD, sndCnt[p]);

			if (pro[p] == 'X')
				pro_del(p);
		}

		if (d == '>')
			p = next[p];
		else
			p = prev[p];
	}
}

int main()
{
	cin >> n >> q;
	scanf("%s", pro + 1);

	for (int i = 0; i <= n + 1; i++)
		prev[i] = i - 1, next[i] = i + 1;

	while (next[0] != n + 1)
	{
		run(next[0]);
		while (next[0] != n + 1 && book[next[0]])
			pro_del(next[0]);
	}
	copy(curCnt, curCnt + MaxD, fstCnt[n + 1]);
	
	while (q--)
	{
		int l = getint(), r = getint();
		int leave[MaxD];
		copy(fstCnt[r + 1], fstCnt[r + 1] + MaxD, leave);
		if (book[l] == 2)
			for (int i = 0; i < MaxD; i++)
				tension(leave[i], sndCnt[l][i]);
		for (int i = 0; i < MaxD; i++)
			printf("%d ", leave[i] - fstCnt[l][i]);
		printf("\n");
	}
	
	return 0;
}