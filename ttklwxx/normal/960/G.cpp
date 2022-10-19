// luogu-judger-enable-o2
#include<iostream>
#include<cstdio>
#include<cmath>
#define mod 998244353
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int ksm(int n,int k)
{
	if(k==0)return 1;
	if(k==1)return n%mod;
	int nn=ksm(n,k/2);
	if(k%2==0)return 1LL*nn*nn%mod;
	else return 1LL*nn*nn%mod*1LL*n%mod;
}
int r[4000001];
inline void ntt(int* f,int tr,int flag)
{
	for(int i=0;i<tr;i++)if(i<r[i])swap(f[i],f[r[i]]);
	for(int j=1;j<tr;j<<=1)
	{
		int tt=ksm(3,(mod-1)/(j<<1));
		if(flag==-1)tt=ksm(tt,mod-2);
		for(int k=0;k<tr;k+=(j<<1))
		{
			int t=1;
			for(int l=0;l<j;l++,t=1LL*t*tt%mod)
			{
				int sthe=f[k+l],sth=1LL*f[k+j+l]*t%mod;
				f[k+l]=(sthe+sth)%mod;
				f[k+j+l]=(sthe-sth+mod)%mod;
			}
		}
	}
	if(flag==-1)
	{
		int sth=ksm(tr,mod-2);
		for(int i=0;i<tr;i++)f[i]=1LL*f[i]*sth%mod;
	}
}
int c[600001],x[600001],y[600001],yh[600001];
int jc[600001],njc[600001];
void mul(int* a,int* b,int tr,int lll)
{
	for(int i=0;i<tr;i++)x[i]=a[i],y[i]=b[i];
	for(int i=0;i<tr;i++)r[i]=(r[i>>1]>>1)|((i&1)<<(lll-1));
	ntt(x,tr,1);
	ntt(y,tr,1);
	for(int i=0;i<tr;i++)x[i]=1LL*x[i]*y[i]%mod;
	ntt(x,tr,-1); 
	for(int i=0;i<tr;i++)a[i]=x[i];
}
int d[600001];
inline void findzhi(int* a,int n,int cj,int *ans)
{
	int tr=1,lll=0;
	while(tr<=(n<<1))tr<<=1,lll++;
	c[n]=1;
	d[0]=0;
	for(int i=1;i<=n;i++)
	{
		c[n-i]=1LL*c[n-i+1]*cj%mod;
		d[i]=1LL*jc[i]*a[i]%mod;
	}
	for(int i=0;i<=n;i++)c[n-i]=1LL*c[n-i]*njc[i]%mod;
	for(int i=n+1;i<tr;i++)c[i]=0,d[i]=0;
	mul(c,d,tr,lll);
	for(int i=0;i<=n;i++)ans[i]=1LL*c[i+n]*njc[i]%mod;
	for(int i=n+1;i<tr;i++)ans[i]=0;
}
int sta[100],top;
int e[600001];
inline void solve(int*f,int n)
{
	while(n>=1)
	{
		sta[++top]=n;
		n>>=1;
	}
	n=1;
	f[1]=1;
	f[0]=0;
	int lll=0,tr=1;
	while(--top)
	{
		findzhi(f,n,n,e);
		while(tr<=(n<<1))tr<<=1,lll++;
		mul(f,e,tr,lll);
		n<<=1;
		if(n==sta[top])continue;
		for(int i=n;i>=0;i--)f[i+1]=(1LL*n*f[i+1]%mod+f[i])%mod;
		f[0]=1LL*f[0]*n%mod;
		n++;
	}
}
int a[400001],b[400001];
signed main()
{
    int n,m,tx,ty,lll=0,tr=1;
    n=read();
    tx=read();
    ty=read();
    if(n==1)
	{
		if(tx==1&&ty==1)printf("1\n");
		else printf("0\n");
		return 0;
	}
    jc[0]=1;
    for(int i=1;i<=n;i++)jc[i]=1LL*jc[i-1]*i%mod;
    njc[n]=ksm(jc[n],mod-2);
    for(int i=n-1;i>=0;i--)njc[i]=1LL*njc[i+1]*(i+1)%mod;
    solve(a,n-1);
    printf("%lld\n",1LL*jc[tx+ty-2]*njc[tx-1]%mod*njc[ty-1]%mod*a[tx+ty-2]%mod);
    return 0;
}