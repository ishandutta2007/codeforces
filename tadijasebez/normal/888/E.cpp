#include <stdio.h>
#include <set>
#include <vector>
using namespace std;
set<int> Set,Set2;
set<int>::iterator it;
int a[50];
vector<int> tmp;
vector<int> sol1,sol2;
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int n,i,j,m;
	Set.insert(0);
	scanf("%i %i",&n,&m);
	for(i=1;i<=n/2;i++)
	{
		scanf("%i",&a[i]);
		for(it=Set.begin();it!=Set.end();it++)
		{
			tmp.push_back(((*it)+a[i])%m);
		}
		for(j=0;j<tmp.size();j++)
		{
			if(!Set.count(tmp[j])) Set.insert(tmp[j]);
		}
		tmp.clear();
	}
	//int sol=*Set.rbegin();
	Set2.insert(0);
	for(i=n/2+1;i<=n;i++)
	{
		scanf("%i",&a[i]);
		for(it=Set2.begin();it!=Set2.end();it++)
		{
			tmp.push_back(((*it)+a[i])%m);
		}
		for(j=0;j<tmp.size();j++)
		{
			if(!Set2.count(tmp[j])) Set2.insert(tmp[j]);
		}
		tmp.clear();
	}
	for(it=Set.begin();it!=Set.end();it++) sol1.push_back(*it);
	for(it=Set2.begin();it!=Set2.end();it++) sol2.push_back(*it);
	int sol=0;
	for(i=0;i<sol1.size();i++)
	{
		int top=sol2.size()-1,bot=0,mid,ans=0;
		int taj=m-sol1[i];
		while(top>=bot)
		{
			mid=top+bot>>1;
			if(sol2[mid]<taj) ans=sol2[mid],bot=mid+1;
			else top=mid-1;
		}
		sol=max(sol,sol1[i]+ans);
	}
	printf("%i\n",sol);
	return 0;
}