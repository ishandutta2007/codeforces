#include<stdio.h>
#include<string.h>
int mo=1000000007;
long long n;
int m,l,z;
int a[52][52];
int b[52][52];
char s[3];
int C(char c)
{
	if(c<'a')
		return c-'A'+26;
	return c-'a';
}
void mul(int a[52][52],int b[52][52],int c[52][52])
{
	int _[52][52]={};
	for(int i=0;i<m;i++)
		for(int j=0;j<m;j++)
			for(int k=0;k<m;k++)
				_[i][j]=(_[i][j]+(long long)a[i][k]*b[k][j])%mo;
	memcpy(c,_,sizeof _);
}
int main()
{
	scanf("%I64d %d %d",&n,&m,&l);
	for(int i=0;i<m;i++)
		a[0][i]=1;
	for(int i=0;i<m;i++)
		for(int j=0;j<m;j++)
			b[i][j]=1;
	for(int i=0;i<l;i++)
		scanf("%s",s),b[C(s[0])][C(s[1])]=0;
	for(n--;n;n>>=1)
	{
		if(n&1)
			mul(a,b,a);
		mul(b,b,b);
	}
	for(int i=0;i<m;i++)
		z=(z+a[0][i])%mo;
	printf("%d\n",z);
	return 0;
}