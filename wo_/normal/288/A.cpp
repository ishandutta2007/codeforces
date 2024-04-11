#include<cstdio>

using namespace std;

char ans[1100100];

int main()
{
	int N,K;
	scanf("%d%d",&N,&K);
	if(N<K)
	{
		printf("-1\n");
		return 0;
	}
	if(K==1)
	{
		if(N==1)
		{
			printf("a\n");
			return 0;
		}
		printf("-1\n");
		return 0;
	}
	if(K==2)
	{
		for(int i=0;i<N;i++)
		{
			if(i%2==0) ans[i]='a';
			else ans[i]='b';
		}
		ans[N]='\0';
		printf("%s",ans);
		return 0;
	}
	for(int i=0;i<K-2;i++)
	{
		ans[N-1-i]='a'+K-1-i;
	}
	for(int i=0;i<N-(K-2);i++)
	{
		if(i%2==0) ans[i]='a';
		else ans[i]='b';
	}
	ans[N]='\0';
	printf("%s",ans);
	return 0;
}