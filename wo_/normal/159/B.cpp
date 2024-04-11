#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int mark[1010][1010],cap[1010][1010];

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	memset(mark,0,sizeof(mark));
	memset(cap,0,sizeof(cap));
	for(int i=0;i<n;i++)
	{
		int ina,inb;
		scanf("%d%d",&ina,&inb);
		ina--;inb--;
		mark[ina][inb]++;
	}
	for(int i=0;i<m;i++)
	{
		int ina,inb;
		scanf("%d%d",&ina,&inb);
		ina--;inb--;
		cap[ina][inb]++;
	}
	int bo=0,no=0;
	for(int i=0;i<1010;i++)
	{
		for(int j=0;j<1010;j++)
		{
			int m=min(cap[i][j],mark[i][j]);
			bo+=m;
			cap[i][j]-=m;
			mark[i][j]-=m;
		}
	}
	for(int j=0;j<1010;j++)
	{
		int m1=0,m2=0;
		for(int i=0;i<1010;i++)
		{
			m1+=mark[i][j];
			m2+=cap[i][j];
		}
		no+=min(m1,m2);
	}
	printf("%d %d\n",bo+no,bo);
	return 0;
}