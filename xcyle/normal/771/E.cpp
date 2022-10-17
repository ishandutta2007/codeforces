#include <iostream>
#include <cstdio>
#include <unordered_map>
#define ll long long
#define maxn 1000005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, a[2][maxn], las[4][maxn];
unordered_map<ll, int> t, f;
inline void work(int tp)
{
	t.clear(); t[0] = 1; ll sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += (tp & 1) * a[0][i] + (tp >> 1) * a[1][i];
		las[tp][i] = max(las[tp][i - 1], t[sum]), t[sum] = i + 1;
	}
}
inline int calc(int x, int y)
{
	if(x < 0 || y < 0) return -1;
	if(!x && !y) return 0;
	int &ans = f[(ll)x * (n + 1) + y];
	if(ans) return ans;
	ans = calc(las[3][min(x, y)] - 1, las[3][min(x, y)] - 1) + 1;
	if(las[1][x] < las[2][y]) ans = max(ans, calc(x, las[2][y] - 1) + 1);
	else ans = max(ans, calc(las[1][x] - 1, y) + 1);
	return ans;
}
int main()
{
	n = read();
	for (int i = 1; i <= n; i++) a[0][i] = read();
	for (int i = 1; i <= n; i++) a[1][i] = read();
	work(1), work(2), work(3);
	printf("%d\n", calc(n, n));
	return 0;
}