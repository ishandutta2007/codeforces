#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int k, n, m, a[Maxn], opt[Maxn], tot;
vector <pair<double, int> > ans, Ve[Maxn];
vector <int> Out[4];
int maxi[Maxn], pos[Maxn];
int main()
{
	scanf("%d%d%d", &k, &n, &m);
	for (int i = 1; i <= k; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		scanf("%d%d%d", &opt[i], &x, &y);
		if (opt[i] == 1)
		{
			if (y > maxi[x]) maxi[x] = y, pos[x] = i;
		}
		else if (opt[i] == 2)
			Ve[x].push_back(make_pair(y, i));
		else ans.push_back(make_pair(y, i));
	}
	for (int i = 1; i <= k; i++)
		if (maxi[i]) Ve[i].push_back(make_pair(maxi[i] - a[i], pos[i]));
	for (int i = 1; i <= k; i++)
		sort(Ve[i].begin(), Ve[i].end());
	for (int i = 1; i <= k; i++)
	{
		long long tmp = a[i];
		for (vector <pair <double, int> > :: reverse_iterator it = Ve[i].rbegin(); it != Ve[i].rend(); it++)
			ans.push_back(make_pair(it -> first / tmp + 1, it -> second)), tmp += it -> first;
	}
	sort(ans.begin(), ans.end());
	for (vector <pair <double, int> > :: reverse_iterator it = ans.rbegin(); it != ans.rend(); it++)
		if (it -> first >= 1) tot++;
	tot = min(tot, m);
	printf("%d\n", tot);
	for (vector <pair <double, int> > :: reverse_iterator it = ans.rbegin(); it != ans.rend(); it++)
		if (tot)
		{
			tot--;
			Out[opt[it -> second]].push_back(it -> second);
		}
	for (int i = 1; i <= 3; i++)
		for (vector <int> :: iterator it = Out[i].begin(); it != Out[i].end(); it++)
			printf("%d ", *it);
	return 0;
}