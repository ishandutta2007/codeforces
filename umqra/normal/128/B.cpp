#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
using namespace std;

const int A = 26;
const int SZ = (int)2e5 + 10;

struct Node
{
	int go[A];
	int link;
	int len;
	Node () 
	{
		memset(go, -1, sizeof(go));
		link = -1;
		len = 0;
	}
	int get(int c)
	{
		return go[c];
	}
	void set(int c, int to)
	{
		go[c] = to;
	}
	void eprint()
	{
		printf("link: %d, len: %d, gos:\n", link, len);
		for (int i = 0; i < A; i++)
		{
			if (go[i] != -1)
				printf("%d ", go[i]);
		}
		puts("");
	}
};

//CHECK SIZE. AUTOMATON CONTAINS UP TO 2N + 1 VERTICES
Node tree[SZ];
int term[SZ];
int mv = 1;
int last = 0;

void addChar(int c)
{
	int v = mv++, p;
	for (p = last; p != -1 && tree[p].get(c) == -1; p = tree[p].link)
		tree[p].set(c, v);
	tree[v].len = tree[last].len + 1;
	if (p != -1)
	{
		int q = tree[p].get(c);
		if (tree[p].len + 1 == tree[q].len)
			tree[v].link = q;
		else
		{
			int clone = mv++;
			tree[clone] = tree[q];
			tree[clone].len = tree[p].len + 1;
			tree[clone].link = tree[q].link;
			tree[q].link = clone;
			tree[v].link = clone;
			for (; p != -1 && tree[p].get(c) == q; p = tree[p].link)
				tree[p].set(c, clone);
		}
	}
	else
		tree[v].link = 0;
	last = v;
}

void markTerm()
{
	for (int v = last; v != -1; v = tree[v].link)
		term[v] = 1;
}

int k;

int add(int a, int b)
{
	a += b;
	if (a > k)
		return k;
	return a;
}

char str[SZ];
int cnt[SZ];
int subCnt[SZ];
int used[SZ];

void dfs(int v, int *arr)
{
	if (used[v])
		return;
	used[v] = 1;
	for (int i = 0; i < A; i++)
	{
		int to = tree[v].get(i);
		if (to != -1)
		{
			dfs(to, arr);
			arr[v] = add(arr[v], arr[to]);
		}
	}
}

void calcCnt()
{
	memset(used, 0, sizeof(used));
	for (int i = 0; i < mv; i++)
		cnt[i] = term[i];
	dfs(0, cnt);
}

void calcSubCnt()
{
	memset(used, 0, sizeof(used));
	for (int i = 0; i < mv; i++)
		subCnt[i] = cnt[i];
	dfs(0, subCnt);
}

string res = "";

void printString(int v, int t)
{
	if (t <= cnt[v] && v != 0)
	{
		printf("%s\n", res.c_str());
		exit(0);
	}
	if (v != 0)
		t -= cnt[v];
	for (int i = 0; i < A; i++)
	{
		int to = tree[v].get(i);
		if (to == -1)
			continue;
		if (subCnt[to] < t)
			t -= subCnt[to];
		else
		{
			res.push_back(i + 'a');
			return printString(to, t);
		}
	}
}

int main()
{
	scanf("%s", str);
	scanf("%d", &k);
	int len = strlen(str);
	for (int i = 0; i < len; i++)
		addChar(str[i] - 'a');
	markTerm();
	calcCnt();
	calcSubCnt();
	printString(0, k);
	puts("No such line.");
	return 0;
}