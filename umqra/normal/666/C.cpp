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
#include <cassert>
#include <complex>
#include <valarray>
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

const int A = 26;
const int mod = (int)1e9 + 7;

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

int myPow(int a, int k)
{
	if (k == 0)
		return 1;
	if (k & 1)
		return mult(a, myPow(a, k - 1));
	int t = myPow(a, k / 2);
	return mult(t, t);
}

int rev(int a)
{
	return myPow(a, mod - 2);
}

const int N = (int)1e5 + 10;
int fact[N];
int rFact[N];

void init()
{
	fact[0] = 1;
	for (int i = 1; i < N; i++)
		fact[i] = mult(fact[i - 1], i);
	rFact[N - 1] = rev(fact[N - 1]);
	for (int i = N - 2; i >= 0; i--)
		rFact[i] = mult(rFact[i + 1], i + 1);
}

int getC(int n, int k)
{
	if (k > n || k < 0)
		return 0;
	return mult(fact[n], mult(rFact[n - k], rFact[k]));
}

const int LEN = (int)1e5 + 10;
char str[LEN];
int n;

void scan(string &s)
{
	scanf(" %s", str);
	s = string(str, str + strlen(str));
}

int queryType[N];
string queryValue[N];
int queryInt[N];

void read()
{
	scanf("%d", &n);
	queryType[0] = 1;
	scan(queryValue[0]);
	n++;
	for (int i = 1; i < n; i++)
	{
		scanf("%d", &queryType[i]);
		scan(queryValue[i]);
		if (queryType[i] == 2)
			queryInt[i] = atoi(queryValue[i].c_str());
	}
}

vector <int> lens;

vector<int> need[N];
int ans[N];
void solveForLen(int len)
{
	for (int i = 0; i < N; i++)
		need[i].clear();
	int setLen = 0;
	for (int i = 0; i < n; i++)
	{
		if (queryType[i] == 1)
			setLen = (int)queryValue[i].length();
		else
		{
			if (setLen == len)
				need[queryInt[i]].push_back(i);
		}
	}
	int sum = 0;
	int rA = rev(A);
	int value = myPow(rA, len);

	for (int i = len; i < N; i++)
	{
		sum = add(sum, mult(value, getC(i - 1, len - 1)));
		for (int id : need[i])
			ans[id] = sum;
		value = mult(value, mult(A - 1, rA));
	}
}

void solve()
{
	for (int i = 0; i < n; i++)
	{
		if (queryType[i] == 1)
			lens.push_back((int)queryValue[i].size());
	}
	sort(lens.begin(), lens.end());
	lens.resize(unique(lens.begin(), lens.end()) - lens.begin());
	for (int l : lens)
		solveForLen(l);
	for (int i = 0; i < n; i++)
	{
		if (queryType[i] == 2)
		{
			int res = ans[i];
			res = mult(res, myPow(A, queryInt[i]));
			printf("%d\n", res);
		}
	}
}

int main()
{
	init();
	read();
	solve();
	return 0;
}