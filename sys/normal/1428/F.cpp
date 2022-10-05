#include <bits/stdc++.h>
using namespace std;

const int Maxn = 500005;
int n, top, cnt, pos;
long long sum[Maxn], tot, ans;
string str;
int lowbit(int x)
{
	return x & -x;
}
void add(int x, int y)
{
	for (int i = x; i <= n; i += lowbit(i))
		sum[i] += y;
}
long long ask(int x)
{
	long long tmp = 0;
	for (int i = x; i; i -= lowbit(i))
		tmp += sum[i];
	return tmp;
}
int main()
{
	scanf("%d", &n);
	cin >> str;
	for (int i = 1; i <= n; i++)
	{
		if (str[i - 1] == '1')
		{
			cnt++;
			tot -= ask(cnt);
			add(cnt + 1, ask(cnt) - pos), add(cnt, pos - ask(cnt));
			add(1, 1), add(cnt + 1, -1);
			tot += cnt - 1 + ask(cnt);
		}
		else cnt = 0, pos = i;
		ans += tot;
	}
	printf("%lld", ans);
	return 0;
}