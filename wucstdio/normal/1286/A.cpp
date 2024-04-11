#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,p[105],f[105][105][2];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	memset(f,0x3f,sizeof(f));
	f[0][0][0]=f[0][0][1]=0;
	for(int i=1;i<=n;i++)
	{
		for(int c0=0;c0<=i;c0++)
		{
			if(p[i]%2||p[i]==0)
			  f[i][c0][1]=min(f[i-1][c0][0]+1,f[i-1][c0][1]);
			if(p[i]%2==0)
			  f[i][c0][0]=min(f[i-1][c0-1][0],f[i-1][c0-1][1]+1);
		}
	}
	printf("%d\n",min(f[n][n/2][0],f[n][n/2][1]));
	return 0;
}