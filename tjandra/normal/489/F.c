#include<stdio.h>
typedef long long unsigned u64;
typedef unsigned u;
u D[1111][1111],C[1111],m;
char V[1111][1111],S[1111];
u F(u i,u j)
{
	if(V[i][j])return D[i][j];
	V[i][j]=1;u r=0;
	if(i==0&&j==0)return D[i][j]=1;
	if(j>=2)r=((u64)r+(((j*(j-1))>>1)*(u64)F(i+2,j-2)))%m;
	if(i>=2)r=((u64)r+(((i*(i-1))>>1)*(u64)F(i-2,j)))%m;
	if(i>=1&&j>=1)r=((u64)r+((i*j)*(u64)F(i,j-1)))%m;
	return D[i][j]=r;
}
int main()
{
	u n,q,i,j,k;char c;
	scanf("%u%u%u",&n,&q,&m);
	for(i=0;i<n;++i)C[i]=2;
	while(q--)
	{
		scanf("%s",S);
		for(i=0;i<n;++i)if(S[i]=='1')--C[i];
	}
	for(i=j=k=0;i<n;++i)
	{
		if(C[i]==1)++j;
		if(C[i]==2)++k;
	}
	printf("%u\n",F(j,k));
	return 0;
}