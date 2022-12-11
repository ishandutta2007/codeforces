#include "bits/stdc++.h"
using namespace std;

map<string, int> map1=
{
	{"S", 0},
	{"M", 1},
	{"L", 2},
	{"XL", 3},
	{"XXL", 4},
	{"XXXL", 5},
};

map<int, string> map2=
{
	{0,"S"},
	{1,"M"},
	{2,"L"},
	{3,"XL"},
	{4,"XXL"},
	{5,"XXXL"},
};

int num[6];
vector<int> p1[6], p2[5];
int ans[100005];

int main()
{
	for (int i = 0; i < 6; i++) scanf("%d",&num[i]);
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		char s1[20];
		scanf("%s",s1);
		if (char *p = strchr(s1, ','))
		{
			*p = 0;
			p2[map1[s1]].push_back(i);
		}
		else
		{
			p1[map1[s1]].push_back(i);
		}
	}

	for (int i = 0; i < 6; i++)
	{
		if (p1[i].size() > num[i])
		{
			printf("NO");
			return 0;
		}

		for (int t : p1[i])
		{
			ans[t] = i;
		}

		num[i] -= p1[i].size();

		if (i == 5) break;

		while (num[i] && p2[i].empty() == false)
		{
			ans[p2[i].back()] = i;
			num[i]--;
			p2[i].pop_back();
		}

		p1[i+1].insert(p1[i+1].end(),p2[i].begin(),p2[i].end());
	}

	printf("YES\n");
	for (int i = 0; i < n; i++) printf("%s\n", map2[ans[i]].c_str());
}