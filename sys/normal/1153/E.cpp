#include <bits/stdc++.h>
using namespace std;
int n,X[3],Y[3],cnt,x;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		printf("? %d %d %d %d\n",i,1,i,n);
		fflush(stdout);
		scanf("%d",&x);
		if(x%2)
			 X[++cnt]=i;
	}
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		printf("? %d %d %d %d\n",1,i,n,i);
		fflush(stdout);
		scanf("%d",&x);
		if(x%2)
			 Y[++cnt]=i;
	}
	if(X[2]&&Y[2])
	{
		printf("? %d %d %d %d\n",X[1],Y[1],X[1],Y[1]);
		fflush(stdout);
		scanf("%d",&x);
		if(x%2)
			printf("! %d %d %d %d\n",X[1],Y[1],X[2],Y[2]),fflush(stdout);
		else printf("! %d %d %d %d\n",X[1],Y[2],X[2],Y[1]),fflush(stdout);
		return 0;
	}
	else
	{
		if(!X[1])
		{
			int YY=(Y[1]+Y[2])/2;
			int l=1,r=n;
			while(l+1<=r)
			{
				int mid=(l+r)/2;
				printf("? 1 1 %d %d\n",mid,YY);
				fflush(stdout);
				scanf("%d",&x);
				if(x%2)
					r=mid;
				else l=mid+1;
			}
			printf("! %d %d %d %d\n",l,Y[1],l,Y[2]);
			fflush(stdout);
			return 0;
		}
		if(!Y[1])
		{
			int XX=(X[1]+X[2])/2;
			int l=1,r=n;
			while(l+1<=r)
			{
				int mid=(l+r)/2;
				printf("? 1 1 %d %d\n",XX,mid);
				fflush(stdout);
				scanf("%d",&x);
				if(x%2)
					r=mid;
				else l=mid+1;
			}
			printf("! %d %d %d %d\n",X[1],l,X[2],l);
			fflush(stdout);
			return 0;
		}
	}
	return 0;
}