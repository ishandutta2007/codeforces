#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MOD=10007;
int n,m,f[205][205][205],tot,sum[205];
char s[205];
struct Matrix
{
	int a[405][405];
	int*operator[](int i){return a[i];}
	Matrix(){memset(a,0,sizeof(a));}
	Matrix operator*(Matrix b)
	{
		Matrix ans;
		for(int k=1;k<=tot;k++)
		  for(int i=1;i<=k;i++)
		    for(int j=k;j<=tot;j++)
		      ans[i][j]=(ans[i][j]+a[i][k]*b[k][j])%MOD;
		return ans;
	}
}A,B;
Matrix quick_pow(Matrix x,int a)
{
	Matrix ans;
	for(int i=1;i<=tot;i++)ans[i][i]=1;
	while(a)
	{
		if(a&1)ans=ans*x;
		x=x*x;
		a>>=1;
	}
	return ans;
}
int main()
{
	scanf("%s",s+1);
	n=(int)strlen(s+1);
	f[1][n][0]=1;
	for(int len=n;len>=1;len--)
	{
		for(int l=1;l+len-1<=n;l++)
		{
			int r=l+len-1;
			for(int k=0;k<=n;k++)
			{
				f[l][r][k]%=MOD;
				if(s[l]==s[r])f[l+1][r-1][k]+=f[l][r][k];
				else
				{
					f[l][r-1][k+1]+=f[l][r][k];
					f[l+1][r][k+1]+=f[l][r][k];
				}
			}
		}
	}
	for(int i=1;i<=n+1;i++)
	  for(int j=0;j<=n;j++)
		sum[j]+=f[i][i-1][j]+f[i+1][i-1][j];
	for(int i=0;i<=n;i++)sum[i]%=MOD;
	int N1=n-1,N2=(n+1)/2;
	tot=N1+N2+N2;
	for(int i=1;i<N1+N2;i++)A[i][i+1]=1;
	for(int i=N1+1;i<=N1+N2;i++)A[i][i+N2]=1;
	for(int i=1;i<=N1;i++)A[i][i]=24;
	for(int i=N1+1;i<=N1+N2;i++)A[i][i]=25;
	for(int i=N1+N2+1;i<=N1+N2+N2;i++)A[i][i]=26;
	scanf("%d",&n);
	m=(int)strlen(s+1);
	n+=m;
	int tmp=n;
	n=(tmp+1)/2;
	B=quick_pow(A,n-1);
	A=B*A;
	int ans=0;
	for(int n1=0;n1<m;n1++)
	{
		int n2=(m-n1+1)/2;
		ans=(ans+A[N1-n1+1][N1+n2+N2]*sum[n1])%MOD;
		if((m-n1)%2==0&&tmp%2==1)ans=(ans-B[N1-n1+1][N1+n2]*sum[n1]%MOD+MOD)%MOD;
	}
	printf("%d\n",ans);
	return 0;
}