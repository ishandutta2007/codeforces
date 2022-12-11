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

const int A = 26;
const int N = (int)3e5 + 100;

struct Node
{
	Node *go[A];
	int cnt;
	bool term;
	Node ()
	{
		term = false;
		cnt = 0;
		for (int i = 0; i < A; i++)
			go[i] = 0;
	}
	void recalcCnt()
	{
		cnt = term;
		for (int i = 0; i < A; i++)
			cnt += go[i] == 0 ? 0 : go[i] -> cnt;
	}
	void addLetter(char c)
	{
		int code = c - 'a';
		if (go[code] == 0)
			go[code] = new Node();
		go[code] -> term = 1;
		go[code] -> recalcCnt();
		recalcCnt();
	}
	void dfs(Node *p)
	{
		if (p == 0)
			return;
		term |= p -> term;
		for (int i = 0; i < A; i++)
		{
			Node *to = p -> go[i];
			if (to == 0)
				continue;
			if (go[i] == 0)
				go[i] = new Node();
			go[i] -> addBor(to);
		}
		recalcCnt();
	}
	void addBor(Node *ptr)
	{
		dfs(ptr);
	}
	Node * up(char c)
	{
		Node* nw = new Node();
		nw -> go[c - 'a'] = this;
		nw -> recalcCnt();
		return nw;
	}
};

int ansMax = 0, ansCnt = 0;
vector <int> g[N];
char letters[N];
int c[N];

Node *dfs(int v, int par = -1)
{
	vector <Node *> childs = vector<Node *>();
	int maxChild = -1;
	for (int to : g[v])
	{
		if (to == par)
			continue;
		childs.push_back(dfs(to, v));
		if (maxChild == -1 || childs[maxChild] -> cnt < childs.back() -> cnt)
			maxChild = (int)childs.size() - 1;
	}

	if (maxChild == -1)
	{
		Node *p = new Node();
		p -> addLetter(letters[v]);
		if (c[v] + (p -> cnt) > ansMax)
		{
			ansMax = c[v] + p -> cnt;
			ansCnt = 1;
		}
		else if (c[v] + p -> cnt == ansMax)
			ansCnt++;
		return p;
	}
	Node *root = 0;
	int i = 0;
	for (int to : g[v])
	{
		if (to == par)
			continue;
		if (i == maxChild)
		{
			root = childs[i] -> up(letters[v]);
			break;
		}
		i++;
	}
	root -> addLetter(letters[v]);

	i = 0;
	for (int to : g[v])
	{
		if (to == par)
			continue;
		if (i != maxChild)
		{
			childs[i] = childs[i] -> up(letters[v]);
			root -> addBor(childs[i]);
		}
		i++;
	}
	if (c[v] + (root -> cnt) > ansMax)
	{
		ansMax = c[v] + root -> cnt;
		ansCnt = 1;
	}
	else if (c[v] + root -> cnt == ansMax)
		ansCnt++;
	return root;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &c[i]);
	}
	scanf(" %s", letters);

	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs(0);
	printf("%d\n%d", ansMax, ansCnt);

	return 0;
}