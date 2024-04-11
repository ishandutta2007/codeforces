#include <iostream>
#include <cstdio>
#include <set>
#include <queue>
#include <algorithm>

typedef long long int ll;
typedef std::pair<int, int> ii;
typedef std::pair<ii, ii> iv;

iv jobs[100100];
std::vector<int> used[100100];
ll anss[100100];

int main()
{
	int n, q;
	std::cin >> n >> q;
	for(int i=0;i<q;i++)
	{
		int t, k, d;
		//std::cin >> t >> k >> d;
		scanf("%i %i %i",&t,&k,&d);
		jobs[i]=iv(ii(t,i),ii(k, d));
	}
	std::sort(jobs, jobs+q);
	std::priority_queue<ii, std::vector<ii>, std::greater<ii> > hp;
	std::set<int> serv;
	for(int i=1;i<=n;i++)
		serv.insert(i);
	for(int i=0;i<q;i++)
	{
		while(!hp.empty() && hp.top().first<=jobs[i].first.first)
		{
			int on=hp.top().second;
			//std::cout << "finished " << on << '\n';
			hp.pop();
			for(int j=0;j<used[on].size();j++)
			{
				serv.insert(used[on][j]);
				//std::cout << "readding " << used[on][j] << '\n';
			}
			used[on].clear();
		}
		if(jobs[i].second.first>serv.size())
		{
			anss[jobs[i].first.second]=-1;
			continue;
		}
		ll ans=0;
		for(int j=0;j<jobs[i].second.first;j++)
		{
			int got=*(serv.begin());
			serv.erase(serv.begin());
			ans+=got;
			used[i].push_back(got);
		}
		anss[jobs[i].first.second]=ans;
		hp.push(ii(jobs[i].first.first+jobs[i].second.second,i));
		//std::cout << "starting on " << jobs[i].first.first << '\n';
		//std::cout << i << " will end on " << jobs[i].first.first+jobs[i].second.second << '\n';
		//std::cout << "dist is " << jobs[i].second.second << '\n';
	}
	for(int i=0;i<q;i++)
		//std::cout << anss[i] << '\n';
		printf("%lli\n",anss[i]);
}