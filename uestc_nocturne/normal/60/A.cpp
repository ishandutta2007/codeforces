#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,can[1200],i,j,x,flag;
char ch[20];
int main()
{
	bool CH=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	can[i]=1;
	for(i=0;i<m;i++)
	{
		scanf("%s",ch);
		scanf("%s",ch);
		scanf("%s",ch);
		if(ch[0]=='l')flag=1;
		else flag=0;
		scanf("%s",ch);
		scanf("%d",&x);
		if(flag==1)
		{
			if(x==1)CH=1;
			for(j=x;j<=n;j++)
			can[j]=0;
		}
		else
		{
			if(x==n)CH=1;
			for(j=1;j<=x;j++)
			can[j]=0;
		}
	}
	int num=0;
	for(i=1;i<=n;i++)
	if(can[i]==1)num++;
	if(num==0||CH==1)num=-1;
	printf("%d\n",num);
}