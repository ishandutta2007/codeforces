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

vector <vector <int>> seq[4];
set <int> pos[2];
int n;
int getType(char c)
{
	return c == 'L' ? 0 : 1;
}

void greedy()
{
	vector <int> curSeq;
	int curPos, type;
	if (*pos[0].begin() < *pos[1].begin())
	{
		curPos = *pos[0].begin();
		type = 0;
	}
	else
	{
		curPos = *pos[1].begin();
		type = 1;
	}
	int mask = type;
	while (1)
	{
		pos[type].erase(curPos);
		curSeq.push_back(curPos);
		int nxt = *pos[1 - type].lower_bound(curPos);
		if (nxt == n)
		{
			mask |= (type << 1);
			seq[mask].push_back(curSeq);
			break;
		}
		curPos = nxt;
		type = 1 - type;
	}
}

void rearrange(int allow)
{
	int bestMask = -1, bestId = -1, maxPos = -1;
	for (int mask = 0; mask < 4; mask++)
	{
		if (!(allow & (1 << mask)))
			continue;
		int curMax = -1, curId = -1;
		for (int i = 0; i < (int)seq[mask].size(); i++)
		{
			for (int x : seq[mask][i])
			{
				if (curMax < x)
				{
					curMax = x;
					curId = i;
				}
			}
		}
		if (curMax > maxPos)
		{
			bestMask = mask;
			bestId = curId;
			maxPos = curMax;
		}
	}
	if (bestMask == -1 || seq[3 ^ bestMask].size() == 0)
		return;
	vector <int> delLast = seq[bestMask][bestId];
	seq[bestMask].erase(seq[bestMask].begin() + bestId);
	vector <int> addLast = seq[3 ^ bestMask][0];
	seq[3 ^ bestMask].erase(seq[3 ^ bestMask].begin());
	delLast.pop_back();
	addLast.push_back(maxPos);
	seq[bestMask ^ 2].push_back(delLast);
	seq[bestMask ^ 1].push_back(addLast);
}

void printLast(int mask)
{
	for (int x : seq[mask].back())
		printf("%d ", x + 1);
	seq[mask].pop_back();
}

void oneEmpty(int mask)
{
	mask ^= 3;
	int start = (mask & 1);
	int end = (mask >> 1);
	int a = (start | (start << 1));
	int b = (end | (end << 1));
	while (seq[b].size() > 0)
		printLast(b);
	while (seq[mask].size() > 0)
		printLast(mask);
	while (seq[a].size() > 0)
		printLast(a);
}

int main()
{
	string str;
	cin >> str;
	n = (int)str.length();
	for (int i = 0; i < n; i++)
	{
		pos[getType(str[i])].insert(i);
	}
	pos[0].insert(n);
	pos[1].insert(n);

	while (pos[0].size() > 1 || pos[1].size() > 1)
	{
		greedy();
	}

	int ans = 0;
	for (int i = 0; i < 4; i++)
		ans += seq[i].size();
	printf("%d\n", ans - 1);
	if (seq[1].size() == 0 || seq[2].size() == 0)
		rearrange((1 << 0) | (1 << 3));

	if (seq[1].size() == 0)
	{
		oneEmpty(1);
		return 0;
	}
	if (seq[2].size() == 0)
	{
		oneEmpty(2);
		return 0;
	}
	if (seq[0].size() == 0 && seq[3].size() == 0)
		rearrange((1 << 1) | (1 << 2));
	

	if (seq[0].size() == seq[3].size())
		printLast(0);

	if (seq[0].size() > seq[3].size())
	{
		while (seq[2].size() > 0)
			printLast(2);
		int id = 0;
		while (seq[id].size() > 0)
		{
			printLast(id);
			id ^= 3;
		}
		while (seq[1].size() > 0)
			printLast(1);
	}
	else
	{
		while (seq[1].size() > 0)
			printLast(1);
		int id = 3;
		while (seq[id].size() > 0)
		{
			printLast(id);
			id ^= 3;
		}
		while (seq[2].size() > 0)
			printLast(2);
	}

	return 0;
}