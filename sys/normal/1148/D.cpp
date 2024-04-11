#include <bits/stdc++.h>
using namespace std;
const int Maxn=300005;
int ans,cnt1,cnt2,n,x[Maxn],y[Maxn];
bool del1[Maxn],del2[Maxn];
struct line
{
	int x,y,id;
	bool operator < (const line &tmp) const
	{
		return y>tmp.y;
	}
}L1[Maxn],L2[Maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=n;i++)
		if(x[i]<y[i]) L1[++cnt1].x=x[i],L1[cnt1].y=y[i],L1[cnt1].id=i;
	sort(L1+1,L1+1+cnt1);
	ans=cnt1;
	for(int i=1;i<n;i++)
		if(L1[i].y<L1[i+1].x) ans--,del1[i]=true; 
	int tmp=0;
	for(int i=1;i<=n;i++)
		if(x[i]>y[i]) L2[++cnt2].x=y[i],L2[cnt2].y=x[i],L2[cnt2].id=i;
	sort(L2+1,L2+1+cnt2);
	tmp=cnt2;
	for(int i=1;i<n;i++)
		if(L2[i].y<L2[i+1].x) tmp--,del2[i]=true;
	printf("%d\n",max(tmp,ans));
	if(tmp<ans)
	{
		for(int i=1;i<=cnt1;i++)
			if(!del1[i])
				printf("%d ",L1[i].id);
	}
	else
	{
		for(int i=cnt2;i>=1;i--)
			if(!del2[i])
				printf("%d ",L2[i].id);
	}
	return 0;
}