#include<cstdio>
#include<algorithm>

using namespace std;

int l[100100],r[100100];
int m=1000000007,M=-1;

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d%d",l+i,r+i);
	for(int i=0;i<N;i++) m=min(m,l[i]);
	for(int i=0;i<N;i++) M=max(M,r[i]);
	for(int i=0;i<N;i++)
	{
		if(l[i]==m&&r[i]==M)
		{
			printf("%d\n",i+1);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}