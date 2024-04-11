#include<bits/stdc++.h>
using namespace std;
map <long long,long long> m;
const int N=1001;
int main()
{
	long long p,i,j=0,u,v,w,state,total[N];
	scanf("%I64d",&p);
	for (i=0;i<p;i++)
	{
		scanf("%I64d",&state);
		if (state==1)
		{
			scanf("%I64d%I64d%I64d",&u,&v,&w);
			while (u!=v)
			{
				if (u<v)
				{
					u^=v;
					v^=u;
					u^=v;
				}
				if (m.count(u))
					m[u]+=w;
				else
					m[u]=w;
				u/=2;
			}
		}
		else
		{
			scanf("%I64d%I64d",&u,&v);
			total[j]=0;
			while (u!=v)
			{
				if (u<v)
				{
					u^=v;
					v^=u;
					u^=v;
				}
				if (m.count(u))
					total[j]+=m[u];
				u/=2;
			}
			j++;
		}
	}
	for (i=0;i<j;i++)
		printf("%I64d\n",total[i]);
	return 0;
}