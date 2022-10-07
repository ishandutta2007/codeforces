#include<cstdio>
#include<algorithm>
#include<cstring>
#include<deque>
#define ll long long
using namespace std;
struct Data
{
	ll x;
	int type;
	int id;
}a[1000005];
ll m,_suma[600005],_sumb[600005],*suma=_suma+300000,*sumb=_sumb+300000;
int n,pos,match[400005],d[400005];
deque<int>q;
bool cmp(Data a,Data b)
{
	return a.x<b.x;
}
int main()
{
	scanf("%lld%d",&m,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i].x);
		a[i].type=1;
		a[i].id=i;
	}
	for(int i=n+1;i<=2*n;i++)
	{
		scanf("%lld",&a[i].x);
		a[i].type=2;
		a[i].id=i;
	}
	sort(a+1,a+2*n+1,cmp);
	int na=0,nb=0;
	for(int i=1;i<=2*n;i++)
	{
		if(a[i].type==1)
		{
			d[i]=na-nb;
			suma[na-nb]+=a[i].x;
			na++;
		}
		else
		{
			d[i]=nb-na;
			sumb[nb-na]+=a[i].x;
			nb++;
		}
	}
	ll ans=1e18;
	ll nowans=0;
	int ta=0,tb=0;
	for(int i=-n;i<=n;i++)
	{
		if(i>=0)nowans-=suma[i]+sumb[i];
		else nowans+=suma[i]+sumb[i];
	}
	ans=min(ans,nowans);
	pos=0;
	for(int i=1;i<=2*n;i++)
	{
		if(a[i].type==1)
		{
			nowans+=suma[ta];
			suma[d[i]]+=m;
			nowans+=suma[ta];
			ta++;
			tb--;
			nowans-=sumb[tb]*2;
		}
		else
		{
			nowans+=sumb[tb];
			sumb[d[i]]+=m;
			nowans+=sumb[tb];
			tb++;
			ta--;
			nowans-=suma[ta]*2;
		}
		if(nowans<ans)
		{
			ans=nowans;
			pos=i;
		}
	}
	printf("%lld\n",ans);
	na=0,nb=0;
	for(int o=1;o<=2*n;o++)
	{
		int i=(o+pos-1)%(2*n)+1;
		if(a[i].type==1)
		{
			na++;
			if(na<=nb)
			{
				int j=q.front();
				q.pop_front();
				match[a[i].id]=a[j].id;
				match[a[j].id]=a[i].id;
			}
			else q.push_back(i);
		}
		else
		{
			nb++;
			if(nb<=na)
			{
				int j=q.front();
				q.pop_front();
				match[a[i].id]=a[j].id;
				match[a[j].id]=a[i].id;
			}
			else q.push_back(i);
		}
	}
	for(int i=1;i<=n;i++)printf("%d ",match[i]-n);
	printf("\n");
	return 0;
}