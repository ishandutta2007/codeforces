#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
struct point
{
	int x,y;
}a[N];
bool cmp(point p,point q)
{
	return p.x!=q.x?p.x<q.x:p.y<q.y;
}
void P(int x,char c)
{
	while(x--) printf("%c",c);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
		sort(a+1,a+n+1,cmp);
		bool f=false;
		for(int i=1;i<n;i++)
			if(a[i].y>a[i+1].y)
			{
				f=true;
				break;
			}
		if(f)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for(int i=0;i<n;i++)
		{
			P(a[i+1].x-a[i].x,'R');
			P(a[i+1].y-a[i].y,'U');
		}
		printf("\n");
	}
	return 0;
}