#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const char to[4]={'R','L','U','D'};
int n,a[100005],x[100005],ope[600005][3],y[100005],num;
void write0(int x){ope[++num][0]=1,ope[num][1]=x,ope[num][2]=0;}
void write1(int x){ope[++num][0]=1,ope[num][1]=x,ope[num][2]=1;}
void write2(int x){ope[++num][0]=1,ope[num][1]=x,ope[num][2]=2;}
void write3(int x){ope[++num][0]=1,ope[num][1]=x,ope[num][2]=3;}
void work(int i)
{
	if(x[i]>0&&y[i]>0)
	{
		write0(x[i]);
		write2(y[i]);
		ope[++num][0]=2;
		write1(x[i]);
		write3(y[i]);
	}
	else if(x[i]>0&&y[i]==0)
	{
		write0(x[i]);
		ope[++num][0]=2;
		write1(x[i]);
	}
	else if(x[i]>0&&y[i]<0)
	{
		write0(x[i]);
		write3(-y[i]);
		ope[++num][0]=2;
		write1(x[i]);
		write2(-y[i]);
	}
	else if(x[i]==0&&y[i]>0)
	{
		write2(y[i]);
		ope[++num][0]=2;
		write3(y[i]);
	}
	else if(x[i]==0&&y[i]<0)
	{
		write3(-y[i]);
		ope[++num][0]=2;
		write2(-y[i]);
	}
	else if(x[i]<0&&y[i]>0)
	{
		write1(-x[i]);
		write2(y[i]);
		ope[++num][0]=2;
		write0(-x[i]);
		write3(y[i]);
	}
	else if(x[i]<0&&y[i]==0)
	{
		write1(-x[i]);
		ope[++num][0]=2;
		write0(-x[i]);
	}
	else
	{
		write1(-x[i]);
		write3(-y[i]);
		ope[++num][0]=2;
		write0(-x[i]);
		write2(-y[i]);
	}
	ope[++num][0]=3;
}
bool cmp(int a,int b)
{
	if(abs(x[a])!=abs(x[b]))return abs(x[a])<abs(x[b]);
	return abs(y[a])<abs(y[b]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		a[i]=i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)work(a[i]);
	printf("%d\n",num);
	for(int i=1;i<=num;i++)
	{
		if(ope[i][0]==2)printf("2\n");
		else if(ope[i][0]==3)printf("3\n");
		else printf("%d %d %c\n",ope[i][0],ope[i][1],to[ope[i][2]]);
	}
	return 0;
}