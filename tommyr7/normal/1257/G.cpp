#include <bits/stdc++.h>
using namespace std;
#define modp 998244353
#define g 3
#define Maxn 1600007
int n,m,N;
int val[Maxn];
int stk[21][Maxn],size[21],tot=0;
int a[Maxn],b[Maxn];
map<int,int> mp;
int power(int a,int b)
{
    int res=1,now=a,left=b;
    while (left>0)
    {
        if (left%2==1) res=(1LL*res*now)%modp;
        left/=2;
        now=(1LL*now*now)%modp;
    }
    return res;
}
void ntt(int *a, int n, int flag)
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
		int rt=power(g,(modp-1)/k);
		if (flag==-1) rt=power(rt,modp-2);
        for (int i=0;i<n;i+=k) 
        {
			long long del=1;
            for (int j=i;j<i+k/2;++j) 
            {
                int u=a[j],v=(1LL*a[j+k/2]*del)%modp;
                a[j]=(u+v)%modp;
                a[j+k/2]=(u+modp-v)%modp;
				del=(1LL*del*rt)%modp;
            }
        }
    }
    if (flag==-1)
    {
        int ni=power(n,modp-2);
	    for (int i=0;i<n;i++) a[i]=(1LL*a[i]*ni)%modp;
    }
}
void multiply()
{
    ++n,++m;
    int len=2;
	while (len<m+n) len<<=1;
    for (int i=n;i<=len;i++)
        a[i]=0;
    for (int i=m;i<=len;i++)
        b[i]=0;
	ntt(a,len,1),ntt(b,len,1);
	for (int i=0;i<len;i++) a[i]=(1LL*a[i]*b[i])%modp;
	ntt(a,len,-1);
}
void solve(int lx,int rx)
{
    if (lx==rx)
    {
        ++tot;
        size[tot]=val[lx];
        for (int i=0;i<=val[lx];i++)
            stk[tot][i]=1;
        return;
    }
    int mid=(lx+rx)/2;
    solve(lx,mid);
    solve(mid+1,rx);
    n=size[tot-1];
    m=size[tot];
    for (int i=0;i<=n;i++)
        a[i]=stk[tot-1][i];
    for (int i=0;i<=m;i++)
        b[i]=stk[tot][i];
    multiply();
    --tot;
    size[tot]+=size[tot+1];
    for (int i=0;i<=size[tot];i++)
        stk[tot][i]=a[i];
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        ++mp[x];
    }
    N=0;
    for (map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
        val[++N]=(*it).second;
    memset(size,0,sizeof(0));
    solve(1,N);
    int ans=stk[1][size[1]/2];
    printf("%d\n",ans);
    return 0;
}