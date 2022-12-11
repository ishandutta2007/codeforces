#include<bits/stdc++.h>
using namespace std;
const int G=3;
const int max_N=1<<19|5;
struct Poly
{
	int P;
	inline Poly(int mod)
	{
		assert(mod>0);
		P=mod;
	}
	inline void add(int &a,int b)
	{
	    a=a+b-(a+b>=P?P:0);
	}
	inline void sub(int &a,int b)
	{
	    a=a-b+(a-b<0?P:0);
	}
	inline void mul(int &a,int b)
	{
	    a=1ll*a*b%P;
	}
	inline int get_sum(int a,int b)
	{
	    return a+b-(a+b>=P?P:0);
	}
	inline int get_dif(int a,int b)
	{
	    return a-b+(a-b<0?P:0);
	}
	inline int get_pro(int a,int b)
	{
	    return 1ll*a*b%P; 
	}
	inline int get_power(int a,int n)
	{
	    int res=1;
	    while(n>0)
	    {
	        res=(n&1)?get_pro(res,a):res;
	        mul(a,a);
	        n>>=1;
	    }
	    return res;
	}
	inline int get_inv(int x)
	{
	    return get_power(x,P-2);
	}
	int N;
	int f[max_N],g[max_N],r[max_N],w[max_N];
	void NTT(int *f,int n,int ty=1)
	{
	    if(n!=N)
	    {
	        N=n;
	        for(int i=0;i<N;++i)
	            r[i]=(r[i>>1]>>1)|(i&1?N>>1:0);
	    }
	    for(int i=0;i<N;++i)
	    {
	        if(i<r[i])
	            swap(f[i],f[r[i]]);
	    }
	    w[0]=1;
	    for(int o=2,k=1;o<=N;o<<=1,k<<=1)
	    {
	        int w_n=get_power(G,(P-1)+ty*(P-1)/o);
	        for(int i=k-2;i>=0;i-=2)
	            w[i+1]=get_pro(w[i]=w[i>>1],w_n);
	        for(int i=0;i<N;i+=o)
	            for(int j=i;j<i+k;++j)
	            {
	                int t0=f[j],t1=get_pro(f[j+k],w[j-i]);
	                f[j]=get_sum(t0,t1),f[j+k]=get_dif(t0,t1);
	            }
	    }
	    if(ty==-1)
	    {
	        int t=get_inv(N);
	        for(int i=0;i<N;++i)
	            mul(f[i],t);
	    }
	}
}p1(998244353),p2(1004535809);
const int max_n=2e5+5;
int a[max_n];
const int max_R=1e6+5;
int ans[max_R];
int main()
{
	int n,x,y;
	scanf("%d%d%d",&n,&x,&y);
	for(int i=0;i<=n;++i)
	{
		scanf("%d",a+i);
		p1.f[a[i]]+=1,p1.g[x-a[i]]+=1;
		p2.f[a[i]]+=1,p2.g[x-a[i]]+=1;
	}
    int N=1;
    while(N<=2*x)
        N<<=1;
    p1.NTT(p1.f,N),p1.NTT(p1.g,N);
    for(int i=0;i<N;++i)
        p1.f[i]=1ll*p1.f[i]*p1.g[i]%p1.P;
   	p1.NTT(p1.f,N,-1);
    p2.NTT(p2.f,N),p2.NTT(p2.g,N);
    for(int i=0;i<N;++i)
        p2.f[i]=1ll*p2.f[i]*p2.g[i]%p2.P;
   	p2.NTT(p2.f,N,-1);
    const int R=1e6;
    for(int i=x+1;i<=2*x;++i)
    {
		if(p1.f[i]||p2.f[i])
		{
			int L=2*(i-x+y);
			for(int j=L;j<=R;j+=L)
				ans[j]=max(ans[j],L);
		}
	}
	int q;
	scanf("%d",&q);
	for(int t=1;t<=q;++t)
	{
		int l;
		scanf("%d",&l);
		printf("%d%c",ans[l]?ans[l]:-1,t<q?' ':'\n');
	}
    return 0;
}