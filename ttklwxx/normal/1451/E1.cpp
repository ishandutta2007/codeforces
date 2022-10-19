#include<iostream>
#include<cstdio>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int yh[114514],tans[114514];
int main()
{
	int n,he1,he2,he3;
	n=read();
	printf("XOR 1 2\n");
	fflush(stdout);
	yh[2]=read();
	printf("AND 1 2\n");
	fflush(stdout);
	he1=2*read()+yh[2];
	printf("XOR 1 3\n");
	fflush(stdout);
	yh[3]=read();
	printf("AND 1 3\n");
	fflush(stdout);
	he2=2*read()+yh[3];
	he3=yh[2]^yh[3];
	printf("AND 2 3\n");
	fflush(stdout);
	he3+=2*read();
	tans[1]=(he1+he2-he3)/2;
	tans[2]=tans[1]^yh[2];
	tans[3]=tans[1]^yh[3];
	for(int i=4;i<=n;i++)
	{
		printf("XOR 1 %d\n",i);
		fflush(stdout);
		yh[i]=read();
		tans[i]=tans[1]^yh[i];
	}
	printf("! ");
	for(int i=1;i<=n;i++)printf("%d ",tans[i]);
	printf("\n");
	fflush(stdout);
	return 0;
}