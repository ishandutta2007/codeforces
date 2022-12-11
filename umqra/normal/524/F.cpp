#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cassert>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef pair<int, int> pii;
typedef long long ll;

#define X first
#define Y second
#define mp make_pair

const int pow2 = (1 << 21);
const int N = pow2;
const int INF = (int)1e9 + 10;
int balance[pow2];
char str[pow2];

struct SegmentTree
{
	int tree[pow2 * 2];
	SegmentTree ()
	{
		for (int i = 0; i < pow2 * 2; i++)
			tree[i] = INF;
	}
	void build(int v = 1, int l = 0, int r = pow2 - 1)
	{
		if (l == r)
		{
			tree[v] = balance[l];
			return;
		}
		int m = (l + r) / 2;
		build(2 * v, l, m);
		build(2 * v + 1, m + 1, r);
		tree[v] = min(tree[2 * v], tree[2 * v + 1]);
	}
	int getMin(int a, int b, int v = 1, int l = 0, int r = pow2 - 1)
	{
		if (l >= a && r <= b)
			return tree[v];
		if (l > b || r < a)
			return INF;
		int m = (l + r) / 2;
		return min(getMin(a, b, 2 * v, l, m), getMin(a, b, 2 * v + 1, m + 1, r));
	}
} tree;

int color[N];
int pos[N];
int arr[N];
int nArr[N];
int nColor[N];
int cnt[N];

inline int add(int a, int b, int m)
{
	a += b;
	if (a < 0)
		return a + m;
	if (a < m)
		return a;
	return a - m;
}

void printArr(int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int s = arr[i]; s < len; s++)
			printf("%c", str[s]);
		puts("");
	}
}

void buildSuffArr(int len)
{
	int maxColor = 0;
	for (int i = 0; i < len; i++)
	{
		color[i] = str[i];
		maxColor = max(maxColor, color[i]);
		cnt[color[i]]++;
	}
	maxColor++;
	for (int i = 1; i < maxColor; i++)
		pos[i] = pos[i - 1] + cnt[i - 1];

	for (int i = 0; i < len; i++)
		arr[pos[color[i]]++] = i;

	for (int shift = 1; shift < len; shift *= 2)
	{
		for (int i = 0; i < len; i++)
			maxColor = max(maxColor, color[i]);
		maxColor++;
		for (int i = 0; i < maxColor; i++)
			cnt[i] = pos[i] = 0;
		for (int i = 0; i < len; i++)
			cnt[color[i]]++;
		for (int i = 1; i < maxColor; i++)
			pos[i] = pos[i - 1] + cnt[i - 1];

		for (int i = 0; i < len; i++)
		{
			int npos = add(arr[i], -shift, len);
			nArr[pos[color[npos]]++] = npos;
		}

		nColor[nArr[0]] = 0;
		for (int i = 1; i < len; i++)
		{
			int a = nArr[i - 1];
			int b = nArr[i];
			if (color[a] == color[b] &&
				color[add(a, shift, len)] == color[add(b, shift, len)])
				nColor[b] = nColor[a];
			else
				nColor[b] = nColor[a] + 1;
		}
		for (int i = 0; i < len; i++)
		{
			arr[i] = nArr[i];
			color[i] = nColor[i];
		}
	}
}

void printString(int len, int position)
{
	int b = balance[len];
	if (b < 0)
	{
		for (int i = 0; i < -b; i++)
			putchar('(');
	}
	rotate(str, str + position, str + len);
	printf("%s", str);
	if (b > 0)
		for (int i = 0; i < b; i++)
			putchar(')');
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	scanf("%s", str);
	int len = strlen(str);

	balance[0] = 0;
	for (int i = 1; i <= 2 * len; i++)
		balance[i] = balance[i - 1] + (str[(i - 1) % len] == '(' ? 1 : -1);

	tree.build();
	buildSuffArr(len);
	
	int addBal = balance[len];
	for (int i = 0; i < len; i++)
	{
		bool ok = false;
		int position = arr[i];
		int val = tree.getMin(position, position + len);
		if (addBal > 0)
			ok = (val >= balance[position]);
		else
		{
			ok = (val - addBal >= balance[position]);
		}
		if (ok)
		{
			printString(len, position);
			return 0;
		}
	}

	return 0;
}