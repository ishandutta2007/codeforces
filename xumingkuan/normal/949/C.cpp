#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
const int MAXN = 101010, MAXM = 202020;
int n, m, h, u[MAXN], c[MAXN][2];
class Edge
{
public:
	int to, next;
}e[MAXM], e2[MAXM];
int head[MAXN], en = 0, head2[MAXN], en2 = 0;
void insert(int u, int v)
{
//	printf("insert %d %d\n", u, v);
	e[++en].to = v;
	e[en].next = head[u];
	head[u] = en;
}
void insert2(int u, int v)
{
	e2[++en2].to = v;
	e2[en2].next = head2[u];
	head2[u] = en2;
}
int dfn[MAXN], low[MAXN], dfsnum = 0;
stack<int> st;
int block[MAXN], bls[MAXN], bln = 0;
int ansblk = 0, ans;
bool instack[MAXN];
void tarjan(int p)
{
	dfn[p] = low[p] = ++dfsnum;
	st.push(p);
	instack[p] = true;
	for(int i = head[p]; i > 0; i = e[i].next)
	{
		if(!dfn[e[i].to])
			tarjan(e[i].to);
		if(low[e[i].to] < low[p] && instack[e[i].to])
			low[p] = low[e[i].to];
	}
	if(low[p] == dfn[p])
	{
		bln++;
		bls[bln] = 0;
//		printf("block %d: ", bln);
		while(st.top() != p)
		{
			block[st.top()] = bln;
			instack[st.top()] = false;
//			printf("%d ", st.top());
			bls[bln]++;
			st.pop();
		}
		block[p] = bln;
		instack[p] = false;
//		printf("%d\n", p);
		bls[bln]++;
		st.pop();
	}
}
int main()
{
	scanf("%d%d%d", &n, &m, &h);
	for(int i = 1; i <= n; i++)
		scanf("%d", &u[i]);
	memset(head, -1, sizeof(head));
	for(int i = 1; i <= m; i++)
	{
		scanf("%d%d", &c[i][0], &c[i][1]);
		if((u[c[i][0]] + 1) % h == u[c[i][1]])
			insert(c[i][0], c[i][1]);
		if((u[c[i][1]] + 1) % h == u[c[i][0]])
			insert(c[i][1], c[i][0]);
	}
	memset(instack, false, sizeof(instack));
	memset(dfn, 0, sizeof(dfn));
	for(int i = 1; i <= n; i++)
		if(!dfn[i])
			tarjan(i);
	memset(head2, -1, sizeof(head2));
	for(int i = 1; i <= n; i++)
		for(int j = head[i]; j > 0; j = e[j].next)
			if(block[i] != block[e[j].to])
				insert2(block[i], block[e[j].to]);
	ans = n + 1;
	for(int i = 1; i <= bln; i++)
		if(head2[i] == -1)
		{
			if(bls[i] < ans)
			{
				ans = bls[i];
				ansblk = i;
			}
		}
	printf("%d\n", ans);
	for(int i = 1; i <= n; i++)
		if(block[i] == ansblk)
			printf("%d ", i);
	return 0;
}