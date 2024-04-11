#include <bits/stdc++.h>
using namespace std;
struct pint
{
	long long where;
	bool id;
	bool operator < (const pint &a)const
	{
		return where<a.where;
	}
}pnt[400005];
int cnt,n;
long long ans[200005];
int main()
{
	//freopen("C.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d%I64d",&pnt[2*i-1].where,&pnt[2*i].where);
		pnt[2*i].where++;
		pnt[2*i-1].id=false;
		pnt[2*i].id=true;
	}
	sort(pnt+1,pnt+1+2*n);
	cnt=1;
	for(int i=2;i<=2*n;i++)
	{
		ans[cnt]+=(pnt[i].where-pnt[i-1].where);
		if(!pnt[i].id) cnt++;
		if(pnt[i].id)
		{
			//ans[cnt]--;
			cnt--;
		}
	}
	for(int i=1;i<=n;i++)
		printf("%I64d ",ans[i]);
	return 0;
}