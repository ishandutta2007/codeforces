#include<cstdio>

using namespace std;

int a[55],b[55];

int Ma=0;

int cnt=0;

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d",a+i);
	int M;
	scanf("%d",&M);
	for(int i=0;i<M;i++) scanf("%d",b+i);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			if(b[j]%a[i]==0)
			{
				if(b[j]/a[i]==Ma) cnt++;
				else if(b[j]/a[i]>Ma)
				{
					Ma=b[j]/a[i];
					cnt=1;
				}
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}