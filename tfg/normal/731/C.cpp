#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>

typedef long long int ll;
typedef std::pair<int, int> ii;

int n,m,k;

std::vector<int> v[300300];
int c[300300];

int cur_max;
int c_max;

int step[300300];
int c_step[300300];
int v_step[300300];
int c_num[300300];
int cur_step=0;

bool visit[300300];

void dfs1(int on)
{
	if(v_step[on]==cur_step || visit[on]) return;
	v_step[on]=cur_step;
	if(c_step[c[on]]!=cur_step)
	{
		c_step[c[on]]=cur_step;
		c_num[c[on]]=1;
	}
	else
	{
		c_num[c[on]]++;
	}
	if(c_num[c[on]]>cur_max)
	{
		c_max=c[on];
		cur_max=c_num[c[on]];
	}
	for(int i=0;i<v[on].size();i++)
	{
		dfs1(v[on][i]);
	}


}

int dfs2(int on)
{
	if(visit[on]) return 0;
	int ans=(c[on]!=c_max?1:0);
	visit[on]=true;
	for(int i=0;i<v[on].size();i++)
		ans+=dfs2(v[on][i]);
	return ans;
}

int main()
{
	std::cin >> n >> m >> k;
	for(int i=0;i<n;i++)
		std::cin >> c[i];
	for(int i=0;i<m;i++)
	{
		int t1,t2;std::cin >> t1 >> t2;
		t1--;t2--;
		v[t1].push_back(t2);
		v[t2].push_back(t1);
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		cur_step++;
		cur_max=0;
		dfs1(i);
		//std::cout << "c_max is " << c_max << ", freq " << cur_max << ", ans "<< ans << std::endl;
		ans+=dfs2(i);
	}
	std::cout << ans << std::endl;
}