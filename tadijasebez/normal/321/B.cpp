#include <stdio.h>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
vector<int> def;
vector<int> atk;
int card[105];
bool Compare(int a, int b)
{
	return a>b;
}
int Count[8050];
int main()
{
	int n,m,i,x,j;
	char c[5];
	scanf("%i %i",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%s %i",&c,&x);
		if(c[0]=='D') def.push_back(x);
		else atk.push_back(x);
	}
	for(i=0;i<m;i++) scanf("%i",&card[i]);
	multiset<int> Set;
	for(i=0;i<m;i++)
	{
		if(Count[card[i]]==0)
			Set.insert(card[i]);
		Count[card[i]]++;
	}
	int sol=0;
	sort(def.begin(),def.end());
	sort(atk.begin(),atk.end(),Compare);
	multiset<int>::iterator it;
	bool clear=true;
	//printf("1:\n");
	for(i=0;i<def.size();i++)
	{
		it=Set.upper_bound(def[i]);
		if(it!=Set.end())
		{
			//printf("DEF:%i %i\n",def[i],*it);
			Count[*it]--;
			if(Count[*it]<1)
				Set.erase(*it);
		}
		else clear=false;
	}
	for(i=0;i<atk.size();i++)
	{
		if(!Set.empty())
		{
			it=Set.end();
			it--;
			if(*it>=atk[i])
			{
				//printf("ATK:%i %i\n",atk[i],*it);
				sol+=*it-atk[i];
				Count[*it]--;
				if(Count[*it]<1)
					Set.erase(*it);
				//printf(":D");
			}
			else clear=false;
		}
		else clear=false;
	}
	if(clear)
	{
		for(it=Set.begin();it!=Set.end();it++)
		{
			for(j=0;j<Count[*it];j++)
			{
				//printf("DIR:%i\n",*it);
				sol+=*it;
			}
		}
	}
	//printf("\n2:\n");
	Set.clear();
	for(i=0;i<m;i++) Count[card[i]]=0;
	for(i=0;i<m;i++)
	{
		if(Count[card[i]]==0)
			Set.insert(card[i]);
		Count[card[i]]++;
	}
	int sol1=0;
	sort(atk.begin(),atk.end());
	for(i=0;i<atk.size();i++)
	{
		if(!Set.empty())
		{
			it=Set.end();
			it--;
			if(*it>=atk[i])
			{
				//printf("ATK:%i %i\n",atk[i],*it);
				sol1+=*it-atk[i];
				Count[*it]--;
				if(Count[*it]<1)
					Set.erase(*it);
			}
		}
	}
	if(sol1>sol) sol=sol1;
	printf("%i\n",sol);
	return 0;
}