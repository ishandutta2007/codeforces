#include <bits/stdc++.h>
using namespace std;
int n,cnt,lt,rt,a,b,maxi,l[300005],r[300005];
struct seg
{
	int id,from;
	bool is_l;
	bool operator < (const seg &tmp) const
	{
		if(id!=tmp.id) return id<tmp.id;
		return is_l<tmp.is_l;
	}
}Seg[600005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&l[i],&r[i]);
		Seg[2*i-1].id=l[i];
		Seg[2*i-1].is_l=true;
		Seg[2*i-1].from=i; 
		Seg[2*i].id=r[i];
		Seg[2*i].is_l=false;
		Seg[2*i].from=i;
	}
	sort(Seg+1,Seg+1+2*n);
	for(int i=1;i<=2*n;i++)
	{
		if(Seg[i].is_l)
			cnt++;
		else
			cnt--;
		if(cnt==n)
		{
			lt=Seg[i].id,rt=Seg[i+1].id;
			a=Seg[i].from,b=Seg[i+1].from;
		}
	}
	if(a==b&&a)
	{
		for(int i=1;i<=2*n;i++)
		{
			if(Seg[i].from!=a)
			{
				if(Seg[i].is_l)
					cnt++;
				else
					cnt--;
				if(cnt==n-1)
				{
					if(Seg[i+1].from==a)
						if(Seg[i+2].from==a)
							rt=Seg[i+3].id;
						else
							rt=Seg[i+2].id;
					else
						rt=Seg[i+1].id;
					lt=Seg[i].id;
				}
			}
		}
		printf("%d",rt-lt);
		return 0;
	}
	else if(rt-lt)
	{
		for(int i=1;i<=2*n;i++)
		{
			if(Seg[i].from!=a)
			{
				if(Seg[i].is_l)
					cnt++;
				else
					cnt--;
				if(cnt==n-1)
				{
					if(Seg[i+1].from==a)
						if(Seg[i+2].from==a)
							rt=Seg[i+3].id;
						else
							rt=Seg[i+2].id;
					else
						rt=Seg[i+1].id;
					lt=Seg[i].id;
				}
			}
		}
		maxi=rt-lt;
		for(int i=1;i<=2*n;i++)
		{
			if(Seg[i].from!=b)
			{
				if(Seg[i].is_l)
					cnt++;
				else
					cnt--;
				if(cnt==n-1)
				{
					if(Seg[i+1].from==b)
						if(Seg[i+2].from==b)
							rt=Seg[i+3].id;
						else
							rt=Seg[i+2].id;
					else
						rt=Seg[i+1].id;
					lt=Seg[i].id;
				}
			}
		}
		printf("%d",max(maxi,rt-lt));
	}
	else
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(l[i]==r[i]&&!a) a=i;
			else if(l[i]==r[i]&&a)
			{
				printf("0");
				return 0;
			}
		}
		for(int i=1;i<=2*n;i++)
		{
			if(Seg[i].from!=a)
			{
				if(Seg[i].is_l)
					cnt++;
				else
					cnt--;
				if(cnt==n-1)
				{
					if(Seg[i+1].from==a)
						if(Seg[i+2].from==a)
							rt=Seg[i+3].id;
						else
							rt=Seg[i+2].id;
					else
						rt=Seg[i+1].id;
					lt=Seg[i].id;
					ans=max(rt-lt,ans);
				}
			}
		}
		printf("%d",ans);
	}
	return 0;
}