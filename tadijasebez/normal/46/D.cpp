#include <stdio.h>
#include <set>
using namespace std;
#define mp make_pair
set<pair<int,int> > car;
set<pair<int,int> >::iterator it;
const int N=100050;
int x[N],len[N];
int main()
{
	int l,b,f,n,i,t,id;
	scanf("%i %i %i",&l,&b,&f);
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i %i",&t,&len[i]);
		if(t==1)
		{
			if(car.empty())
			{
				x[i]=0;
				if(len[i]>l) x[i]=-1;
				else car.insert(mp(x[i],x[i]+len[i]));
				printf("%i\n",x[i]);
				continue;
			}
			x[i]=-1;
			int y=car.begin()->first;
			if(y>=len[i]+f)
			{
				x[i]=0;
				car.insert(mp(0,len[i]));
				printf("0\n");
				continue;
			}
			y=car.begin()->second;
			it=car.begin();it++;
			for(;it!=car.end();it++)
			{
				int space=it->first-y;
				//printf("y:%i s:%i\n",y,space);
				if(space>=b+f+len[i])
				{
					x[i]=y+b;
					car.insert(mp(x[i],x[i]+len[i]));
					break;
				}
				y=it->second;
			}
			if(!(~x[i]))
			{
				if(y+b+len[i]<=l)
				{
					x[i]=y+b;
					car.insert(mp(x[i],x[i]+len[i]));
				}
			}
			printf("%i\n",x[i]);
		}
		else
		{
			id=len[i];
			car.erase(mp(x[id],x[id]+len[id]));
		}
	}
	return 0;
}