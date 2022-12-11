#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cmath>
using namespace std;

typedef long long ll;
#define X first
#define Y second
#define mp make_pair

const int E = (int)1e5;
const int N = 4000 + 100;

struct Event
{
	int tme, type;
	int value;
	Event () {}
	Event (int _tme, int _type, int v) : tme(_tme), type(_type), value(v) {}
};

struct Item
{
	int cost;
	int hap;
	Item () {}
	Item (int c, int h) : cost(c), hap(h) {}
};

int dp[2][N][N];

void calcDp(int index, int startIndex, int endIndex, Item *values)
{
	for (int i = startIndex; i <= endIndex; i++)
	{
		for (int s = 0; s < N; s++)
		{
			int old = s - values[i - 1].cost;
			dp[index][i][s] = 0;
			if (old >= 0)
				dp[index][i][s] = dp[index][i - 1][old] + values[i - 1].hap;
			dp[index][i][s] = max(dp[index][i][s], dp[index][i - 1][s]);
		}
	}
}

Event listEvent[E];
int indE = 0;
Item items[N];
int tStart[N];
int money[E];
int resultDp[N];
int answer[E];


struct Queue
{
	Item frontS[N];
	Item backS[N];
	int fSz, bSz;
	Queue ()
	{
		fSz = bSz = 0;
	}
	void push(Item value)
	{
		backS[bSz++] = value;
		calcDp(0, bSz, bSz, backS);
	}
	void pop()
	{
		if (fSz > 0)
		{
			fSz--;
			return;
		}
		while (bSz > 0)
		{
			frontS[fSz++] = backS[bSz - 1];
			bSz--;
		}
		fSz--;
		calcDp(1, 1, fSz, frontS);
	}
} q;

bool cmpEvent(const Event &a, const Event &b)
{
	if (a.tme != b.tme)
		return a.tme < b.tme;
	if (a.type != b.type)
		return a.type < b.type;
	return a.value < b.value;
}

void delThing()
{
	q.pop();
}

void addThing(int c, int h)
{
	q.push(Item(c, h));
}

int getAnswer(int m)
{
	int result = 0;
	for (int i = 0; i <= m; i++)
		result = max(result, dp[0][q.bSz][i] + dp[1][q.fSz][m - i]);
	return result;
}

int main()
{
	int n, p;
	scanf("%d%d", &n, &p);

	for (int i = 0; i < n; i++)
	{
		int cost, hap;
		scanf("%d%d%d", &cost, &hap, &tStart[i]);
		items[i] = Item(cost, hap);
		listEvent[indE++] = Event(tStart[i], 1, i);
		listEvent[indE++] = Event(tStart[i] + p, -1, i);
	}

	int cntQ;
	scanf("%d", &cntQ);
	for (int i = 0; i < cntQ; i++)
	{
		int t;
		scanf("%d%d", &t, &money[i]);
		listEvent[indE++] = Event(t, 2, i);
	}

	sort(listEvent, listEvent + indE, cmpEvent);

	for (int i = 0; i < indE; i++)
	{
		int index = listEvent[i].value;
		if (listEvent[i].type == 2)
			answer[index] = getAnswer(money[index]);
		else if (listEvent[i].type == 1)
			addThing(items[index].cost, items[index].hap);
		else
			delThing();
	}

	for (int i = 0; i < cntQ; i++)
		printf("%d\n", answer[i]);

	return 0;
}