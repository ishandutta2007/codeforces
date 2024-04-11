#include <bits/stdc++.h>
#define Maxn 262144*2
#define modp 998244353
#define g 3
using namespace std;
int n,m;
int N,K,Q,q[Maxn],ans[Maxn],CNT[Maxn];
int pre[Maxn],inv[Maxn];
long long a[Maxn+7],b[Maxn+7];
int A[Maxn],B[Maxn];
long long power(long long a,long long b)
{
	long long ans=1,now=a,left=b;
	while (left>0)
	{
		if (left%2==1) ans=(1LL*ans*now)%modp;
		left/=2;
		now=(1LL*now*now)%modp;
	}
	return ans;
}
void ntt(long long *a, int n, int flag)
{
    for (int i=n/2,j=1;j<n;++j) 
    {
        if (i<j) swap(a[i],a[j]);
        int k=n/2;
        while (i&k) {i^=k;k/=2;}
        i^=k;
    }
    for (int k=2;k<=n;k*=2) 
    {
		long long rt=power(g,(modp-1)/k);
		if (flag==-1) rt=power(rt,modp-2);
        for (int i=0;i<n;i+=k) 
        {
			long long del=1;
            for (int j=i;j<i+k/2;++j) 
            {
                long long u=a[j],v=(1LL*a[j+k/2]*del)%modp;
                a[j]=(u+v)%modp;
                a[j+k/2]=(u+modp-v)%modp;
				del=(1LL*del*rt)%modp;
            }
        }
    }
    if (flag==-1)
    {
        long long ni=power(n,modp-2);
	    for (int i=0;i<n;i++) a[i]=(1LL*a[i]*ni)%modp;
    }
}
void multiply()
{
    ++n,++m;
    int len=2;
	while (len<m+n) len<<=1;
	ntt(a,len,1),ntt(b,len,1);
	for (int i=0;i<len;i++) a[i]=(1LL*a[i]*b[i])%modp;
	ntt(a,len,-1);
}
int calc(int x,int y)
{
    if (y<0||y>x) return 0;
    int res=(1LL*inv[y]*inv[x-y])%modp;
    return (1LL*res*pre[x])%modp;
}
int main()
{
    scanf("%d%d",&N,&K);
    for (int i=1;i<=N;i++)
    {
        scanf("%d",&A[i]);
        ++CNT[A[i]];
    }
    for (int i=1;i<=K;i++)
        scanf("%d",&B[i]);
    scanf("%d",&Q);
    for (int i=1;i<=Q;i++)
    {
        scanf("%d",&q[i]);
        q[i]/=2;
    }
    pre[0]=1;
    for (int i=1;i<=N;i++)
        pre[i]=(1LL*i*pre[i-1])%modp;
    inv[N]=(int)(power(1LL*pre[N],modp-2)%modp);
    for (int i=N;i;i--)
        inv[i-1]=(1LL*i*inv[i])%modp;
    for (int ii=1;ii<=K;ii++)
    {
        int nowA=0,nowB=0;
        for (int j=1;j<B[ii];j++)
            if (CNT[j]==1) ++nowA; 
            else if (CNT[j]>=2) ++nowB;
        nowB*=2;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        n=nowA,m=nowB;
        for (int i=0;i<=n;i++)
            a[i]=(1LL*power(2,i)*calc(n,i))%modp;
        for (int i=0;i<=m;i++)
            b[i]=(1LL*calc(m,i))%modp;
        multiply();
        for (int i=1;i<=Q;i++)
            if (q[i]>B[ii]) ans[i]=(ans[i]+a[q[i]-B[ii]-1])%modp;
    }
    for (int i=1;i<=Q;i++)
        printf("%d\n",ans[i]);
    return 0;
}