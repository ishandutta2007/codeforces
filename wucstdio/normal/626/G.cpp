#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int n,t,q,now[200005],l[200005],num;
double p[200005],ans;
priority_queue<pair<double,int> >q1,q2,del1,del2;
int main()
{
	scanf("%d%d%d",&n,&t,&q);
	for(int i=1;i<=n;i++)scanf("%lf",&p[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&l[i]);
		q1.push(make_pair(1.0/(l[i]+1.0)*p[i],i));
	}
	for(num=1;num<=t;num++)
	{
		if(q1.empty())break;
		ans+=q1.top().first;
		int x=q1.top().second;
		q1.pop();
		now[x]++;
		if(now[x]<l[x])q1.push(make_pair((now[x]+1.0)/(l[x]+now[x]+1.0)*p[x]-now[x]/(l[x]+now[x]*1.0)*p[x],x));
	}
	num--;
	for(int i=1;i<=n;i++)
		if(now[i]>0)q2.push(make_pair((now[i]-1.0)/(l[i]+now[i]-1.0)*p[i]-now[i]/(l[i]+now[i]*1.0)*p[i],i));
	while(q--)
	{
		int type,x;
		scanf("%d%d",&type,&x);
		ans-=now[x]/(l[x]+now[x]*1.0)*p[x];
		if(now[x]<l[x])del1.push(make_pair((now[x]+1.0)/(l[x]+now[x]+1.0)*p[x]-now[x]/(l[x]+now[x]*1.0)*p[x],x));
		if(now[x]>0)del2.push(make_pair((now[x]-1.0)/(l[x]+now[x]-1.0)*p[x]-now[x]/(l[x]+now[x]*1.0)*p[x],x));
		if(type==1)l[x]++;
		else l[x]--;
		if(now[x]>l[x])now[x]--,num--;
		ans+=now[x]/(l[x]+now[x]*1.0)*p[x];
		if(now[x]<l[x])q1.push(make_pair((now[x]+1.0)/(l[x]+now[x]+1.0)*p[x]-now[x]/(l[x]+now[x]*1.0)*p[x],x));
		if(now[x]>0)q2.push(make_pair((now[x]-1.0)/(l[x]+now[x]-1.0)*p[x]-now[x]/(l[x]+now[x]*1.0)*p[x],x));
		while(1)
		{
			while(!q1.empty()&&!del1.empty()&&q1.top()==del1.top())q1.pop(),del1.pop();
			if(q1.empty()||num==t)break;
			ans+=q1.top().first;
			int x=q1.top().second;
			q1.pop();
			if(now[x]>0)del2.push(make_pair((now[x]-1.0)/(l[x]+now[x]-1.0)*p[x]-now[x]/(l[x]+now[x]*1.0)*p[x],x));
			now[x]++;
			if(now[x]<l[x])q1.push(make_pair((now[x]+1.0)/(l[x]+now[x]+1.0)*p[x]-now[x]/(l[x]+now[x]*1.0)*p[x],x));
			if(now[x]>0)q2.push(make_pair((now[x]-1.0)/(l[x]+now[x]-1.0)*p[x]-now[x]/(l[x]+now[x]*1.0)*p[x],x));
			num++;
		}
		while(1)
		{
			while(!q1.empty()&&!del1.empty()&&q1.top()==del1.top())q1.pop(),del1.pop();
			while(!q2.empty()&&!del2.empty()&&q2.top()==del2.top())q2.pop(),del2.pop();
			if(q1.empty()||q2.empty())break;
			if(q1.top().first+q2.top().first>0)
			{
				ans+=q1.top().first+q2.top().first;
				int x=q1.top().second;
				q1.pop();
				if(now[x]>0)del2.push(make_pair((now[x]-1.0)/(l[x]+now[x]-1.0)*p[x]-now[x]/(l[x]+now[x]*1.0)*p[x],x));
				now[x]++;
				if(now[x]<l[x])q1.push(make_pair((now[x]+1.0)/(l[x]+now[x]+1.0)*p[x]-now[x]/(l[x]+now[x]*1.0)*p[x],x));
				if(now[x]>0)q2.push(make_pair((now[x]-1.0)/(l[x]+now[x]-1.0)*p[x]-now[x]/(l[x]+now[x]*1.0)*p[x],x));
				x=q2.top().second;
				q2.pop();
				if(now[x]<l[x])del1.push(make_pair((now[x]+1.0)/(l[x]+now[x]+1.0)*p[x]-now[x]/(l[x]+now[x]*1.0)*p[x],x));
				now[x]--;
				if(now[x]<l[x])q1.push(make_pair((now[x]+1.0)/(l[x]+now[x]+1.0)*p[x]-now[x]/(l[x]+now[x]*1.0)*p[x],x));
				if(now[x]>0)q2.push(make_pair((now[x]-1.0)/(l[x]+now[x]-1.0)*p[x]-now[x]/(l[x]+now[x]*1.0)*p[x],x));
			}
			else break;
		}
		printf("%.12lf\n",ans);
	}
	return 0;
}