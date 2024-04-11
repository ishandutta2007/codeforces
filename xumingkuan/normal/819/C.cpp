#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
int n[3], m[3], s[3];
long long N, M;
map<int, int> np, sp;
vector<pair<int, int> > spv;
vector<long long> vec;
long long ans;
void search(int p, long long v)
{
	if(p == spv.size())
	{
		ans++;
		return;
	}
	for(int i = 0; i <= spv[p].second && v <= N; i++, v *= spv[p].first)
		search(p + 1, v);
}
void solve()
{
	scanf("%d%d%d%d%d%d%d%d%d", n, n + 1, n + 2, m, m + 1, m + 2, s, s + 1, s + 2);
	N = (long long)n[0] * n[1] * n[2];
	M = (long long)m[0] * m[1] * m[2];
	np.clear();
	sp.clear();
	sp[2] = 1;
	for(int i = 2; i <= 1001; i++)
	{
		for(int j = 0; j < 3; j++)
			while(s[j] % i == 0)
				s[j] /= i, sp[i]++;
		for(int j = 0; j < 3; j++)
			while(n[j] % i == 0)
				n[j] /= i, np[i]++;
	}
	for(int j = 0; j < 3; j++)
		if(s[j] > 1)
			sp[s[j]]++;
	for(int j = 0; j < 3; j++)
		if(n[j] > 1)
			np[n[j]]++;
	vec.clear();
	ans = 0;
	spv.clear();
	for(map<int, int>::iterator it = sp.begin(); it != sp.end(); it++)
		spv.push_back(make_pair(it->first, it->second));
	for(map<int, int>::iterator it = np.begin(); it != np.end(); it++)
		if(it->second > sp[it->first])
		{
			long long tmp = 1;
			for(int i = 1; i <= sp[it->first] + 1; i++)
				tmp *= it->first;
			vec.push_back(tmp);
		}
	search(0, 1);
//	printf("a %I64d\n", ans);
	for(int i = 0; i < (1 << vec.size()); i++)
	{
		long long now = M;
		bool flag = true;
		for(int j = 0; j < (int)vec.size(); j++)
			if((i >> j) & 1)
				now /= vec[j], flag = !flag;
		if(flag)
			ans += now;
		else
			ans -= now;
//		printf("%d %I64d\n", i, now);
	}
	printf("%I64d\n", ans);
}

int main()
{
	int T;
	for(scanf("%d", &T); T; T--)
		solve();
	return 0;
}