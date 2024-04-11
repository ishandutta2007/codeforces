#include <bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,k;
int a[200007];
long long f[200007][21];
long long cnt;
int sum[200007];
int p,q;
vector< pair<pair<int,int>,pair<int,int> > >que;
void Mo_algorithm1(int x)
{
	while (p>x)
	{
		cnt+=sum[a[--p]];
		++sum[a[p]];
	}
	while (p<x)
	{		
		--sum[a[p]];
		cnt-=sum[a[p++]];
	}
}
void Mo_algorithm2(int x)
{
	while (q<x)
	{
		cnt+=sum[a[++q]];
		++sum[a[q]];
	}
	while (q>x)
	{
		--sum[a[q]];
		cnt-=sum[a[q--]];
	}
}
int main()
{
	n=read(),k=read();
	for (int i=1;i<=n;i++)
		a[i]=read();
	memset(sum,0,sizeof(sum));
	++sum[a[1]];
	p=1,q=1;
	cnt=0;
	memset(f,-1,sizeof(f));
	f[0][0]=0;
	for (int i=1;i<=k;i++)
	{
		int lx=-1,rx=0;
		que.clear();
		que.push_back(make_pair(make_pair(1,n),make_pair(1,n)));
		while (lx<rx)
		{
			++lx;
			int left=que[lx].first.first,right=que[lx].first.second;
			int L=que[lx].second.first,R=que[lx].second.second;
if (left<=right&&L<=R)
{
			int mid=(left+right)/2,now=L;
			Mo_algorithm2(mid);
			Mo_algorithm1(L);
			for (int j=L;j<=R&&j<=mid;j++)
			{
				Mo_algorithm1(j);
				if (f[j-1][i-1]!=-1&&(f[mid][i]==-1||f[mid][i]>cnt+f[j-1][i-1]))
				{
					f[mid][i]=cnt+f[j-1][i-1];
					now=j;
				}
			}
			rx+=2;
			que.push_back(make_pair(make_pair(left,mid-1),make_pair(L,now)));
			que.push_back(make_pair(make_pair(mid+1,right),make_pair(now,R)));
}
		}
	}
	printf("%lld\n",f[n][k]);
	return 0;
}