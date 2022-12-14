#include<cstdio>

using namespace std;

int num[8];

int main()
{
	for(int i=0;i<8;i++) num[i]=-1;
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		int a;
		scanf("%d",&a);
		int n=a;
		int mask=0;
		if(a%10!=0) mask|=1;
		a/=10;
		if(a%10!=0) mask|=2;
		a/=10;
		if(a%10!=0) mask|=4;
	//	printf("%d %d\n",mask,n);
		num[mask]=n;
	}
	int cnt=0;
	int ans=-1;
	for(int i=0;i<(1<<8);i++)
	{
		bool ok=true;
		for(int j=0;j<8;j++)
		{
			if(((i>>j)&1)==1)
			{
				if(num[j]==-1) ok=false;
			}
		}
		if(ok==false) continue;
		int a=0,b=0,c=0;
		for(int j=0;j<8;j++)
		{
			if(((i>>j)&1)==1)
			{
				a+=j;
				b|=j;
				c++;
			}
		}
		if(a==b)
		{
			if(c>cnt)
			{
				ans=i;
				cnt=c;
			}
		}
	}
	printf("%d\n",cnt);
	bool fi=true;
	//for(int i=0;i<8;i++) printf("%d ",num[i]);
	//printf("\n");
	for(int i=0;i<8;i++)
	{
		if(((ans>>i)&1)==1)
		{
			if(fi)
			{
				printf("%d",num[i]);
				fi=false;
			}
			else printf(" %d",num[i]);
		}
	}
	printf("\n");
	return 0;
}