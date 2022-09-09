#include <stdio.h>
#define ll long long
const int N=300050;
const int M=2*N;
const int mod=1e9+9;
struct Matrix
{
	int a[2][2];
	Matrix(){ for(int i=0;i<2;i++) for(int j=0;j<2;j++) a[i][j]=0;}
	Matrix operator + (Matrix b) const
	{
		Matrix c;
		for(int i=0;i<2;i++) for(int j=0;j<2;j++)
		{
			c.a[i][j]=a[i][j]+b.a[i][j];
			if(c.a[i][j]>=mod) c.a[i][j]-=mod;
		}
		return c;
	}
	Matrix operator * (Matrix b) const
	{
		Matrix c;
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				for(int k=0;k<2;k++)
				{
					c.a[i][j]=c.a[i][j]+(ll)a[i][k]*b.a[k][j]%mod;
					if(c.a[i][j]>=mod) c.a[i][j]-=mod;
				}
		return c;
	}
	bool operator == (Matrix b) const
	{
		for(int i=0;i<2;i++) for(int j=0;j<2;j++) if(a[i][j]!=b.a[i][j]) return 0;
		return 1;
	}
} fib,PreCalc[N],PreDP[N],y[M];
Matrix pow(Matrix a, int k)
{
	Matrix ans;
	for(int i=0;i<2;i++) ans.a[i][i]=1;
	for(;k;k>>=1,a=a*a) if(k&1) ans=ans*a;
	return ans;
}
int a[N],F[N],dp[N];
int x[M],ls[M],rs[M],clock,root;
void Build(int &c, int ss, int se)
{
	c=++clock;
	if(ss==se)
	{
		x[c]=a[ss];
		return;
	}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	x[c]=x[ls[c]]+x[rs[c]];
	if(x[c]>=mod) x[c]-=mod;
}
void Propagate(int c, int ss, int se)
{
	if(y[c]==Matrix()) return;
	int tmp=(y[c]*PreDP[se-ss]).a[0][1];
	x[c]=x[c]+tmp;
	if(x[c]>=mod) x[c]-=mod;
	if(ss!=se)
	{
		int mid=ss+se>>1;
		y[ls[c]]=y[ls[c]]+y[c];
		y[rs[c]]=y[rs[c]]+(y[c]*PreCalc[mid-ss+1]);
	}
	y[c]=Matrix();
}
void Set(int c, int ss, int se, int qs, int qe)
{
	Propagate(c,ss,se);
	if(ss>qe || qs>se) return;
	if(qs<=ss && qe>=se)
	{
		//printf("%i %i %i\n",c,ss,se);
		y[c]=y[c]+PreCalc[ss-qs+1];
		Propagate(c,ss,se);
		return;
	}
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe);
	Set(rs[c],mid+1,se,qs,qe);
	x[c]=x[ls[c]]+x[rs[c]];
	if(x[c]>=mod) x[c]-=mod;
}
int Get(int c, int ss, int se, int qs, int qe)
{
	Propagate(c,ss,se);
	if(ss>qe || qs>se) return 0;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	int ret=Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
	if(ret>=mod) ret-=mod;
	return ret;
	//return (Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe))%mod;
}
void All(int c, int ss, int se)
{
	Propagate(c,ss,se);
	if(ss==se) return;
	int mid=ss+se>>1;
	All(ls[c],ss,mid);
	All(rs[c],mid+1,se);
}
void Run()
{
	printf("\n");
	for(int i=1;i<=clock;i++) printf("%i ",x[i]);
	printf("\n");
}
int main()
{
	fib.a[0][1]=1;
	fib.a[1][0]=1;
	fib.a[1][1]=1;
	int n,i,q,l,r,t;
	scanf("%i %i",&n,&q);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=0;i<=n;i++) PreCalc[i]=pow(fib,i);
	PreDP[0]=PreCalc[0];
	for(i=1;i<=n;i++) PreDP[i]=PreDP[i-1]+PreCalc[i];
	/*F[1]=1;
	dp[1]=1;
	for(i=2;i<=n;i++)
	{
		F[i]=(F[i-1]+F[i-2])%mod;
		dp[i]=(dp[i-1]+F[i])%mod;
	}*/
	Build(root,1,n);
	//Run();
	while(q--)
	{
		scanf("%i %i %i",&t,&l,&r);
		if(t==1) Set(root,1,n,l,r);
		else printf("%i\n",Get(root,1,n,l,r));
		//All(root,1,n);
		//Run();
	}
	return 0;
}