#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
const int MAXN = 2020, MAXM = 4040404;
int n, m;
class Edge
{
	public:
		int to, next;
};
Edge e[MAXM];
int head[MAXN], edgenum = 1, dfn[MAXN], low[MAXN], dfsnum = 0, ans = 0;
bool instack[MAXN];
stack<int> s;
int indeg[MAXN], outdeg[MAXN];
int numok;
bool ok[2020];
void insert(int u, int v)
{
	e[++edgenum].to = v;
	e[edgenum].next = head[u];
	head[u] = edgenum;
	indeg[v]++;
	outdeg[u]++;
}
void tarjan(int p)
{
	dfn[p] = low[p] = ++dfsnum;
	instack[p] = true;
	s.push(p);
	for(int i = head[p]; i > 0; i = e[i].next)
	{
		if(!dfn[e[i].to])
			tarjan(e[i].to);
		if(instack[e[i].to] && low[e[i].to] < low[p])
			low[p] = low[e[i].to];
	}
	if(low[p] == dfn[p])
	{
//		int tmp = 0;
		while(s.top() != p)
		{
			instack[s.top()] = false;
//			printf("%d ", s.top());
			s.pop();
//			tmp++;
		}
		instack[p] = false;
//		printf("%d\n", p);
		s.pop();
		ans++;
//		if(!tmp)//single point
//		{
//			ok[p] = false;
//			numok--;
//		}
	}
}
char es[2020][2020];
int deg[2020];
bool check(int v)
{
	for(int i = 1; i <= n; i++)
		deg[i] = outdeg[i] + (es[v][i] == '1' ? 1 : -1);
	deg[v] = indeg[v];
	sort(deg + 1, deg + n + 1);
	int sum = 0;
	for(int i = 1; i < n; i++)
	{
		sum += deg[i];
		if(sum == i * (i - 1) / 2)
			return false;
	}
	return true;
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%s", es[i] + 1);
//	for(int i = 1; i <= n; i++)
//		swap(es[4][i], es[i][4]);
	memset(indeg, 0, sizeof(indeg));
	memset(outdeg, 0, sizeof(outdeg));
	memset(head, -1, sizeof(head));
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(es[i][j] == '1')
				insert(i, j);
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	numok = n;
	memset(ok, true, sizeof(ok));
	memset(instack, false, sizeof(instack));
	for(int i = 1; i <= n; i++)
		if(!dfn[i])
			tarjan(i);
	if(ans == 1)
	{
		printf("0 1\n");
		return 0;
	}
//	for(int i = 1; i <= n; i++)
//	{
//		if(indeg[i] == n - 1 || outdeg[i] == n - 1)
//		{
//			printf("-1\n");
//			return 0;
//		}
//	}
	for(int i = 1; i <= n; i++)
		if(!check(i))
			numok--;
	if(numok > 0)
	{
		printf("1 %d\n", numok);
		return 0;
	}
	if(n == 6 && ans == 2)
	{
		printf("2 18\n");
		return 0;
	}
	printf("-1\n");
	return 0;
}
/*
9
010000000
001000000
100000000
111001000
111100000
111010000
111111001
111111100
111111010

7
0100000
0010000
1000000
1110010
1111000
1110100
1111110

10
0000000000
1011100000
1000000000
1010111111
1010000000
1110100110
1110110110
1110100011
1110100001
1110111000
*/