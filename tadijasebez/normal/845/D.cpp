#include <stdio.h>
#include <vector>
using namespace std;
vector<int> overtake,limit;
int sol;
int main()
{
	int q,i,t,MySpeed,x;
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i",&t);
		while(!limit.empty() && limit[limit.size()-1]<MySpeed) sol++,limit.pop_back();
		if(t==1)
		{
			scanf("%i",&MySpeed);
			while(!limit.empty() && limit[limit.size()-1]<MySpeed) sol++,limit.pop_back();
		}
		if(t==2)
		{
			while(!overtake.empty() && overtake[overtake.size()-1]==0) sol++,overtake.pop_back();
		}
		if(t==3)
		{
			scanf("%i",&x);
			limit.push_back(x);
		}
		if(t==4)
		{
			overtake.push_back(1);
		}
		if(t==5)
		{
			limit.push_back(1000000);
		}
		if(t==6)
		{
			overtake.push_back(0);
		}
	}
	while(!limit.empty() && limit[limit.size()-1]<MySpeed) sol++,limit.pop_back();
	printf("%i",sol);
	return 0;
}

/*#include <stdio.h>
#include <vector>
using namespace std;
bool NoOvertake[200050];
bool SpeedLimit[200050];
int NOcnt,SLcnt;
int curLimit=1000,curOvertake=1;
vector<int> overtake,limit;
int val[200050];
int main()
{
	int q,MySpeed,i,t;
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i",&t);
		if(t==1)
		{
			scanf("%i",&MySpeed);
			//if(MySpeed>curLimit) SpeedLimit[SLcnt]=true;
			i=limit.size()-1;
			while(i>-1 && limit[i]>0 && val[limit[i]]<=MySpeed) SpeedLimit[limit[i]]=true,i--;
		}
		if(t==2)
		{
			if(curOvertake==0)
			{
				i=overtake.size()-1;
				while(i>-1 && overtake[i]>0) NoOvertake[overtake[i]]=true,i--;
				//NoOvertake[NOcnt]=true;
			}
		}
		if(t==3)
		{
			scanf("%i",&curLimit);
			SLcnt++;
			val[SLcnt]=curLimit;
			if(MySpeed>curLimit) SpeedLimit[SLcnt]=true;
			//i=limit.size()-1;
			//while(i>-1 && limit[i]>0 && val[limit[i]]<=MySpeed) SpeedLimit[limit[i]]=true,i--;
			limit.push_back(SLcnt);
		}
		if(t==4)
		{
			curOvertake=1;
			overtake.push_back(0);
		}
		if(t==5)
		{
			curLimit=1000;
			limit.push_back(0);
		}
		if(t==6)
		{
			curOvertake=0;
			NOcnt++;
			overtake.push_back(NOcnt);
		}
	}
	int sol=0;
	for(i=0;i<=NOcnt;i++) sol+=NoOvertake[i];
	for(i=0;i<=SLcnt;i++) sol+=SpeedLimit[i];
	printf("%i\n",sol);
	return 0;
}*/