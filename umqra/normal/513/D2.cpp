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

const int N = (int)1e6 + 100;
vector <int> leftChild[N], rightChild[N];
int maxLeft[N], minLeft[N];
int maxRight[N], minRight[N];

#define index ajsdhkads
char com[10];
int answer[N];
int index = 0;

int mv = 2;

void fail()
{
	puts("IMPOSSIBLE");
	exit(0);
}

int solve(int v, int maxV)
{
	if (v > maxV)
		return maxV;
	if (leftChild[v].size() > 0)
	{
		int mx = solve(mv++, maxLeft[v]);
		if (rightChild[v].size() > 0 && mx >= minRight[v])
			fail();
		answer[index++] = v;
		if (mv <= max(maxRight[v], maxV))
			return solve(mv++, max(maxV, maxRight[v]));
		return max(maxV, mx);
	}
	answer[index++] = v;
	if (mv <= max(maxRight[v], maxV))
		return solve(mv++, max(maxV, maxRight[v]));
	return maxV;
}

int main()
{
	int n, c;
	scanf("%d%d", &n, &c);	
	for (int i = 0; i < c; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (a >= b)
			fail();
		scanf(" %s", com);
		if (com[0] == 'L')
			leftChild[a].push_back(b);
		else
			rightChild[a].push_back(b);
	}
	for (int i = 1; i <= n; i++)
	{
		if (leftChild[i].size() > 0)
		{
			minLeft[i] = *min_element(leftChild[i].begin(), leftChild[i].end());
			maxLeft[i] = *max_element(leftChild[i].begin(), leftChild[i].end());
		}
	
		if (rightChild[i].size() > 0)
		{
			minRight[i] = *min_element(rightChild[i].begin(), rightChild[i].end());
			maxRight[i] = *max_element(rightChild[i].begin(), rightChild[i].end());
		}
	}

	solve(1, n);
	for (int i = 0; i < index; i++)
		printf("%d ", answer[i]);

	return 0;
}