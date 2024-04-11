#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int N=1000050;
const int L=20;
vector<int> a[L+1];
vector<int> ans,sol;
bool was;
int abs(int x){ return x>0?x:-x;}
void work(int lvl)
{
	if(lvl==L || a[lvl].empty())
	{
		if(!was || sol.size()>ans.size()) sol=ans,was=1;
		return;
	}
	sort(a[lvl].begin(),a[lvl].end());
	a[lvl].erase(unique(a[lvl].begin(),a[lvl].end()),a[lvl].end());
	int i;
	bool ok=1;
	for(i=0;i<a[lvl].size();i++)
	{
		if((abs(a[lvl][i])>>lvl)&1) ok=0;
	}
	if(ok)
	{
		a[lvl+1].clear();
		for(i=0;i<a[lvl].size();i++) a[lvl+1].push_back(a[lvl][i]);
		work(lvl+1);
	}
	else
	{
		ans.push_back(1<<lvl);
		a[lvl+1].clear();
		for(i=0;i<a[lvl].size();i++)
		{
			int tmp=abs(a[lvl][i]);
			int f=abs(a[lvl][i])/a[lvl][i];
			if((tmp>>lvl)&1) tmp-=f*(1<<lvl);
			if(tmp) a[lvl+1].push_back(f*tmp);
		}
		work(lvl+1);
		ans.pop_back();
		ans.push_back(-(1<<lvl));
		a[lvl+1].clear();
		for(i=0;i<a[lvl].size();i++)
		{
			int tmp=abs(a[lvl][i]);
			int f=abs(a[lvl][i])/a[lvl][i];
			if((tmp>>lvl)&1) tmp+=f*(1<<lvl);
			if(tmp) a[lvl+1].push_back(f*tmp);
		}
		work(lvl+1);
		ans.pop_back();
	}
}
int main()
{
	int x,n,i;
	scanf("%i",&n);
	while(n--)
	{
		scanf("%i",&x);
		if(x) a[0].push_back(x);
	}
	work(0);
	printf("%i\n",sol.size());
	for(i=0;i<sol.size();i++) printf("%i ",sol[i]);
	return 0;
}