#include <cstdio>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

typedef std::pair<int, int> ii;

int n, m;

int a[200200];


std::set<int> diffs[2], lm[2];
std::vector<int> change_this;

int main()
{
	std::cin >> n >> m;
	m=std::min(m, 2*int(1e5)+10);
	for(int i=1;i<=m;i++)
		lm[i%2].insert(i);
	for(int i=0;i<n;i++)
	{
		scanf("%i",a+i);
		int ind=a[i]%2;
		if(diffs[ind].find(a[i])!=diffs[ind].end() || diffs[ind].size()>=n/2)
		{
			change_this.push_back(i);
		}
		else
		{
			diffs[ind].insert(a[i]);
			if(a[i]<=m)
				lm[ind].erase(a[i]);
		}
		
	}
	int odd=diffs[1].size();
	int even=diffs[0].size();

	int ans=0;
	if(n/2-odd>lm[1].size() || n/2-even>lm[0].size() || n%2!=0)
	{
		std::cout << -1 << '\n';
		return 0;
	}

	int g_ind=0;

	while(odd<n/2)
	{
		int num=*(lm[1].begin());
		lm[1].erase(lm[1].begin());

		int on=change_this[g_ind++];
		a[on]=num;

		odd++;
		ans++;
	}

	while(even<n/2)
	{
		int num=*(lm[0].begin());
		lm[0].erase(lm[0].begin());

		int on=change_this[g_ind++];
		a[on]=num;

		even++;
		ans++;
	}

	std::cout << ans << '\n';
	for(int i=0;i<n;i++)
	{
		if(i)
			printf(" ");
		printf("%i",a[i]);
	}
	std::cout << '\n';

}