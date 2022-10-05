#include <bits/stdc++.h>
using namespace std;
int cnt;
struct point
{
	int x,y;
	bool operator < (const point &tmp) const
	{
		if(x!=tmp.x) return x<tmp.x;
		return y<tmp.y;
	}
}P[5],now,ans[100005];
int main()
{
//	freopen("C.in","r",stdin);
	scanf("%d%d%d%d%d%d",&P[1].x,&P[1].y,&P[2].x,&P[2].y,&P[3].x,&P[3].y);
	sort(P+1,P+4);
	ans[0]=P[1];
	for(int i=P[1].x;i<=P[2].x;i++)
		ans[++cnt]=(point){i,P[1].y};
	now=ans[cnt];
	if(P[2].y>now.y)
		for(int i=min(P[2].y,now.y)+1;i<=max(now.y,P[2].y);i++)
			ans[++cnt]=(point){P[2].x,i};
	else
		for(int i=min(P[2].y,now.y);i<=max(now.y,P[2].y)-1;i++)
			ans[++cnt]=(point){P[2].x,i};
	if(P[3].y<=min(now.y,P[2].y))
	{
		for(int i=now.x+1;i<=P[3].x;i++)
			ans[++cnt]=(point){i,min(now.y,P[2].y)};
		for(int i=max(P[3].y,min(now.y,P[2].y))-1;i>=P[3].y;i--)
			ans[++cnt]=(point){P[3].x,i};
	}
	else if(P[3].y>=max(now.y,P[2].y))
	{
		for(int i=now.x+1;i<=P[3].x;i++)
			ans[++cnt]=(point){i,max(now.y,P[2].y)};
		for(int i=max(now.y,P[2].y)+1;i<=P[3].y;i++)
			ans[++cnt]=(point){P[3].x,i};
	}
	else
	{
		for(int i=P[3].x;i>=now.x+1;i--)
			ans[++cnt]=(point){i,P[3].y};
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)
		printf("%d %d\n",ans[i].x,ans[i].y);
	return 0;
}