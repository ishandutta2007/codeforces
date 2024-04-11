#include <bits/stdc++.h>

using namespace std;

#define re return
#define fi first
#define se second
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define fill(x,y) memset(x,y,sizeof(x))
#define mp make_pair
#define pb push_back
#define j0 j237849523
#define j1 j5435324
#define y0 y2543
#define y1 y548975
#define prev PREV
#define next NEXT
#define left LEFT
#define right RIGHT

typedef pair<int, int> ii;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef double D;

template<typename T> T abs (T x) { re x < 0 ? -x : x; }
template<typename T> T sqr (T x) { re x * x; }

const double pi = 2 * asin (1.0);

const int maxn = 200005;

int s[maxn], p[maxn];
int nxt[maxn];
int n, q;

int get(int a)
{
	if (p[a] != a) p[a] = get(p[a]);
	return p[a];
}

void unite(int a, int b)
{
	a = get(a);
	b = get(b);
	if (a == b) return;
	if (s[a] < s[b]) swap(a, b);
	p[b] = a;
	if (s[a] == s[b]) s[a]++;
}

int next(int a)
{
	if (get(nxt[a]) == get(a)) nxt[a] = next(nxt[a]);
	return nxt[a];
}

int main () {
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++)
	{
		p[i] = i;
		s[i] = 0;
		nxt[i] = i + 1;
	}
	p[n] = n;
	for (int i = 0; i < q; i++)
	{
		int t, x, y;
		scanf("%d%d%d", &t, &x, &y);
		x--, y--;
		if (t == 1)
		{
			unite(x, y);
		} else if (t == 2)
		{
			int cur = x;
			while (cur <= y)
			{
				unite(cur, x);
				cur = next(cur);
			}
		} else
		{
			if (get(x) == get(y)) printf("YES\n");
			else printf("NO\n");
		}
	}
}