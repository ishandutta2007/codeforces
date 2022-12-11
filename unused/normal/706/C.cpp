#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int e[100005];
long long d[100005][2];
vector<string> vt;
char buf[100005];

const long long oo = 1e17;

int main()
{
	int n;
	scanf("%d", &n);
	vt.resize(n + 1);
	for (int i = 1; i <= n; i++) scanf("%d", &e[i]);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", buf);
		vt[i] = buf;
	}

	d[1][0] = 0; d[1][1] = e[1];
	for (int i = 2; i <= n; i++)
	{
		d[i][0] = d[i][1] = oo;

		if (!lexicographical_compare(vt[i].begin(), vt[i].end(), vt[i - 1].begin(), vt[i - 1].end()))
			d[i][0] = min(d[i][0], d[i - 1][0]);
		if (!lexicographical_compare(vt[i].rbegin(), vt[i].rend(), vt[i - 1].begin(), vt[i - 1].end()))
			d[i][1] = min(d[i][1], d[i - 1][0] + e[i]);
		if (!lexicographical_compare(vt[i].begin(), vt[i].end(), vt[i - 1].rbegin(), vt[i - 1].rend()))
			d[i][0] = min(d[i][0], d[i - 1][1]);
		if (!lexicographical_compare(vt[i].rbegin(), vt[i].rend(), vt[i - 1].rbegin(), vt[i - 1].rend()))
			d[i][1] = min(d[i][1], d[i - 1][1] + e[i]);
	}

	long long ans = min(d[n][0], d[n][1]);
	if (ans == oo) printf("-1");
	else printf("%lld", ans);
}