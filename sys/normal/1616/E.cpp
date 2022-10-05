#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 100005;
int Q, n, sum[Maxn];
string S, T;
long long ans, now;
set <int> Se[27];
int lowbit(int x)
{
	return x & -x;
}
void erase(int x)
{
	Se[S[x] - 'a'].erase(x);
	x++;
	for (int i = x; i <= n; i += lowbit(i))
		sum[i]++;
}
int ask(int x)
{
	int res = 0;
	x++;
	for (int i = x; i; i -= lowbit(i))
		res += sum[i];
	return res;
}
pair <long long, int> get_pos(int pos, char ch)
{
	int mini = 0x3f3f3f3f;
	for (int i = 0; i <= ch - 'a'; i++)
	{
		set <int> :: iterator it = Se[i].lower_bound(pos);
		if (it != Se[i].end()) mini = min(mini, *it);
	}
	if (mini == 0x3f3f3f3f)
		return make_pair(0x3f3f3f3f3f3f3f3fLL, 0);
	return make_pair(mini - pos - (ask(mini) - ask(pos - 1)), mini);
}
int main()
{
	scanf("%d", &Q);
	while (Q--)
	{
		scanf("%d", &n);
		cin >> S >> T;
		for (int i = 0; i < 26; i++) Se[i].clear();
		for (int i = 0; i < n; i++)
			Se[S[i] - 'a'].insert(i);
		int pnt = 0;
		ans = 0x3f3f3f3f3f3f3f3fLL, now = 0;
		memset(sum, 0, sizeof(int[n + 1]));
		for (int i = 0; i < n; i++)
		{
			while (ask(pnt) - ask(pnt - 1)) pnt++;
			if (S[pnt] < T[i])
			{
				ans = min(ans, now);
				break;
			}
			ans = min(ans, now + get_pos(pnt, T[i] - 1).first);
			pair <long long, int> equ = get_pos(pnt, T[i]);
			if (equ.first == 0x3f3f3f3f3f3f3f3fLL) break;
			now += equ.first;
			erase(equ.second);
		}
		printf("%lld\n", ans == 0x3f3f3f3f3f3f3f3fLL ? -1 : ans);
	}
	return 0;
}