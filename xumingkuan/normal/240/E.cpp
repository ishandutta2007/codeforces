#include <stdio.h>
#include <string.h>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <utility>
#include <iostream>
using namespace std;
#define MAXN 101010
int n, m;
char input[2020202], *zz;
inline void inputnum(int &p)
{
	p = 0;
	while(*zz < '0' || *zz > '9')
		zz++;
	while(*zz >= '0' && *zz <= '9')
		p = p * 10 + *zz++ - '0';
}
class Edge
{
	public:
		int from, to, next;
};
Edge e0[MAXN], e1[MAXN];
int h0[MAXN], h1[MAXN], num = 0, ans[MAXN];
bool visit[MAXN];
inline void insert(Edge *e, int *h, int u, int v)
{
	e[++num].to = v;
	e[num].from = u;
	e[num].next = h[u];
	h[u] = num;
}
bool instack[MAXN];
void dfs(int p)
{
	visit[p] = true;
	for(int i = h0[p]; i > 0; i = e0[i].next)
		if(!visit[e0[i].to])
			dfs(e0[i].to);
	for(int i = h1[p]; i > 0; i = e1[i].next)
		if(!visit[e1[i].to])
			dfs(e1[i].to);
}
int edgetype[MAXN];
int low[MAXN], dfn[MAXN], dfsnum = 0;
stack <int> st;
int block[MAXN], blocknum = 0;
void tarjan(int p)
{
	low[p] = dfn[p] = ++dfsnum;
	instack[p] = true;
	st.push(p);
	for(int i = h0[p]; i > 0; i = e0[i].next)
	{
		if(!dfn[e0[i].to])
			tarjan(e0[i].to);
		if(instack[e0[i].to] && low[e0[i].to] < low[p])
			low[p] = low[e0[i].to];
	}
	if(low[p] == dfn[p])
	{
		blocknum++;
		while(st.top() != p)
		{
			block[st.top()] = blocknum;
			instack[st.top()] = false;
			st.pop();
		}
		instack[p] = false;
		block[p] = blocknum;
		st.pop();
	}
}
set <int> to0[MAXN];
map <int, int> to1[MAXN];
int indegree[MAXN], in1[MAXN];
queue <int> q;
int seq[MAXN], seqnum;
bool dead[MAXN];
void dfs2(int p)
{
	visit[p] = true;
	dead[block[p]] = true;
	block[p] = block[1];
	for(int i = h0[p]; i > 0; i = e0[i].next)
		if(!visit[e0[i].to])
			dfs2(e0[i].to);
}
int remain;
bool visit2[MAXN];
queue <pair <int, int> > qe;
void aug(int tmp)
{
	for(set <int> :: iterator it1 = to0[tmp].begin(); it1 != to0[tmp].end(); it1++)
		if(!visit2[*it1])
		{
			q.push(*it1);
			visit2[*it1] = true;
			aug(*it1);
		}
	for(map <int, int> :: iterator it1 = to1[tmp].begin(); it1 != to1[tmp].end(); it1++)
		if(!visit2[it1->first] && !visit[it1->second])
		{
			q.push(it1->first);
			visit2[it1->first] = true;
			aug(it1->first);
		}
}
void bfs2()
{
	while(!q.empty())
		q.pop();
	q.push(block[1]);
	memset(visit2, false, sizeof(visit2));
	visit2[1] = true;
	aug(block[1]);
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		for(map <int, int> :: iterator it = to1[now].begin(); it != to1[now].end(); it++)
			if(!visit2[it->first] && visit[it->second] && indegree[it->first] == 0)
			{
				visit[it->second] = false;
				int tmp = it->first;
				q.push(tmp);
				visit2[tmp] = true;
				remain--;
				aug(tmp);
			}
			else if(!visit2[it->first] && visit[it->second])
				qe.push(*it);
		if(remain == 0)
			break;
		if(q.empty())
		{
			while(!qe.empty())
			{
				pair <int, int> now1 = qe.front();
				if(!visit2[now1.first] && visit[now1.second])
				{
					visit[now1.second] = false;
					visit2[now1.first] = true;
					q.push(now1.first);
					aug(now1.first);
					qe.pop();
					break;
				}
				qe.pop();
			}
		}
	}
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	fread(input, 1, 2020000, stdin);
	zz = input;
	inputnum(n);
	inputnum(m);
	memset(h0, 0, sizeof(h0));
	memset(h1, 0, sizeof(h1));
	for(int i = 1; i <= m; i++)
	{
		int a, b, c;
		inputnum(a);
		inputnum(b);
		inputnum(c);
		if(c)
			insert(e1, h1, a, b), edgetype[i] = 1;
		else
			insert(e0, h0, a, b), edgetype[i] = 0;
	}
	memset(ans, 0, sizeof(ans));
	memset(visit, false, sizeof(visit));
	dfs(1);
	for(int i = 1; i <= n; i++)
		if(!visit[i])
		{
			printf("-1\n");
			return 0;
		}
	memset(instack, false, sizeof(instack));
	memset(low, 0, sizeof(low));
	memset(dfn, 0, sizeof(dfn));
	for(int i = 1; i <= n; i++)
		if(!dfn[i])
			tarjan(i);
	memset(visit, false, sizeof(visit));
	memset(dead, false, sizeof(dead));
	dfs2(1);
	dead[block[1]] = false;
	int tmp1 = 0;
	for(int i = 1; i <= blocknum; i++)
		if(!dead[i])
			seq[++tmp1] = i;
	seqnum = tmp1;
	for(int i = 1; i <= m; i++)
	{
		if(edgetype[i] == 0)
		{
			if(block[e0[i].from] != block[e0[i].to])
				to0[block[e0[i].from]].insert(block[e0[i].to]);
		}
		else
		{
			if(block[e1[i].from] != block[e1[i].to] && block[e1[i].to] != block[1])
				to1[block[e1[i].from]].insert(make_pair(block[e1[i].to], i));
		}
	}
	tmp1 = 101010;
	memset(indegree, 0, sizeof(indegree));
	for(int i = 1; i <= seqnum; i++)
		for(set <int> :: iterator it = to0[seq[i]].begin(); it != to0[seq[i]].end(); it++)
			indegree[*it]++;
	memset(visit, true, sizeof(visit));//0:repaired
	remain = 0;
	for(int i = 1; i <= seqnum; i++)
		if(seq[i] != block[1] && indegree[seq[i]] == 0)
			remain++;
	bfs2();
	tmp1 = 0;
	for(int i = 1; i <= m; i++)
		if(!visit[i])
			ans[++tmp1] = i;
	printf("%d\n", tmp1);
	for(int i = 1; i <= tmp1; i++)
		printf("%d ", ans[i]);
	return 0;
}