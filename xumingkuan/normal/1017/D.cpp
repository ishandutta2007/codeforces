#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 4100;
const int MAXQ = 505050;
int n, m, q;
int LOG2[MAXN];
char s[15];
int w[15];
bool same[15];
int num[MAXN];
vector<pair<int, int> > qr[MAXN];//k, id
int add[MAXQ];
int ans[MAXQ];
void inputquery(int id)
{
	scanf("%s", s);
	int t = 0;
	for(int i = 0; i < n; i++)
		t = t * 2 + s[i] - '0';
	int k;
	scanf("%d", &k);
	qr[t].push_back(make_pair(k, id));
}
int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for(int i = n - 1; i >= 0; i--)
		scanf("%d", &w[i]);
	memset(num, 0, sizeof(num));
	for(int i = 1; i <= m; i++)
	{
		scanf("%s", s);
		int t = 0;
		for(int j = 0; j < n; j++)
			t = t * 2 + s[j] - '0';
		num[t]++;
	}
	for(int i = 1; i <= q; i++)
		inputquery(i);
	for(int i = 0; i < n; i++)
		LOG2[1 << i] = i;
	for(int i = 0; i < (1 << n); i++)
		if(!qr[i].empty())
		{
			sort(qr[i].begin(), qr[i].end());
			for(int j = 0; j < (int)qr[i].size(); j++)
				add[j] = 0;
			int now = 0;
			for(int j = 0; j < n; j++)
				if((same[j] = !((i >> j) & 1)))
					now += w[j];
			add[lower_bound(qr[i].begin(), qr[i].end(), make_pair(now, 0)) - qr[i].begin()] += num[0];
			for(int j = 1; j < (1 << n); j++)
			{
				int lb = LOG2[j & (-j)];
				for(int k = 0; k <= lb; k++)
					if((same[k] = !same[k]))
						now += w[k];
					else
						now -= w[k];
				add[lower_bound(qr[i].begin(), qr[i].end(), make_pair(now, 0)) - qr[i].begin()] += num[j];
			}
			for(int j = 0; j < (int)qr[i].size(); j++)
			{
				if(j > 0)
					add[j] += add[j - 1];
				ans[qr[i][j].second] = add[j];
			}
		}
	for(int i = 1; i <= q; i++)
		printf("%d\n", ans[i]);
	return 0;
}