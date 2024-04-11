#include<cstdio>

using namespace std;

int a[110];

int c=0;
int cnt=0;
int prev=-1;
int ans[110];

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d",a+i);
	for(int i=0;i<N;i++)
	{
		if(a[i]<0)
		{
			cnt++;
		}
		if(i!=N-1&&cnt==2&&a[i+1]<0)
		{
			ans[c]=i-prev;
			c++;
			prev=i;
			cnt=0;
		}
	}
	ans[c]=N-1-prev;
	c++;
	printf("%d\n",c);
	for(int i=0;i<c;i++)
	{
		printf("%d%c",ans[i],i==c-1?'\n':' ');
	}
	return 0;
}