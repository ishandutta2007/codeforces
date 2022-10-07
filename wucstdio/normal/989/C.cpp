#include<cstdio>
using namespace std;
int n,m,f[66][66],a,b,c,d;
int main()
{
	scanf("%d%d%d%d",&a,&b,&c,&d);
	for(int i=1;i<=25;i++)
	  for(int j=1;j<=50;j++)
		f[i][j]='c';
	for(int i=26;i<=50;i++)
	  for(int j=1;j<=50;j++)
		f[i][j]='d';
	c--;
	d--;
	for(int i=1;i<=a;i++)
		f[i/25*2+1][i%25*2+1]='a';
	for(int i=1;i<=d;i++)
		f[(a+i)/25*2+1][(a+i)%25*2+1]='d';
	for(int i=1;i<=c;i++)
		f[i/25*2+27][i%25*2+1]='c';
	for(int i=1;i<=b;i++)
		f[(c+i)/25*2+27][(c+i)%25*2+1]='b';
	printf("50 50\n");
	for(int i=1;i<=50;i++)
	{
		for(int j=1;j<=50;j++)
		  printf("%c",f[i][j]);
		printf("\n");
	}
	return 0;
}