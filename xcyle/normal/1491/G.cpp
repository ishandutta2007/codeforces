#include <iostream>
#include <cstdio>
#include <vector>
#define maxn 200005
using namespace std;
int n, p[maxn], pt[maxn], st[maxn], vis[maxn];
vector<pair<int, int> > ans;
inline void foo(int x, int y) {ans.push_back(make_pair(x, y)), swap(p[x], p[y]), swap(pt[p[x]], pt[p[y]]), st[p[x]] ^= 1, st[p[y]] ^= 1;}
void work(int x)
{
	if(p[p[x]] == x) {foo(x, p[x]); return;}
	if(!st[p[p[x]]]) foo(x, p[x]), work(x);
	else work(p[x]);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &p[i]), pt[p[i]] = i;
	int cnt = 1;
	for (int i = p[1]; i != 1; i = p[i]) cnt++;
	if(cnt == n)
	{
		int tmp = p[1];
		foo(1, tmp), foo(tmp, p[1]), work(tmp);
	}
	else
	{
		int las = -1;
		for (int i = 1; i <= n; i++) if(!vis[i])
		{
			vis[i] = 1; for (int j = p[i]; j != i; j = p[j]) vis[j] = 1;
			if(las != -1) foo(las, i), work(i), las = -1;
			else las = i;
		}
		if(las != -1) foo(1, las), work(1);
	}
	printf("%d\n", ans.size()); for (auto x: ans) printf("%d %d\n", x.first, x.second);
	return 0;
}