#include <cstdio>
#include <set>

const int ms = 3001000;

char str[ms];
char ans[ms];
int to = 0;

int main()
{
	int n;
	scanf("%i", &n);
	std::set<int> pos;
	for(int i = 0; i < ms; i++)
		pos.insert(i);
	while(n--)
	{
		scanf(" %s", str);
		int on = 0;
		while(str[on] != 0)
			on++;
		int k;
		scanf("%i", &k);
		while(k--)
		{
			int start;
			scanf("%i", &start);
			start--;
			auto it = pos.lower_bound(start);
			while(it != pos.end() && *it < start + on)
			{
				ans[*it] = str[*it - start];
				to = std::max(to, *it);
				pos.erase(it);
				it = pos.lower_bound(start);
			}
		}
		for(int i = 0; i < on; i++)
			str[i] = 0;
	}
	for(int i = 0; i <= to; i++)
	{
		if(ans[i] == 0)
			ans[i] = 'a';
	}
	printf("%s\n", ans);
}