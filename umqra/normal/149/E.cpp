#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int A = 26;
const int INF = (int)1e8;
const int N = (int)3e5;

struct Node
{
	int go[A];
	int suff, len;
	Node ()
	{
		suff = len = 0;
		for (int i = 0; i < A; i++)
			go[i] = 0;
	}
} tree[N];
int mv = 2;
int maxPath[N], minPath[N];
bool term[N];
int root = 1;
bool used[N];
char str[N], t[N];

void addSumbol(int c)
{
	int nR = mv++;
	tree[nR].len = tree[root].len + 1;
	int p;
	for (p = root; p != 0 && tree[p].go[c] == 0; p = tree[p].suff)
		tree[p].go[c] = nR;
	if (p != 0)
	{
		int q = tree[p].go[c];
		if (tree[q].len == tree[p].len + 1)
			tree[nR].suff = q;
		else
		{       
			int clone = mv++;
			tree[clone].len = tree[p].len + 1;
			tree[clone].suff = tree[q].suff;
			for (int i = 0; i < A; i++) tree[clone].go[i] = tree[q].go[i];
			tree[q].suff = tree[nR].suff = clone;
			for (;p != 0 && tree[p].go[c] == q; p = tree[p].suff)
				tree[p].go[c] = clone;
		}
	}
	else
		tree[nR].suff = 1;
	root = nR;
}

void calcPaths(int v)
{
	if (used[v] || v == 0)
		return;	
	if (term[v])
		minPath[v] = maxPath[v] = 0;
	used[v] = 1;                                    
	for (int i = 0; i < A; i++)
	{
		calcPaths(tree[v].go[i]);
		if (tree[v].go[i] != 0)
		{
			minPath[v] = min(minPath[v], minPath[tree[v].go[i]] + 1);
			maxPath[v] = max(maxPath[v], maxPath[tree[v].go[i]] + 1);
		}
	}
}

bool check(int a, int b)
{       	
	int vA = 1, vB = 1;
	for (int i = 0; i < a; i++) 
		vA = tree[vA].go[t[i] - 'A'];

	for (int i = a; i < a + b; i++)
		vB = tree[vB].go[t[i] - 'A'];     
	if (vA == 0 || vB == 0)
		return false;

	if (maxPath[vA] >= minPath[vB] + b)
		return true;
	return false;
}

void printTree(int v)
{
	if (used[v] || v == 0)
		return;
	used[v] = 1;
	printf("Vertex = %d, suff = %d.\nGo:", v, tree[v].suff);
	for (int i = 0; i < A; i++)
		printf("%c = %d, ", i + 'A', tree[v].go[i]);
	puts("");
	for (int i = 0; i < A; i++)
		printTree(tree[v].go[i]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	int n;
	scanf("%s\n%d\n", str, &n);
	int strL = strlen(str);

	for (int i = 0; i < strL; i++)
		addSumbol(str[i] - 'A');                   	

	for (int i = root; i != 0; i = tree[i].suff)
		term[i] = 1;

	fill(minPath, minPath + N, INF);
	calcPaths(1);
	fill(used, used + N, 0);           

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%s\n", t);
		int l = strlen(t);
		for (int i = 1; i < l; i++)
		{
			if (check(i, l - i))
			{                                                   
				cnt++;
				break;
			}
		}
	}

	printf("%d", cnt);

	return 0;
}