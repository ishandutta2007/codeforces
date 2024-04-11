#include<bits/stdc++.h>
using namespace std;

struct point 
{int x,y;
};
struct point a[400010];

int n;
long long ans;

bool cmp1(point p1,point p2)
{return p1.x<p2.x;
}

bool cmp2(point p1,point p2)
{return (p1.y==p2.y && p1.x<p2.x) || p1.y<p2.y;
}

int main()
{int i,j;
 long long s=0;
 
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 	scanf("%d%d",&a[i].x,&a[i].y);
 a[0].x=2000000001;
 a[0].y=2000000001;
 sort(a+1,a+n+1,cmp1);
 s=0;
 for(i=1;i<=n;i++)
 	if(i>1 && a[i].x==a[i-1].x)
 		s++;
 	else
	{	ans+=(long long)s*(s-1)/2;
		s=1;
	}
 ans+=(long long)s*(s-1)/2;
 
 sort(a+1,a+n+1,cmp2);
 s=0;
 for(i=1;i<=n;i++)
 	if(i>1 && a[i].y==a[i-1].y)
 		s++;
 	else
	{	ans+=(long long)s*(s-1)/2;
		s=1;
	}
 ans+=(long long)s*(s-1)/2;	
 
 s=0;
 for(i=1;i<=n;i++)
 	if(i>1 && a[i].x==a[i-1].x && a[i].y==a[i-1].y)
		s++;
	else
	{	ans-=(long long)s*(s-1)/2;
		s=1;
	}
 ans-=(long long)s*(s-1)/2;
 printf("%I64d\n",ans);
 return 0;
}