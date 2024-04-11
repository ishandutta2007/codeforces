#include <iostream>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

const int A = 27;
const int N = (int)2e6 + 10;
const int V = N;
char str[N];
char query[N];

int to[A][V];
int link[A][V];
int maskLink[V];

int pi[N];
int parent[V];
int len[V], pos[V];
int countLeafs[V];
int suffLink[V];
int sz = 2;
int slen = 0;
int qlen = 0;
const char MS = 'a' - 1;

void attach(int a, int b, int p, int l)
{
	to[str[p] - MS][a] = b;
	pos[b] = p;
	len[b] = l;
	parent[b] = a;
}

void expand(char c)
{
	int v, index = slen;
	for (v = sz - 1; !((maskLink[v] >> (c - MS)) & 1); v = parent[v])
		index -= len[v];

	int l = link[c - MS][v];
	if (to[str[index] - MS][l] != -1)
	{
		int u = to[str[index] - MS][l];
		pos[sz] = pos[u];
		while (str[pos[sz]] == str[index])
		{
			v = to[str[index] - MS][v];
			pos[sz] += len[v];
			index += len[v];
		}
		int newLen = pos[sz] - pos[u];
		link[c - MS][v] = sz;
		maskLink[v] |= (1 << (c - MS));
		attach(l, sz, pos[u], newLen);
		attach(sz, u, pos[u] + newLen, len[u] - newLen);
		l = sz++;
	}
	attach(l, sz++, index, slen - index);
}

void initTree()
{
	memset(link, -1, sizeof(link));
	memset(to, -1, sizeof(to));
	for (int i = 0; i < A; i++)
	{
		link[i][0] = to[i][0] = 1;
		maskLink[0] |= (1 << i);
	}
	parent[1] = 0;
	len[1] = 1;
	pos[1] = 0;
}

bool goChar(int &vertex, int &edgePosition, char c)
{
	if (edgePosition < len[vertex])
	{
		if (str[pos[vertex] + edgePosition] == c)
		{
			edgePosition++;
			return true;
		}
	}
	else if (to[c - MS][vertex] != -1)
	{
		vertex = to[c - MS][vertex];
		edgePosition = 1;
		return true;
	}
	return false;
}

void goLink(int &vertex, int &edgePosition)
{
	if (edgePosition == len[vertex])
	{
		vertex = suffLink[vertex];
		edgePosition = len[vertex];
	} 
	else
	{
		int l = suffLink[parent[vertex]];
		int index = 0;
		while (index < edgePosition)
		{
			l = to[str[pos[vertex] + index] - MS][l];
			index += len[l];
		}
		vertex = l;
		edgePosition = len[vertex] - (index - edgePosition);
	}
}

void processQuery()
{
	int answer = 0;
	int vertex = 1, edgePosition = 1;
	int it = 0;
	for (int i = 1; i < 2 * qlen; i++)
	{
		int p = pi[i - 1];
		while (p > 0 && query[i] != query[p])
			p = pi[p - 1];
		if (query[i] == query[p])
			p++;
		pi[i] = p;
	}
	for (int i = 0; i < qlen; i++)
	{
		while (it - i < qlen && goChar(vertex, edgePosition, query[it]))
			it++;
		if (pi[i + qlen - 1] >= qlen)
			break;
		if (it - i == qlen)
			answer += countLeafs[vertex];
		goLink(vertex, edgePosition);
	}
	printf("%d\n", answer);
}

void calcInfo(int v)
{
	if (pos[v] + len[v] == slen)
		countLeafs[v] = 1;
	for (int i = 0; i < A; i++)
	{
		int child = to[i][v];
		if (child != -1)
		{
			calcInfo(child);
			countLeafs[v] += countLeafs[child];
		}
	}
	for (int i = 0; i < A; i++)
	{
		int l = link[i][v];
		if (l != -1)
			suffLink[l] = v;
	}
}

int main()
{
	scanf("%s", str);
	slen = strlen(str);
	str[slen++] = MS;
	initTree();
	for (int i = slen - 1; i >= 0; i--)
		expand(str[i]);
	
	suffLink[1] = 0;
	calcInfo(1);
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		scanf(" %s", query);	
		qlen = strlen(query);
		strcat(query, query);
		processQuery();
	}
	return 0;
}