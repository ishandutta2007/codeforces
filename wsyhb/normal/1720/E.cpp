#include<bits/stdc++.h>
using namespace std;
int n,k,R;
const int max_n=500+5;
int a[max_n][max_n];
const int max_R=25e4+5;
bool vis[max_R];
int val[max_n][max_n];
inline void add(int a,int b,int c,int d,int v)
{
	a=max(a,1),b=min(b,n),c=max(c,1),d=min(d,n);
	if(a>b||c>d)
		return;
	val[a][c]+=v,val[a][d+1]-=v,val[b+1][c]-=v,val[b+1][d+1]+=v;
}
int l1[max_R],r1[max_R],l2[max_R],r2[max_R];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			scanf("%d",&a[i][j]);
//			fprintf(stderr,"%d%c",a[i][j]," \n"[j==n]);
			vis[a[i][j]]=true;
		}
	R=n*n;
	int tot=0;
	for(int i=1;i<=R;++i)
		tot+=vis[i];
//	fprintf(stderr,"tot=%d\n",tot);
	if(tot<=k)
	{
		printf("%d\n",k-tot);
		return 0;
	}
	if(k==1)
	{
		puts("1");
		return 0;
	}
	for(int i=1;i<=R;++i)
	{
		if(vis[i])
			l1[i]=l2[i]=n+1,r1[i]=r2[i]=0;
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			int v=a[i][j];
			l1[v]=min(l1[v],i),r1[v]=max(r1[v],i);
			l2[v]=min(l2[v],j),r2[v]=max(r2[v],j);
		}
	for(int l=1;l<=n-1;++l)
	{
		for(int i=0;i<=n+1;++i)
			for(int j=0;j<=n+1;++j)
				val[i][j]=0;
		for(int i=1;i<=R;++i)
		{
			if(vis[i])
				add(r1[i]-l+1,l1[i],r2[i]-l+1,l2[i],1);
		}
		for(int i=1;i+l-1<=n;++i)
			for(int j=1;j+l-1<=n;++j)
			{
				val[i][j]+=val[i-1][j]+val[i][j-1]-val[i-1][j-1];
				int cnt=tot-val[i][j];
				if(k==cnt||k==cnt+1)
				{
					puts("1");
					return 0;
				}
			}
	}
	puts("2");
	return 0;
}