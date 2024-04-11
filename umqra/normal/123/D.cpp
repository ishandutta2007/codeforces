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

const int N = (int)1e5 + 10;
const int V = 2 * N;

struct SuffixAutomat
{
	map <char, int> go[V];
	int link[V];
	int len[V];
	int cnt[V];
	int used[V];
	ll ans[V];
	int curState;
	int mv;

	SuffixAutomat()
	{
		for (int i = 0; i < N; i++)
		{
			link[i] = -1;
			len[i] = 0;
			go[i] = map<char, int>();
			used[i] = 0;
		}
		curState = 0;
		mv = 1;
	}
	void addChar(char c)
	{
		int newState = mv++;
		len[newState] = len[curState] + 1;
		int p;
		for (p = curState; p != -1 && go[p].count(c) == 0; p = link[p])
			go[p][c] = newState;
		if (p == -1)
		{
			link[newState] = 0;
			curState = newState;
			return;
		}
		int q = go[p][c];
		if (len[q] == len[p] + 1)
		{
			link[newState] = q;
			curState = newState;
			return;
		}
		int clone = mv++;
		go[clone] = go[q];
		link[clone] = link[q];
		len[clone] = len[p] + 1;

		link[q] = clone;
		for (; p != -1 && go[p][c] == q; p = link[p])
			go[p][c] = clone;
		link[newState] = clone;
		curState = newState;
	}
	int calcCounts(int v)
	{
		if (used[v])
			return cnt[v];
		used[v] = 1;
		for (auto to : go[v])
			cnt[v] += calcCounts(to.second);
		return cnt[v];
	}
	void markTerm()
	{
		for (int p = curState; p != -1; p = link[p])
			cnt[p] = 1;
	}
	void calcCounts()
	{
		markTerm();
		calcCounts(0);
	}
	ll solve(int v)
	{
		if (used[v])
			return ans[v];
		used[v] = 1;
		ans[v] = (v != 0 ? 1LL * cnt[v] * (cnt[v] + 1) / 2 : 0);
		for (auto to : go[v])
			ans[v] += solve(to.second);
		return ans[v];
	}
	ll solve()
	{
		memset(used, 0, sizeof(used));
		return solve(0);
	}
};

char str[N];
SuffixAutomat sa;

int main()
{
	scanf("%s", str);
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		sa.addChar(str[i]);
	}
	sa.calcCounts();
	printf("%lld\n", sa.solve());
	
	return 0;
}