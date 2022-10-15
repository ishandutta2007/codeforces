#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
#include <iostream>
#include <set>
#include <vector>
#include <bitset>

int n;
char s[501000];

std::map<int, int> mp;

int main()
{
	scanf("%d", &n);
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		scanf("%s", s);
		int len = strlen(s);
		int r = 0, l = 0;
		for(int j = 0; j < len; j++)
		{
			if(s[j] == '(') l++;
			if(s[j] == ')')
			{
				if(!l) r++;
				else l--;
			}
		}
		if(l && r) continue;
		int x = -l + r;
		if(mp[-x]) mp[-x]--, ans++;
		else mp[x]++; 
	}
	printf("%d\n", ans);
}