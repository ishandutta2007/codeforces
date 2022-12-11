#include <bits/stdc++.h>
#define Maxn 2000007
using namespace std;
int n;
int lx,rx;
int val[Maxn];
bool check;
int main()
{
	scanf("%d",&n);
	if (n%4==2)
	{
		printf("! -1\n");
		fflush(stdout);
		return 0;
	} else
	{
		int lx=1,rx=n/2;
		printf("? %d\n",lx);
		fflush(stdout);
		int a;
		scanf("%d",&a);
		printf("? %d\n",lx+n/2);
		fflush(stdout);
		int b;
		scanf("%d",&b);
		if (a==b)
		{
			printf("! 1\n");
			fflush(stdout);
			return 0;
		}
		check=(a<b);
		while (rx-lx>1)
		{
			int mid=(lx+rx)/2;
			int x,y;
			printf("? %d\n",mid);
			fflush(stdout);
			scanf("%d",&x);
			printf("? %d\n",mid+n/2);
			fflush(stdout);
			scanf("%d",&y);
			if (x==y)
			{
				printf("! %d\n",mid);
				fflush(stdout);
				return 0;
			}
			if ((x<y)==check) lx=mid; else rx=mid;
		}
		int mid=lx,x,y;
		printf("? %d\n",mid);
			fflush(stdout);
			scanf("%d",&x);
			printf("? %d\n",mid+n/2);
			fflush(stdout);
			scanf("%d",&y);
			if (x==y)
			{
				printf("! %d\n",mid);
				fflush(stdout);
				return 0;
			}
		mid=rx;
		printf("? %d\n",mid);
			fflush(stdout);
			scanf("%d",&x);
			printf("? %d\n",mid+n/2);
			fflush(stdout);
			scanf("%d",&y);
			if (x==y)
			{
				printf("! %d\n",mid);
				fflush(stdout);
				return 0;
			}
		printf("! -1\n");
		fflush(stdout);
		return 0;
	}
	return 0;
}