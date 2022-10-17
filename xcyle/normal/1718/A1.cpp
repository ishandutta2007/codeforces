#include <bits/stdc++.h>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define ru(i, l, r) for (int i = (l); i <= (r); i++)
#define rd(i, r, l) for (int i = (r); i >= (l); i--)
#define mid ((l + r) >> 1)
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define maxn 100005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn];
map<int, int> las;
void solve()
{
	n = read();
	ru(i, 1, n) a[i] = read() ^ a[i - 1];
	int sum = 0, ans = n; las.clear(); las[0] = 1;
	ru(i, 1, n)
	{
		if(las[a[i]])
		{
			ans--;
			las.clear();
		}
		las[a[i]] = 1;
	} 
	printf("%d\n", ans);
}
int main()
{
	int T = read();
	while(T--) solve();
	return 0;
}