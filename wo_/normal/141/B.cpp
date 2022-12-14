#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
	int side,x,y;
	scanf("%d%d%d",&side,&x,&y);
	x*=2;y*=2;side*=2;
	if(y<=0||y%side==0)
	{
		printf("%d\n",-1);
		return 0;
	}
	int k=y/side;
	if(k==0||k==1)
	{
		if(x>-1*side/2&&x<side/2)
		{
			printf("%d\n",k+1);
			return 0;
		}
		printf("-1\n");
		return 0;
	}
	if(k%2==0)
	{
		if(x>(-1)*side&&x<0)
		{
			printf("%d\n",3*k/2);
			return 0;
		}
		else if(x>0&&x<side)
		{
			printf("%d\n",3*k/2+1);
			return 0;
		}
		printf("%d\n",-1);
		return 0;
	}
	if(x>-1*side/2&&x<side/2)
	{
		printf("%d\n",(3*k+1)/2);
		return 0;
	}
	printf("%d\n",-1);
	return 0;
}