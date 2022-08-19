#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
#define mp make_pair
set<pii> s;
int n;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	int x;
	scanf("%d", &x);
	s.insert(mp(x, 0));
	for (int i = 1; i < n; i++)
	{
		scanf("%d", &x);
		pii tmp = mp(x, i);
		auto it = s.lower_bound(tmp);
		if (it == s.end())
		{
			it--;
		}
		else if (it == s.begin())
		{
		}
		else
		{
			auto it2 = it;
			it2--;
			if (it2->second > it->second)
				it = it2;			
		}
		printf("%d ", it->first);
		s.insert(tmp);
	}
	printf("\n");

	return 0;
}