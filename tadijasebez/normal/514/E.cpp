#include <stdio.h>
#define ll long long
const int mod=1e9+7;
const int N=101;
struct Matrix
{
	int a[N][N];
	Matrix(){ for(int i=0;i<N;i++) for(int j=0;j<N;j++) a[i][j]=0;}
	Matrix operator * (Matrix b) const
	{
		Matrix c;
		int i,j,k;
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				for(k=0;k<N;k++)
				{
					c.a[i][j]+=(ll)a[i][k]*b.a[k][j]%mod;
					if(c.a[i][j]>=mod) c.a[i][j]-=mod;
				}
			}
		}
		return c;
	}
	void Print()
	{
		printf("Matrix:\n");
		int i,j;
		for(i=0;i<6;i++)
		{
			for(j=0;j<6;j++) printf("%i ",a[i][j]);
			printf("\n");
		}
	}
} base;
Matrix pow(Matrix x, int k)
{
	Matrix ret;for(int i=0;i<N;i++) ret.a[i][i]=1;
	for(;k;k>>=1,x=x*x) if(k&1) ret=ret*x;
	return ret;
}
int main()
{
	int n,x,k,i;
	scanf("%i %i",&n,&k);
	while(n--) scanf("%i",&x),base.a[1][x]++;
	base.a[0][1]=1;base.a[0][0]=1;
	for(i=2;i<N;i++) base.a[i][i-1]=1;
	Matrix sol=pow(base,k);
	printf("%i\n",(sol.a[0][1]+sol.a[1][1])%mod);
	/*sol.Print();
	Matrix tmp;for(i=0;i<N;i++) tmp.a[i][i]=1;
	for(i=1;i<=k;i++)
	{
		tmp=tmp*base;
		tmp.Print();
	}*/
	return 0;
}