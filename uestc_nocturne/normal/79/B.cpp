#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
struct Node
{
	int x,y;
}wt[1200];
bool cmp(Node x,Node y)
{
	if(x.x==y.x)return x.y<y.y;
	return x.x<y.x;
}
int n,m,k,q,x,y,i,ans;
int main()
{
	while(~scanf("%d%d%d%d",&n,&m,&k,&q))
	{
		for(i=0;i<k;i++)
		{
			scanf("%d%d",&wt[i].x,&wt[i].y);
		}
		sort(wt,wt+k,cmp);
		while(q--)
		{
			bool ws=false;
			int ct=0;
			scanf("%d%d",&x,&y);
			for(i=0;i<k;i++)
			{
				if(wt[i].x<x||(wt[i].x==x&&wt[i].y<y))
				ct++;
				else if(wt[i].x==x&&wt[i].y==y)
				{ws=true;break;}
				else break;
			}
			x--;y--;
			ans=((x%3)*m+(y%3)-ct%3+3)%3;
			if(ws)puts("Waste");
			else
			{
				if(ans==0)puts("Carrots");
				else if(ans==1)puts("Kiwis");
				else puts("Grapes");
			}
		}
	}
}