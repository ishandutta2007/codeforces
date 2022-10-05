#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n, nxt[Maxn], sum[Maxn], pre[Maxn];
string str;
long long ans;
unordered_map <int, int> cnt;
int main()
{
	cin >> str;
	n = str.size();
	int bloc = sqrt(n / log2(n));
	for (int i = 1; i <= bloc; i++)
	{
		cnt.clear();
		sum[0] = 0;
		cnt[0] = 1;
		for (int j = 1; j <= n; j++)
		{
			sum[j] = sum[j - 1] + str[j - 1] - '0';
			ans += cnt[i * sum[j] - j];
			cnt[i * sum[j] - j]++;
		}
	}
	int las = 0;
	for (int i = 0; i < n; i++)
		if (str[i] == '1') nxt[las] = i + 1, pre[i + 1] = las, las = i + 1;
	nxt[las] = n + 1, pre[n + 1] = las;
	for(int i = 1; i <= n; i++)
		if(str[i - 1] == '1')
			for(int j = i, tmp_cnt = 1; j != n + 1 && tmp_cnt <= n / bloc + 10; j = nxt[j], tmp_cnt++)
			{
				int mini = j - i + 1, maxi = (nxt[j] - 1) - (pre[i] + 1) + 1;
				for(int t = max(bloc + 1, mini / tmp_cnt + (bool)(mini % tmp_cnt)); t <= maxi / tmp_cnt; t++)
					ans += min(min(t * tmp_cnt - mini + 1, maxi - t * tmp_cnt + 1), min(i - pre[i], nxt[j] - j));
			}
	printf("%lld", ans);
	return 0;
}