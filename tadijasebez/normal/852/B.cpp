#include <stdio.h>
const int mod=1e9+7;
const int N=100050,M=105;
struct Matrix
{
	int a[M][M];
	Matrix operator * (const Matrix &b) const
	{
		Matrix c;
		int i,j,k;
		for(i=0;i<M;i++) for(j=0;j<M;j++) c.a[i][j]=0;
		for(i=0;i<M;i++) for(j=0;j<M;j++) for(k=0;k<M;k++) c.a[i][j]=(c.a[i][j]+(1ll*a[i][k]*b.a[k][j]%mod))%mod;
		return c;
	}
}ans,tmp;
int b[N*10];
int sol;
int main()
{
	int n,l,m,i,u,j;
	scanf("%i %i %i",&n,&l,&m);
	for(i=0;i<n;i++) scanf("%i",&u),ans.a[0][u%m]++;
	for(i=0;i<n;i++) scanf("%i",&b[i]),b[i]%=m;
	for(j=0;j<m;j++) for(i=0;i<n;i++) tmp.a[(m+j-b[i])%m][j]++;
	l-=2;
	for(;l;tmp=tmp*tmp,l>>=1) if(l&1) ans=ans*tmp;
	for(i=0;i<n;i++) scanf("%i",&u),u%=m,sol=((long long)sol+ans.a[0][(2*m-u-b[i])%m])%mod;
	printf("%i\n",sol);
}