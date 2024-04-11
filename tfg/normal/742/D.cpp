#include <cstdio>
#include <utility>
#include <algorithm>
#include <vector>
#include <iostream>

typedef std::pair<int, int> ii;

int n, m, maxw;
int w[1010], b[1010];

int par[1010], visit[1010], ind[1010];

int get_par(int x)
{
	if(x==par[x]) return x;
	return par[x]=get_par(par[x]);
}

void make_union(int a, int b)
{
	a=get_par(a);
	b=get_par(b);
	par[b]=a;
}

std::vector<ii> groups[1010];
int size=0;

int memo[1010][1010];
bool visit1[1010][1010];

int dp(int on, int we)
{
	int &ans=memo[on][we];
	if(on>=size) return 0;
	if(visit1[on][we]) return ans;
	visit1[on][we]=true;
	ans=dp(on+1,we);
	int totalw=0;
	int totalb=0;
	for(int i=0;i<groups[on].size();i++)
	{
		totalw+=groups[on][i].first;
		totalb+=groups[on][i].second;
		if(we+groups[on][i].first<=maxw)
			ans=std::max(ans, groups[on][i].second+dp(on+1,we+groups[on][i].first));
		//else
		//	std::cout << we+groups[on][i].first << " on " << on << ',' << i << '\n';
	}
	if(we+totalw<=maxw)
		ans=std::max(ans, totalb+dp(on+1,we+totalw));
	//std::cout << "on dp(" << on << ',' << we << "), ans=" << ans << '\n';
	return ans;
}

int main()
{
	scanf("%i %i %i", &n, &m, &maxw);
	for(int i=0;i<n;i++)
		scanf("%i",w+i);
	for(int i=0;i<n;i++)
		scanf("%i",b+i);
	for(int i=0;i<n;i++)
	{
		par[i]=i;
	}
	for(int i=0;i<m;i++)
	{
		int t1,t2;
		scanf("%i %i", &t1, &t2);
		t1--;t2--;
		make_union(t1,t2);
	}
	for(int i=0;i<n;i++)
	{
		int cur=get_par(i);
		if(!visit[cur])
			ind[cur]=size++;
		visit[cur]=true;
		groups[ind[cur]].push_back(ii(w[i],b[i]));
		//std::cout << i << ": on group " << size << ", par is " << cur << '\n';
	}
	std::cout << dp(0,0) << '\n';
}