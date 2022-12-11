#include <bits/stdc++.h>
using namespace std;

char dat[200005];
set<pair<int, int>> s1;
set<int> s2;
set<int> s3;

int main()
{
	int n;
	scanf("%d%s", &n, dat);
	for (int i = 0; i < n; i++)
	{
		if (dat[i] == 'D')
		{
			s1.emplace(i, 0);
			s2.insert(i);
		}
		else
		{
			s1.emplace(i, 1);
			s3.insert(i);
		}
	}

	auto itr = s1.begin();
	while (s2.empty() == false && s3.empty() == false)
	{
		if (itr->second == 0)
		{
			auto itr2 = s3.lower_bound(itr->first);
			if (itr2 == s3.end()) itr2 = s3.begin();
			s1.erase({ *itr2, 1 });
			s3.erase(itr2);
		}
		else
		{
			auto itr2 = s2.lower_bound(itr->first);
			if (itr2 == s2.end()) itr2 = s2.begin();
			s1.erase({ *itr2, 0 });
			s2.erase(itr2);
		}

		if (++itr == s1.end()) itr = s1.begin();
	}

	if (s2.empty()) printf("R\n");
	else printf("D\n");
}