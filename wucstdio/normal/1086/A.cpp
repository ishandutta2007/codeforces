#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int xa,ya,xb,yb,xc,yc,ansx,ansy,dis;
int main()
{
	dis=2147483647;
	scanf("%d%d%d%d%d%d",&xa,&ya,&xb,&yb,&xc,&yc);
	for(int i=0;i<=1000;i++)
	for(int j=0;j<=1000;j++)
	{
		int d=abs(i-xa)+abs(j-ya)+abs(i-xb)+abs(j-yb)+abs(i-xc)+abs(j-yc);
		if(d<dis)
		{
			dis=d;
			ansx=i;
			ansy=j;
		}
	}
	printf("%d\n",dis+1);
	if(xa<ansx)
	  for(int i=xa;i<ansx;i++)
	    printf("%d %d\n",i,ya);
	else
	  for(int i=ansx+1;i<=xa;i++)
		printf("%d %d\n",i,ya);
	if(ya<ansy)
	  for(int i=ya;i<ansy;i++)
	    printf("%d %d\n",ansx,i);
	else
	  for(int i=ansy+1;i<=ya;i++)
		printf("%d %d\n",ansx,i);
	
	if(xb<ansx)
	  for(int i=xb;i<ansx;i++)
	    printf("%d %d\n",i,yb);
	else
	  for(int i=ansx+1;i<=xb;i++)
		printf("%d %d\n",i,yb);
	if(yb<ansy)
	  for(int i=yb;i<ansy;i++)
	    printf("%d %d\n",ansx,i);
	else
	  for(int i=ansy+1;i<=yb;i++)
		printf("%d %d\n",ansx,i);
	if(xc<ansx)
	  for(int i=xc;i<ansx;i++)
	    printf("%d %d\n",i,yc);
	else
	  for(int i=ansx+1;i<=xc;i++)
		printf("%d %d\n",i,yc);
	if(yc<ansy)
	  for(int i=yc;i<ansy;i++)
	    printf("%d %d\n",ansx,i);
	else
	  for(int i=ansy+1;i<=yc;i++)
		printf("%d %d\n",ansx,i);
	printf("%d %d\n",ansx,ansy);
	return 0;
}