#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
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
int f[200005];
int ys[200005];
void insert(int k,int x)
{
	while(k<=200000)
	{
		f[k]+=x;
		k+=((k)&(-k)); 
	}
}
int query(int k)
{
	int ans=0;
	while(k>=1)
	{
		ans+=f[k];
		k-=((k)&(-k));
	}
	return ans;
}
struct sth
{
	int l,r,bh;
}q[200005];
bool bi(struct sth x,struct sth y)
{
	return x.l<y.l; 
}
int qans[200005];
signed main()
{
	for(int i=1;i<=200000;i++)
	{
		for(int j=2*i;j<=200000;j+=i)
		{
			ys[j]++;
		}
	}
	for(int i=1;i<=200000;i++)insert(i,ys[i]*(ys[i]-1)/2);
	int t;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		q[greg].l=read();
		q[greg].r=read(); 
		q[greg].bh=greg;
	}
	sort(q+1,q+t+1,bi);
	q[0].l=1;
	for(int i=1;i<=t;i++)
	{
		for(int j=q[i-1].l;j<=q[i].l-1;j++)
		{
			for(int k=2*j;k<=200000;k+=j)
			{
				ys[k]--;
				insert(k,-ys[k]);
			}
		}
		qans[q[i].bh]=(q[i].r-q[i].l+1)*(q[i].r-q[i].l)*(q[i].r-q[i].l-1)/6;
		qans[q[i].bh]-=query(q[i].r)-query(q[i].l-1);
		if(2*q[i].l<=q[i].r)qans[q[i].bh]-=(q[i].r/6-(2*q[i].l-1)/6);
		int tl=(5*q[i].l+1)/2,tr=q[i].r;
		if(tl<=tr)qans[q[i].bh]-=(tr/15-(tl-1)/15);
	}
	for(int i=1;i<=t;i++)printf("%lld\n",qans[i]); 
	return 0;
}