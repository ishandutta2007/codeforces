/**************************/
/*It is made by decoration*/
/*gzzkal   gzzkal   gzzkal*/
/*It is made by decoration*/
/**************************/
#include <bits/stdc++.h>
using namespace std;
struct base
{
	int power,gold;
	bool operator<(const base&a)const
	{
		return power<a.power;
	}
}b[100010];
int sp[100010],sum[100010],qaq[100010];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&sp[i]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&b[i].power,&b[i].gold);
	}
	sort(b+1,b+m+1);
	for(int i=1;i<=m;i++)
	{
		sum[i]=sum[i-1]+b[i].gold; 
		qaq[i]=b[i].power;
	}
	for(int i=1;i<=n;i++)
	{
		int qwq=upper_bound(qaq+1,qaq+m+1,sp[i])-qaq-1;
		printf("%d ",sum[qwq]);
	}
}