#include <bits/stdc++.h>
using namespace std;
const int Maxn=1<<18|5;
namespace polynomial
{
	const int p=998244353,inv3=(p+1)/3;
	const int Complex_i=86583718;
	int rev[Maxn];
	long long tmp[Maxn],tmp2[Maxn],tmp3[Maxn];
	long long fast_pow(long long x,long long y)
	{
		long long ans=1,now=x;
		while(y)
		{
			if(y&1) ans=(ans*now)%p;
			now=(now*now)%p;
			y>>=1;
		}
		return ans;
	}
	void get_rev(int len)
	{
		for(int i=0;i<len;i++)
			rev[i]=(rev[i>>1]>>1)|((i&1)*(len>>1));
	}
	void NTT(long long now[],int len,bool type=false)
	{
		for(int i=0;i<len;i++)
			if(i<rev[i])
				swap(now[i],now[rev[i]]);
		for(int i=1;i<len;i<<=1)
		{
			long long w=fast_pow(type?inv3:3,(p-1)/(i<<1));
			for(int j=0;j<len;j+=(i<<1))
			{
				long long l=1;
				for(int k=j;k<i+j;k++,l=(l*w)%p)
				{
					long long x=now[i+k]*l%p,y=now[k];
					now[k]=(x+y)%p;
					now[i+k]=(y-x+p)%p;
				}
			}
		}
		if(type)
		{
			long long inv=fast_pow(len,p-2); 
			for(int i=0;i<len;i++)
				now[i]=now[i]*inv%p;
		}
	}
	void multipli(long long a[],long long b[],int len)
	{
		NTT(a,len);
		NTT(b,len);
		for(int i=0;i<len;i++)
			a[i]=(a[i]*b[i])%p;
		NTT(a,len,true);
		NTT(b,len,true);
	}
	void inverse(long long val[],long long now[],int n)
	{
		if(n==1)
		{
			now[0]=fast_pow(val[0],p-2);
			return ;
		}
		inverse(val,now,n>>1);
		int len=n<<1;
		memset(tmp,0,sizeof(long long [len]));
		for(int i=0;i<n;i++)
			tmp[i]=val[i];
		get_rev(len); 
		NTT(tmp,len);
		NTT(now,len);
		for(int i=0;i<len;i++)
			now[i]=now[i]*(2-now[i]*tmp[i]%p+p)%p;
		NTT(now,len,true);
		for(int i=n;i<len;i++) now[i]=0;
	}
	void integral(long long val[],long long now[],int n)
	{
	    for(int i=n-1;i>0;i--)
	        now[i]=val[i-1]*fast_pow(i,p-2)%p;
	    now[0]=0;
	}
	void derivative(long long val[],long long now[],int n)
	{
	    for(int i=0;i<n-1;i++)
	        now[i]=val[i+1]*(i+1)%p;
	    now[n-1]=0;
	}
	void ln(long long val[],long long now[],int n)
	{
		inverse(val,tmp3,n);
		derivative(val,now,n);
		int len=n<<1;
		get_rev(len);
		multipli(tmp3,now,len);
		integral(tmp3,now,len);
	    for(int i=n;i<len;i++) now[i]=0;
		memset(tmp3,0,sizeof(long long [len]));
	}
	void exp(long long val[],long long now[],int n)
	{
		if(n==1)
		{
			now[0]=1;
			return ;
		}
		exp(val,now,n>>1);
		ln(now,tmp2,n);
		tmp2[0]=(val[0]+1-tmp2[0]+p)%p;
		for(int i=1;i<n;i++)
			tmp2[i]=(val[i]-tmp2[i]+p)%p;
		multipli(now,tmp2,n<<1);
		for(int i=n;i<(n<<1);i++) now[i]=0;
		memset(tmp2,0,sizeof(long long[n<<1]));
	}
	long long tmp4[Maxn],tmp5[Maxn];
	void sin(long long val[],long long now[],int len)
	{
		memset(tmp4,0,sizeof(long long[len]));
		for(int i=0;i<len;i++)
			val[i]=val[i]*Complex_i%p; 
		exp(val,tmp4,len);
		inverse(tmp4,now,len);
		long long _inv=fast_pow(2*Complex_i%p,p-2);
		for(int i=0;i<len;i++)
			now[i]=(tmp4[i]-now[i]+p)*_inv%p;
		_inv=fast_pow(Complex_i,p-2);
		for(int i=0;i<len;i++)
			val[i]=val[i]*_inv%p;
	}
	void cos(long long val[],long long now[],int len)
	{
		memset(tmp4,0,sizeof(long long[len]));
		for(int i=0;i<len;i++)
			val[i]=val[i]*Complex_i%p; 
		exp(val,tmp4,len);
		inverse(tmp4,now,len);
		for(int i=0;i<len;i++)
			now[i]=(tmp4[i]+now[i])*((p+1)/2)%p;
		long long _inv=fast_pow(Complex_i,p-2);
		for(int i=0;i<len;i++)
			val[i]=val[i]*_inv%p;
	}
	void poly_pow(long long x[],long long y,long long Ans[],int len)
	{
		for(int i=0;i<len;i++)
			tmp4[i]=tmp5[i]=x[i];
		Ans[0]=1;
		while(y)
		{
			if(y&1) multipli(Ans,tmp4,len);
			multipli(tmp5,tmp4,len);
			for(int i=0;i<len;i++)
				tmp4[i]=tmp5[i];
			y>>=1;
		}
		for(int i=0;i<len;i++)
			tmp4[i]=tmp5[i]=0;
	}
	long long tmp6[Maxn];
	void Sqrt(long long val[],long long now[],int len)
	{
		ln(val,tmp6,len);
		for(int i=0;i<len;i++)
			tmp6[i]=tmp6[i]*((p+1)/2)%p;
		exp(tmp6,now,len);
		memset(tmp6,0,sizeof(tmp6));
	}
}
using namespace polynomial;
int n,m,len;
long long c[Maxn],a[Maxn],b[Maxn],ans[Maxn];
int main()
{
//	freopen("CF438E.in","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&c[i]),a[c[i]]=-4;
	for(len=1;len<=1e5;len<<=1);
	a[0]=1;
	Sqrt(a,b,len);
	b[0]++;
	inverse(b,ans,len);
	for(int i=0;i<len;i++)
		ans[i]=(ans[i]*2)%p;
	for(int i=1;i<=m;i++)
		printf("%lld\n",ans[i]);
	return 0;
}