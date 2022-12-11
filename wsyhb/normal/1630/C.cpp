#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
int a[max_n],L[max_n],R[max_n],v[max_n];
bool vis[max_n],del[max_n];
struct Interval
{
	int l,r;
}I[max_n];
inline bool operator < (const Interval &a,const Interval &b)
{
	return a.l!=b.l?a.l<b.l:a.r>b.r;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		L[i]=n+1,R[i]=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		L[a[i]]=min(L[a[i]],i);
		R[a[i]]=max(R[a[i]],i);
	}
	int m=0;
	for(int i=1;i<=n;++i)
	{
		if(L[i]<R[i])
		{
			vis[L[i]]=vis[R[i]]=true;
			++v[L[i]+1],--v[R[i]]; // [L[i]+1,R[i]-1]
			I[++m].l=L[i],I[m].r=R[i];
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		v[i]+=v[i-1];
		if(!vis[i]&&v[i]>0)
			++ans;
	}
	sort(I+1,I+m+1);
	int m_new=0,far=-1;
	for(int i=1;i<=m;++i)
	{
		if(far>=I[i].r)
			ans+=2;
		else
		{
			far=I[i].r;
			I[++m_new]=I[i];
		}
	}
	m=m_new;
	for(int l=1;l<=m;++l)
	{
		int r=l;
		while(r+1<=m&&I[r+1].l<I[r].r)
			++r;
		int Last=l;
		for(int i=l+1;i<=r-1;++i)
		{
			if(I[Last].r>I[i+1].l)
			{
				del[i]=true;
				ans+=2;
			}
			else
				Last=i;
		}
		int cnt=0;
		for(int i=l;i<=r;++i)
			cnt+=!del[i];
		ans+=cnt-1;
		l=r;
	}
	printf("%d\n",ans);
	return 0;
}