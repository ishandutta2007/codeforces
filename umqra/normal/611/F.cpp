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

const int C = (int)1e6 + 10;
const int N = (int)2e6 + 10;
const int INF = (int)1e9 + 10;
const int mod = (int)1e9 + 7;

char str[N];

int add(int a, int b)
{
	a += b;
	if (a < 0)
		return a + mod;
	if (a < mod)
		return a;
	return a - mod;
}

int mult(int a, int b)
{
	return (1LL * a * b) % mod;
}

vector <int> posHor[N], posVer[N];
int sizeVer[N], sizeHor[N];
int hor[N], ver[N];
int sumHor[N], sumVer[N];

int getTimeHor(int it, int s)
{
	s += (it > 0 ? sumHor[it - 1] : 0);
	s += C;
	if (s < 0 || s >= N)
		return INF;
	if (posHor[s].size() == 0)
		return INF;
	return *lower_bound(posHor[s].begin(), posHor[s].end(), it);		
}

int getTimeVer(int it, int s)
{
	s += (it > 0 ? sumVer[it - 1] : 0);
	s += C;
	if (s < 0 || s >= N)
		return INF;
	if (posVer[s].size() == 0)
		return INF;
	return *lower_bound(posVer[s].begin(), posVer[s].end(), it);
}

int main()
{
	int n, h, w;
	scanf("%d%d%d", &n, &h, &w);
	scanf(" %s", str);
	for (int i = 0; i < n; i++)
		str[i + n] = str[i];
	n *= 2;
	int len = n / 2;
	for (int i = 0; i < n; i++)
	{
		if (str[i] == 'R' || str[i] == 'L')
		{
			hor[i] = (str[i] == 'R' ? 1 : -1);
			ver[i] = 0;
		}
		else
		{
			hor[i] = 0;
			ver[i] = (str[i] == 'U' ? 1 : -1);
		}
	}
	for (int i = 0; i < n; i++)
	{
		sumHor[i] = hor[i] + (i > 0 ? sumHor[i - 1] : 0);
		sumVer[i] = ver[i] + (i > 0 ? sumVer[i - 1] : 0);
		sizeHor[sumHor[i] + C]++;
		sizeVer[sumVer[i] + C]++;
	}
	for (int i = 0; i < N; i++)
	{
		posHor[i].reserve(sizeHor[i]);
		posVer[i].reserve(sizeVer[i]);
	}
	for (int i = 0; i < n; i++)
	{
		posHor[sumHor[i] + C].push_back(i);
		posVer[sumVer[i] + C].push_back(i);
	}
	int distL = 0, distR = 0, distU = 0, distD = 0;

	int it = 0;
	int ans = 0;
	while (distL + distR < w && distU + distD < h)
	{
		int curW = w - distL - distR;
		int curH = h - distU - distD;
		int tme = getTimeHor(it, distR + 1);
		tme = min(tme, getTimeHor(it, -distL - 1));
		tme = min(tme, getTimeVer(it, distU + 1));
		tme = min(tme, getTimeVer(it, -distD - 1));
		if (tme == INF)
		{
			puts("-1");
			return 0;
		}
		int delta = tme - it + 1;
		int dHor = sumHor[tme] - (it > 0 ? sumHor[it - 1] : 0);
		int dVer = sumVer[tme] - (it > 0 ? sumVer[it - 1] : 0);

//		printf("l: %d, r: %d, u: %d, d: %d, delta: %d\n", distL, distR, distU, distD, delta);

		it = (tme + 1) % len;
		ans = add(ans, mult(mult(curW, curH), delta));


		distR -= dHor;
		distL += dHor;

		distU -= dVer;
		distD += dVer;

		distR = min(max(distR, 0), w);
		distL = min(max(distL, 0), w);

		distU = min(max(distU, 0), h);
		distD = min(max(distD, 0), h);
	}
	printf("%d\n", ans);

	return 0;
}