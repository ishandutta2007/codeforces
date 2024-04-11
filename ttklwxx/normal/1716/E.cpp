#include<iostream>
#include<cstdio>
#include<vector>
#define int long long
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
int a[500005],qzh[500005];
vector<int>maxr[2000005],maxl[2000005],maxf[2000005];
void solve(int l,int r,int k)
{
	//printf("%lld %lld %lld\n",l,r,k);
	if(l==r)
	{
		maxr[k].push_back(a[l]);
		maxl[k].push_back(a[l]);
		maxf[k].push_back(a[l]);
		return;
	}
	int mid=(l+r)>>1;
	solve(l,mid,k<<1);
	solve(mid+1,r,k<<1|1);
	for(int i=0;i<=mid-l;i++)
	{
		maxr[k].push_back(max(maxr[k<<1|1][i],qzh[r]-qzh[mid]+maxr[k<<1][i]));
		maxl[k].push_back(max(maxl[k<<1][i],qzh[mid]-qzh[l-1]+maxl[k<<1|1][i]));
		maxf[k].push_back(max(max(maxf[k<<1][i],maxf[k<<1|1][i]),maxr[k<<1][i]+maxl[k<<1|1][i]));
	}
	for(int i=0;i<=mid-l;i++)
	{
		maxr[k].push_back(max(maxr[k<<1][i],qzh[mid]-qzh[l-1]+maxr[k<<1|1][i]));
		maxl[k].push_back(max(maxl[k<<1|1][i],qzh[r]-qzh[mid]+maxl[k<<1][i]));
		maxf[k].push_back(max(max(maxf[k<<1][i],maxf[k<<1|1][i]),maxr[k<<1|1][i]+maxl[k<<1][i]));
	}
}
signed main()
{
	int n,q,x;
	n=read();
	for(int i=0;i<(1<<n);i++)
	{
		a[i]=read();
	}
	qzh[0]=a[0];
	for(int i=1;i<(1<<n);i++)qzh[i]=(a[i]+qzh[i-1]);
	solve(0,(1<<n)-1,1);
	int now=0;
	q=read();
	for(int i=1;i<=q;i++)
	{
		x=read();
		now^=(1<<(x));
		//printf("%lld\n",now);
		printf("%lld\n",max(maxf[1][now],0LL));
	}
	return 0;
}