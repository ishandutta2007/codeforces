#include <bits/stdc++.h>
using namespace std;

const int Maxn = 5005;
int n, top, sta[Maxn], x[Maxn], y[Maxn];
bool check(int a, int b, int c)
{
	pair <int, int> tmp1 = make_pair(x[a] - x[b], y[a] - y[b]), tmp2 = make_pair(x[c] - x[b], y[c] - y[b]);
	return tmp1.first * (long long) tmp2.first + tmp1.second * (long long) tmp2.second > 0;
}
void work(int x, bool flag = false)
{
	if (top <= 1 || check(sta[top - 1], sta[top], x))
	{
		sta[++top] = x;
		return ;
	}
	int tmp = sta[top];
	top--, work(x);
	sta[++top] = tmp;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &x[i], &y[i]);
	for (int i = 1; i <= n; i++)
	{
		if (top <= 1) sta[++top] = i;
		else work(i, true);
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", sta[i]);
	return 0;
}