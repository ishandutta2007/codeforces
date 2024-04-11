#include <iostream>
#include <cstdio>
#define maxn 300005
using namespace std;
int n, a[maxn], b[maxn];
int t[maxn * 60], ch[maxn * 60][2], tot, siz[maxn * 60];
void insert(int x)
{
	int now = 0;
	for (int i = 30; i >= 0; i--)
	{
		int k = ((x >> i) & 1);
		if(!ch[now][k]) ch[now][k] = ++tot;
		now = ch[now][k];
		siz[now]++;
	}
}
int que(int x)
{
	int res = 0;
	int now = 0;
	for (int i = 30; i >= 0; i--)
	{
		int k = ((x >> i) & 1);
		if(ch[now][k] && siz[ch[now][k]]) now = ch[now][k];
		else 
		{
			now = ch[now][k ^ 1];
			res += (1 << i);
		}
		siz[now]--;
	}
	return res;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
	for (int i = 1; i <= n; i++) insert(b[i]);
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", que(a[i]));
	}
	return 0;
}