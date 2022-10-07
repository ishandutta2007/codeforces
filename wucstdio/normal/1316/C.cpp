#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,p,a[1000005],b[1000005];
int main()
{
	scanf("%d%d%d",&n,&m,&p);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		a[i]%=p;
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d",&b[i]);
		b[i]%=p;
	}
	int x=0,y=0;
	while(a[x]==0)x++;
	while(b[y]==0)y++;
	printf("%d\n",x+y);
	return 0;
}