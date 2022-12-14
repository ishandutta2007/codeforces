#include<cstdio>

using namespace std;

int ans[110];
int b[110][110];

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++) scanf("%d",&b[i][j]);
	}
	for(int bit=30;bit>=0;bit--)
	{
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				if(i==j) continue;
				if((b[i][j]&(1<<bit))!=0)
				{
					ans[i]|=(1<<bit);
					ans[j]|=(1<<bit);
				}
			}
		}
	}
	for(int i=0;i<N;i++)
	{
		printf("%d%c",ans[i],i==N-1?'\n':' ');
	}
	return 0;
}