#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct Node
{
	ll id;
	ll to;
	ll mon;
	bool used;
};
struct Org
{
//	Node v[3005];
	ll tot;
};
Org org[3005];
Node all[3005];
bool cmp(Node x,Node y)
{
	return x.mon<y.mon;
}
ll org_last[3005];
int main()
{
	ll m,n;
	cin>>m>>n;
	Node t;
	ll minn=0x7fffffffffffffff;
	for(int i=1;i<=m;i++)
	{
		scanf("%lld %lld",&t.to,&t.mon);
		t.id=i;
		org[t.to].tot++;
//		minn+=t.mon;
//		org[t.to].v[org[t.to].tot]=t;
		all[i]=t;
	}
	sort(all+1,all+m+1,cmp);
//	for(int i=1;i<=n;i++)
//	{
//		printf("%d %d\n",i,org[i].tot);
//		sort(org[i].v+1,org[i].v+org[i].tot+1,cmp);
//		for(int j=1;j<=org[i].tot;j++)
//		{
//			printf("%d %d %d\n",org[i].v[j].id,org[i].v[j].to,org[i].v[j].mon);
//		}
//	}
	ll maxn=m/2+m%2;
	if(org[1].tot>maxn)
	{
		minn=0;
	}
	for(int i=org[1].tot;i<=maxn;i++)
	{
//		cout<<"ZHI\n";
		bool ok=true;
		ll sum=0;
		int now=org[1].tot;
		for(int j=1;j<=m;j++)
		{
			all[j].used=false;
		}
		for(int j=2;j<=n;j++)
		{
			org_last[j]=min(org[j].tot-i+1,org[j].tot);
//			printf("%d ",org_last[j]);
//			printf("%d %d %d\n",i,j,need);
		}
//		cout<<'\n';
//		cout<<"ADD FIRST\n";
		for(int j=1;j<=m;j++)
		{
			if(org_last[all[j].to]>0)
			{
//				printf("%d %d %d\n",all[j].to,org_last[all[j].to],sum);
				now++;
				org_last[all[j].to]--;
				all[j].used=true;
				sum+=all[j].mon;
//				printf("%d %d %d\n",all[j].to,org_last[all[j].to],sum);
			}
		}
//		cout<<"\n";
//		printf("%d %d %d\n",i,now,sum);
		if(now>=i)
		{
			minn=min(minn,sum);
		}
		else
		{
			int need=i-now;
//			printf("%d\n",need);
			for(int j=1,k=1;j<=need;j++,k++)
			{
				if(k==m+1)
				{
					sum=minn+1;
					break;
				}
				if(all[k].used==true||all[k].to==1)
				{
					j--;
					continue;
				}
				sum+=all[k].mon;
//				printf("%d %d\n",j,sum);
			}
			minn=min(minn,sum);
		}
//		printf("%d\n",sum);
	}
	cout<<minn<<endl;
	return 0;
}