#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=500050;
map<int,int> id;
set<int> emp,sell,buy;
set<int>::iterator it;
bool ok=1;
const int mod=1e9+7;
int NextBuy(int x)
{
	it=buy.lower_bound(x);
	if(it==buy.end()) return -1;
	else return *it;
}
int PrevSell(int x)
{
	it=sell.upper_bound(x);
	if(it==sell.begin()) return -1;
	else return *(--it);
}
int main()
{
	int n,i;char t[15];
	scanf("%i",&n);
	int po=0;
	for(int i=1;i<=n;i++)
	{
		int p;
		scanf("%s %i",&t,&p);
		if(!ok) continue;
		if(t[1]=='D')
		{
			bool bf=0,sf=0;
			if(emp.count(p) || buy.count(p) || sell.count(p)){ ok=0;continue;}
			if(NextBuy(p)!=-1) bf=1;
			if(PrevSell(p)!=-1) sf=1;
			if(bf && sf) ok=0;
			else if(bf) buy.insert(p);
			else if(sf) sell.insert(p);
			else emp.insert(p);
		}
		else
		{
			if(emp.count(p)) po++,emp.erase(p);
			if(buy.count(p)) buy.erase(p);
			if(sell.count(p)) sell.erase(p);
			if(NextBuy(p)!=-1 || PrevSell(p)!=-1) ok=0;
			else
			{
				for(it=emp.begin();it!=emp.end();it++)
				{
					if(*it<p) buy.insert(*it);
					else sell.insert(*it);
				}
				emp.clear();
			}
		}
	}
	//po+=emp.size();
	if(!ok) printf("0\n");
	else
	{
		int sol=1;
		while(po--) sol*=2,sol%=mod;
		if(emp.size())
		{
			int mul=emp.size()+1;
			sol=(ll)sol*mul%mod;
		}
		printf("%i\n",sol);
	}
	return 0;
}