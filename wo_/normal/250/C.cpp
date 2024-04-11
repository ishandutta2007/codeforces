#include<cstdio>

using namespace std;

int a[100100];
int dec[100100];

int main()
{
	int N,K;
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++) scanf("%d",a+i+1);
	a[0]=0,a[N+1]=0;
	int prev=0;
	for(int i=1;i<=N;i++)
	{
		if(a[i]==a[i+1]) continue;
		if(a[prev]==a[i+1]) dec[a[i]]+=2;
		else dec[a[i]]++;
		prev=i;
	}
	int M=-1,id=-1;
	for(int i=1;i<=K;i++)
	{
		if(dec[i]>M)
		{
			id=i;
			M=dec[i];
		}
	}
	printf("%d\n",id);
	return 0;
}