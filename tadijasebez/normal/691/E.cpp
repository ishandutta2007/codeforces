#include <stdio.h>
#define ll long long
const int mod=1e9+7;
const int N=105;
int n;
struct Matrix
{
	int a[N][N];
	void init(){ int i,j;for(i=0;i<n;i++) for(j=0;j<n;j++) a[i][j]=0;for(i=0;i<n;i++) a[i][i]=1;}
	Matrix(){ init();}
	void Print(){ for(int i=0;i<n;i++) for(int j=0;j<n;j++) printf("%i%c",a[i][j],j==n-1?'\n':' ');}
} f;
Matrix operator * (Matrix a, Matrix b)
{
	Matrix c;
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			c.a[i][j]=0;
			for(k=0;k<n;k++)
			{
				c.a[i][j]+=(ll)a.a[i][k]*b.a[k][j]%mod;
				if(c.a[i][j]>=mod) c.a[i][j]-=mod;
			}
		}
	}
	return c;
}
Matrix pow(Matrix x, ll k)
{
	Matrix ret;ret.init();
	for(;k;k>>=1,x=x*x) if(k&1) ret=ret*x;
	return ret;
}
ll a[N];
int count(ll x){ int sol=0;while(x) sol+=x&1,x>>=1;return sol;}
int main()
{
	int i,j;ll k;
	scanf("%i %lld",&n,&k);
	for(i=0;i<n;i++) scanf("%lld",&a[i]);
	f.init();
	for(i=0;i<n;i++) for(j=0;j<n;j++) if(count(a[i]^a[j])%3==0) f.a[i][j]=1;
	//f.Print();
	//Matrix tmp=f*f;
	f=pow(f,k-1);
	int sol=0;
	for(i=0;i<n;i++) for(j=0;j<n;j++) sol+=f.a[i][j],sol=sol>=mod?sol-mod:sol;
	//f.Print();
	//tmp.Print();
	printf("%i\n",sol);
	return 0;
}