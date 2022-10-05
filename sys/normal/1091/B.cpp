#include <bits/stdc++.h>
using namespace std;
const int Maxn=1005;
int n;
struct point
{
	int x,y;
	point operator + (point tmp)
	{
		return (point){x+tmp.x,y+tmp.y};
	}
	bool operator < (const point &tmp) const
	{
		if(tmp.x!=x) return x<tmp.x;
		return y<tmp.y;
	}
}from[Maxn],to[Maxn];
map <point,int> Ma;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&from[i].x,&from[i].y);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&to[i].x,&to[i].y);
	for(int i=1;i<=n;i++)
		for(int	j=1;j<=n;j++)
			Ma[from[i]+to[j]]++;
	for(map <point,int>::iterator it=Ma.begin();it!=Ma.end();it++)
	{
		if(it->second==n)
		{
			printf("%d %d",it->first.x,it->first.y);
			return 0;
		}
	}
}