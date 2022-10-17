#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<time.h>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int v[2020][2020];
int la[2020][2020];
int xa[2020][2020];
int n,m,q,x,y;
int d=3;
int ok(int x,int y)
{
	if(x<=0||y<=0||x>n||y>m)
		return 0;
	if(v[x][y])
		return 0;
	return v[x][y]=1;
}
int times;
int main()
{
	scanf("%d %d %d",&n,&m,&q);
	for(int i=0;i<q;i++)
	{
		scanf("%d %d",&x,&y);
		if(!xa[x][y])
			xa[x][y]=1;
		for(int xx=max(x-d,1);xx<=min(x+d,n);xx++)
			for(int yy=max(y-d,1);yy<=min(y+d,m);yy++)
				if(la[x][y]<la[xx][yy]-abs(x-xx)-abs(y-yy))
				{
					la[x][y]=la[xx][yy]-abs(x-xx)-abs(y-yy);
					xa[x][y]=1;
				}
		for(int l=la[x][y];;l++)
		{
			for(int xx=max(x-l,xa[x][y]);xx<=min(x+l,n);xx++)
			{
				
				times++;
				int yy=y-(l-abs((xx-x)));
				if(ok(xx,yy))
				{
					printf("%d %d\n",xx,yy);
					xa[x][y]=xx;
					la[x][y]=l;
					goto end;
				}
				yy=y+(l-abs((xx-x)));
				if(ok(xx,yy))
				{
					printf("%d %d\n",xx,yy);
					xa[x][y]=xx;
					la[x][y]=l;
					goto end;
				}

			}
			xa[x][y]=1;
		}
		end:;
	}
	return 0;
}