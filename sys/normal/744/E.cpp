#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005, p1 = 1e9 + 7, p2 = 1e9 + 9, seed1 = 29, seed2 = 31;
int n, ct, cnt, ans, deg[Maxn], head[Maxn];
long long P1[Maxn], P2[Maxn];
vector <int> id[Maxn];
vector <pair <long long, long long> > Hash[Maxn];
string str[Maxn];
queue <int> Qu;
struct edg
{
	int nxt, to;
} edge[65 * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
	deg[y]++;
}
pair <long long, long long> get_hash(int x, int lt, int rt)
{
	lt++, rt++;
	return make_pair((Hash[x][rt].first - Hash[x][lt - 1].first * P1[rt - lt + 1] % p1 + p1) % p1, (Hash[x][rt].second - Hash[x][lt - 1].second * P2[rt - lt + 1] % p2 + p2) % p2);
}
int main()
{
	P1[0] = P2[0] = 1;
	for (int i = 1; i <= 100000; i++)
		P1[i] = P1[i - 1] * seed1 % p1, P2[i] = P2[i - 1] * seed2 % p2;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		cin >> str[i];
		int siz = str[i].size();
		Hash[i].resize(siz + 1);
		id[i].resize(siz);
		for (int j = 1; j <= siz; j++)
		{
			id[i][j - 1] = ++ct;
			Hash[i][j].first = (Hash[i][j - 1].first * seed1 + str[i][j - 1] - 'a' + 1) % p1;
			Hash[i][j].second = (Hash[i][j - 1].second * seed2 + str[i][j - 1] - 'a' + 1) % p2;
		}
	}
	int rt = 1;
	for (int lt = 1; lt <= n; lt++, ans += max(0, rt - lt))
		for (rt = max(lt, rt); rt <= n; rt++)
		{
			cnt = 0;
			memset(head, 0, sizeof(int[ct + 1]));
			memset(deg, 0, sizeof(int[ct + 1]));
			for (int i = lt; i <= rt; i++)
			{
				int siz_i = str[i].size();
				for (int j = lt; j <= rt; j++)
				{
					int siz_j = str[j].size();
					for (int k = 0; k < siz_i; k++)
					{
						if (!k && str[i] == str[j]) continue;
						int u = !k ? ct : id[i][k - 1], pos, v;
						pos = k + siz_j - 1;
						if (pos == siz_i - 1) v = ct;
						else if (pos > siz_i - 1) v = id[j][siz_i - k - 1];
						else v = id[i][pos];
						if (get_hash(i, k, min(pos, siz_i - 1)) == get_hash(j, 0, min(siz_i - k - 1, siz_j - 1)))
							add(u, v);
					}
				}
			}
			for (int i = 1; i <= ct; i++)
				if (!deg[i]) Qu.push(i);
			while (!Qu.empty())
			{
				int u = Qu.front();
				Qu.pop();
				for (int i = head[u]; i; i = edge[i].nxt)
				{
					int to = edge[i].to;
					deg[to]--;
					if (!deg[to]) Qu.push(to);
				}
			}
			bool flag = false;
			for (int i = 1; i <= ct; i++)
				if (deg[i]) flag = true;
			ans += !flag;
			if (flag) break;
		}
	printf("%d", ans);
	return 0;
}