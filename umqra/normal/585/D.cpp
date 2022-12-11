#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <sstream>
#include <fstream>
#include <functional>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = (int)2e6 + 10;
string REPR[] = {"MW", "LW", "LM"};

struct Triple
{
	int a, b, c;
	int mask;
	Triple () : a(), b(), c(), mask() {}
	Triple (int _a, int _b, int _c, int _mask) : a(_a), b(_b), c(_c), mask(_mask) {}
	Triple add(int x, int y, int z)
	{
		return Triple(a + x, b + y, c + z, mask);
	}
	Triple addMask(int t)
	{
		return Triple(a, b, c, mask * 3 + t);
	}
};

map <pii, pii> secondPart;
Triple firstPart[N];
int cntF = 0;

vector <string> getMask(int mask, int len)
{
	vector <string> res = vector<string>();
	for (int i = 0; i < len; i++)
	{
		int t = (mask % 3);
		mask /= 3;
		res.push_back(REPR[t]);
	}
	reverse(res.begin(), res.end());
	return res;
}

int d[100][3];
int mode = 0;
void brute(int l, int r, Triple cur)
{
	if (l == r)
	{
		if (mode == 0)
			firstPart[cntF++] = cur;
		else
		{
			pii t = mp(cur.b - cur.a, cur.c - cur.b);
			if (secondPart.count(t) == 0)
				secondPart[t] = mp(cur.a, cur.mask);
			else
				secondPart[t] = max(secondPart[t], mp(cur.a, cur.mask));
		}
		return;
	}
	Triple nw = cur.add(d[l][0], d[l][1], d[l][2]);
	int a[3] = {0, 0, 0};
	for (int i = 0; i < 3; i++)
	{
		a[i] = d[l][i];
		brute(l + 1, r, nw.add(-a[0], -a[1], -a[2]).addMask(i));
		a[i] = 0;
	}
}

int fLen, sLen;
void printAnswer(int a, int b)
{
	vector <string> f = getMask(a, fLen);
	vector <string> s = getMask(b, sLen);
	for (string x : f)
		cout << x << endl;
	for (string x : s)
		cout << x << endl;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d%d", &d[i][0], &d[i][1], &d[i][2]);

	fLen = (n + 1) / 2;
	sLen = n - fLen;
	brute(0, fLen, Triple());

	mode = 1;
	brute(fLen, n, Triple());
	
	int bestSum = -(int)1e9;
	int m1 = -1, m2 = -1;
	for (int i = 0; i < cntF; i++)
	{
		pii t = mp(firstPart[i].a - firstPart[i].b, firstPart[i].b - firstPart[i].c);
		if (secondPart.count(t) != 0)
		{
			pii value = secondPart[t];
			int curValue = firstPart[i].a + value.X;
			if (bestSum < curValue)
			{
				bestSum = curValue;
				m1 = firstPart[i].mask;
				m2 = value.Y;
			}
		}
	}
	if (m1 != -1)
		printAnswer(m1, m2);
	else
		puts("Impossible");

	return 0;
}