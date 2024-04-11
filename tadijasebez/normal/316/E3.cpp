#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200050;
const int M=2*N;
const int mod=1e9;
struct matrix
{
	int a[2][2];
	matrix(){ a[0][0]=a[1][0]=a[0][1]=a[1][1]=0;}
	void id(){ a[0][0]=a[1][1]=1;a[0][1]=a[1][0]=0;}
	void fibonacci(){ a[0][0]=a[1][0]=a[0][1]=1;a[1][1]=0;}
};
matrix operator * (matrix a, matrix b)
{
	matrix c;
	c.a[0][0]=(ll)a.a[0][0]*b.a[0][0]%mod+(ll)a.a[0][1]*b.a[1][0]%mod;if(c.a[0][0]>=mod) c.a[0][0]-=mod;
	c.a[0][1]=(ll)a.a[0][0]*b.a[0][1]%mod+(ll)a.a[0][1]*b.a[1][1]%mod;if(c.a[0][1]>=mod) c.a[0][1]-=mod;
	c.a[1][0]=(ll)a.a[1][0]*b.a[0][0]%mod+(ll)a.a[1][1]*b.a[1][0]%mod;if(c.a[1][0]>=mod) c.a[1][0]-=mod;
	c.a[1][1]=(ll)a.a[1][0]*b.a[0][1]%mod+(ll)a.a[1][1]*b.a[1][1]%mod;if(c.a[1][1]>=mod) c.a[1][1]-=mod;
	return c;
}
matrix operator + (matrix a, matrix b)
{
	matrix c;
	c.a[0][0]=a.a[0][0]+b.a[0][0];if(c.a[0][0]>=mod) c.a[0][0]-=mod;
	c.a[0][1]=a.a[0][1]+b.a[0][1];if(c.a[0][1]>=mod) c.a[0][1]-=mod;
	c.a[1][0]=a.a[1][0]+b.a[1][0];if(c.a[1][0]>=mod) c.a[1][0]-=mod;
	c.a[1][1]=a.a[1][1]+b.a[1][1];if(c.a[1][1]>=mod) c.a[1][1]-=mod;
	return c;
}
matrix operator * (matrix a, int b)
{
	matrix c;
	c.a[0][0]=(ll)a.a[0][0]*b%mod;
	c.a[0][1]=(ll)a.a[0][1]*b%mod;
	c.a[1][0]=(ll)a.a[1][0]*b%mod;
	c.a[1][1]=(ll)a.a[1][1]*b%mod;
	return c;
}
matrix f[N],sum[N];
int ls[M],rs[M],tsz,root,a[N],lzy[M];
matrix node[M];
void Build(int &c, int ss, int se)
{
	c=++tsz;
	if(ss==se)
	{
		node[c].fibonacci();
		node[c]=node[c]*a[ss];
		return;
	}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	node[c]=node[ls[c]]+(f[mid-ss+1]*node[rs[c]]);
}
void Set(int c, int ss, int se, int qi, int x, int add=0)
{
	if(ss==se)
	{
		node[c].fibonacci();
		node[c]=node[c]*((x-add+mod)%mod);
		return;
	}
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,x,(add+lzy[c])%mod);
	else Set(rs[c],mid+1,se,qi,x,(add+lzy[c])%mod);
	node[c]=node[ls[c]]+(f[mid-ss+1]*node[rs[c]])+(sum[se-ss+1]*lzy[c]);
}
void Inc(int c, int ss, int se, int qs, int qe, int x)
{
	if(qs>qe || qs>se || ss>qe) return;
	if(qs<=ss && qe>=se)
	{
		node[c]=node[c]+(sum[se-ss+1]*x);
		lzy[c]+=x;lzy[c]%=mod;
		return;
	}
	int mid=ss+se>>1;
	Inc(ls[c],ss,mid,qs,qe,x);
	Inc(rs[c],mid+1,se,qs,qe,x);
	node[c]=node[ls[c]]+(f[mid-ss+1]*node[rs[c]])+(sum[se-ss+1]*lzy[c]);
}
matrix Get(int c, int ss, int se, int qs, int qe)
{
	if(qs<=ss && qe>=se) return node[c];
	int mid=ss+se>>1;
	int sec=min(qe,se)-max(qs,ss)+1;
	int l=min(qe,mid)-max(qs,ss)+1;
	int r=min(qe,se)-max(qs,mid+1)+1;
	matrix ans;
	if(r<=0) ans=Get(ls[c],ss,mid,qs,qe);
	else if(l<=0) ans=Get(rs[c],mid+1,se,qs,qe);
	else ans=Get(ls[c],ss,mid,qs,qe)+(f[l]*Get(rs[c],mid+1,se,qs,qe));
	ans=ans+(sum[sec]*lzy[c]);
	return ans;
}
int main()
{
	int n,q,i,t,l,r,x;
	scanf("%i %i",&n,&q);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	f[0].id();f[1].fibonacci();
	for(int i=2;i<N;i++) f[i]=f[i-1]*f[1];
	for(int i=1;i<N;i++) sum[i]=sum[i-1]+f[i];
	Build(root,1,n);
	while(q--)
	{
		scanf("%i",&t);
		if(t==1)
		{
			scanf("%i %i",&i,&x);
			Set(root,1,n,i,x);
		}
		else if(t==2)
		{
			scanf("%i %i",&l,&r);
			matrix ans=Get(root,1,n,l,r);
			printf("%i\n",ans.a[1][0]);
		}
		else
		{
			scanf("%i %i %i",&l,&r,&x);
			Inc(root,1,n,l,r,x);
		}
	}
	return 0;
}