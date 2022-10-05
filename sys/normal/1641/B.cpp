#include <bits/stdc++.h>
using namespace std;

const int Maxn = 250005;
int T, n, ct, ans_ct, tot, a[Maxn], b[Maxn], c[Maxn], cnt[Maxn];
bool vis[Maxn];
pair <int, int> ans[Maxn];
vector <int> res;
map <int, int> Ma;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		ans_ct = tot = ct = 0;
		res.clear();
		Ma.clear();
		scanf("%d", &n);
		memset(vis, 0, sizeof(bool[n + 1]));
		memset(cnt, 0, sizeof(int[n + 1]));
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]), b[i] = a[i];
		sort(b + 1, b + 1 + n);
		ct = unique(b + 1, b + 1 + n) - b - 1;
		for (int i = 1; i <= n; i++)
			a[i] = lower_bound(b + 1, b + 1 + ct, a[i]) - b, cnt[a[i]]++;
		for (int i = 1; i <= ct; i++)
			if (cnt[i] & 1)
			{
				puts("-1");
				goto END;
			}
		for (int i = 1; i <= n; i++)
			if (!vis[i])
				for (int j = i + 1; j <= n; j++)
					if (a[i] == a[j])
					{
						for (int k = i + 1; k < j; k++)
							ans[++ans_ct] = make_pair(2 * tot + k - i - 1 + j, a[k]);
						tot += j - i - 1;
						res.push_back(j - i);
						for (int k = j; k > i; k--)
							c[k] = a[i + j - k + 1];
						for (int k = j; k > i; k--) a[k] = c[k];
						i++;
						break;
					}
		printf("%d\n", ans_ct);
		for (int i = 1; i <= ans_ct; i++)
			printf("%d %d\n", ans[i].first, b[ans[i].second]);
		printf("%d\n", (int) res.size());
		for (auto u : res) printf("%d ", u * 2);
		puts("");
		END:;
	}
	return 0;
}