#include<cstring>
#include<cstdio>
#include<algorithm>
#include<list>
using namespace std;
int n, m, lx, ly;
pair<int, int> a[222222];
list<pair<int, int> > valid, valid1, par;
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++) scanf("%d%d", &a[i].first, &a[i].second);
	sort(a + 1, a + 1 + m);
	lx = 0;
	valid.push_back(make_pair(1, 1));
	for(int i = 1; i <= m; )
	{
		if(valid.empty()) break;
		if(lx + 1 != a[i].first)
		{
			lx = valid.begin()->first;
			valid.clear();
			valid.push_back(make_pair(lx, n));
		}
		lx = a[i].first;
		par.clear();
		ly = 0;
		for(; i <= m and a[i].first == lx; i++)
		{
			if(ly + 1 <= a[i].second - 1)
				par.push_back(make_pair(ly + 1, a[i].second - 1));
			ly = a[i].second;
		}
		if(ly + 1 <= n) par.push_back(make_pair(ly + 1, n));
		valid1.clear();
		//printf("%d %d %d %d\n", valid.begin()->first, valid.begin()->second, par.begin()->first, par.begin()->second);
		for(list<pair<int, int> >::iterator itr1 = valid.begin(), itr2 = par.begin(); itr1 != valid.end() and itr2 != par.end(); )
		{
			if(itr1->second < itr2->first) itr1++;
			else if(itr2->second < itr1->first) itr2++;
			else
			{
				valid1.push_back(make_pair(max(itr1->first, itr2->first), itr2->second));
				itr2++;
			}
		}
		valid = valid1;
		//printf("lx = %d\n", lx);
		//for(list<pair<int, int> >::iterator itr = valid.begin(); itr != valid.end(); itr++) printf("(%d, %d)\n", itr->first, itr->second);
	}
	if(!valid.empty() and (lx != n or valid.back().second == n)) printf("%d\n", n * 2 - 2); else printf("-1\n");
	fclose(stdin);
	return 0;
}