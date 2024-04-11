#include <stdio.h>
#define ll long long
const int mod=1e9+7;
struct Matrix
{
	ll a[2][2];
	Matrix(){
		for(int i=0;i<2;i++) for(int j=0;j<2;j++) a[i][j]=0;
	}
	Matrix operator + (Matrix b){
		Matrix ans;
		for(int i=0;i<2;i++) for(int j=0;j<2;j++) ans.a[i][j]=(a[i][j]+b.a[i][j])%mod;
		return ans;
	}
	Matrix operator * (Matrix b)
	{
		Matrix ans;
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
			{
				for(int k=0;k<2;k++)
					ans.a[i][j]+=a[i][k]*b.a[k][j];
				ans.a[i][j]%=mod;
			}
		return ans;
	}
} fib;
Matrix pow(Matrix b, int x)
{
	Matrix ans;
	for(int i=0;i<2;i++) ans.a[i][i]=1;
	for(;x;x>>=1,b=b*b) if(x&1) ans=ans*b;
	return ans;
}
const int N=100050;
const int M=2*N;
Matrix x[M],y[M];
int ls[M],rs[M],clock,root,A[M];
void Build(int &c, int ss, int se)
{
	c=++clock;
	for(int i=0;i<2;i++) y[c].a[i][i]=1;
	if(ss==se)
	{
		x[c]=pow(fib,A[ss]);
		return;
	}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	x[c]=x[ls[c]]+x[rs[c]];
}
void Set(int c, int ss, int se, int qs, int qe, Matrix val)
{
	if(ss>qe || qs>se) return;
	if(qs<=ss && qe>=se)
	{
		y[c]=y[c]*val;
		x[c]=x[c]*val;
		return;
	}
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe,val);
	Set(rs[c],mid+1,se,qs,qe,val);
	x[c]=(x[ls[c]]+x[rs[c]])*y[c];
}
Matrix Get(int c, int ss, int se, int qs, int qe)
{
	if(ss>qe || qs>se) return Matrix();
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return (Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe))*y[c];
}
int main()
{
	fib.a[0][0]=0;
	fib.a[1][0]=1;
	fib.a[0][1]=1;
	fib.a[1][1]=1;
	int n,m,i,t,l,r,k;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) scanf("%i",&A[i]);
	Build(root,1,N);
	while(m--){
		scanf("%i %i %i",&t,&l,&r);
		if(t==1) scanf("%i",&k),Set(root,1,N,l,r,pow(fib,k));
		else printf("%lld\n",Get(root,1,N,l,r).a[1][0]);
	}
	return 0;
}