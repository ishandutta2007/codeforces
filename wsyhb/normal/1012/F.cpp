#include<bits/stdc++.h>
using namespace std;
const int max_N=22+5;
struct Trip
{
	int l,r,t,id;
}T[max_N];
inline bool operator < (const Trip &a,const Trip &b)
{
	return a.l<b.l;
}
int l[max_N],r[max_N],tot,id[max_N],L[max_N],R[max_N],ans[max_N],type[max_N];
inline bool cmp(int x,int y)
{
	return T[x].t<T[y].t;
}
const int max_S=1<<22|5;
int dp[max_S],pre[max_S];
int main()
{
	int N,P;
	scanf("%d%d",&N,&P);
	for(int i=0;i<N;++i)
	{
		int s,len,t;
		scanf("%d%d%d",&s,&len,&t);
		T[i].l=s,T[i].r=s+len-1,T[i].t=t,T[i].id=i;
	}
	sort(T,T+N);
	if(T[0].l>1)
		l[++tot]=1,r[tot]=T[0].l-1;
	for(int i=0;i+1<N;++i)
	{
		assert(T[i].r<T[i+1].l);
		if(T[i].r+1<T[i+1].l)
			l[++tot]=T[i].r+1,r[tot]=T[i+1].l-1;
	}
	if(T[N-1].r<1e9)
		l[++tot]=T[N-1].r+1,r[tot]=1e9;
	for(int i=0;i<N;++i)
		id[i]=i;
	sort(id,id+N,cmp);
	int U=(1<<N)-1;
	for(int S=1;S<=U;++S)
		dp[S]=INT_MAX;
	dp[0]=1;
	for(int S=0;S<U;++S)
	{
		int d=dp[S];
		if(d==INT_MAX)
			continue;
		int cur=1;
		while(cur<=tot&&d>r[cur])
			++cur;
		if(cur>tot)
			continue;
		int lst=-1,cnt=0;
		for(int i=0;i<N;++i)
		{
			if(S>>i&1)
			{
				if(~lst)
				{
					if(T[lst].r+1<T[i].l)
						L[++cnt]=T[lst].r+1,R[cnt]=T[i].l-1;
				}
				else
				{
					if(T[i].l>1)
						L[++cnt]=1,R[cnt]=T[i].l-1;
				}
				lst=i;
			}
		}
		if(~lst)
		{
			if(T[lst].r<1e9)
				L[++cnt]=T[lst].r+1,R[cnt]=1e9;
		}
		else
			L[++cnt]=1,R[cnt]=1e9;
		int now=1;
		for(int k=0;k<N;++k)
		{
			int i=id[k];
			if(S>>i&1)
				continue;
			bool ok=false;
			while(1)
			{
				while(cur<=tot&&d>r[cur])
					++cur;
				if(cur>tot)
					break;
				d=max(d,l[cur]);
				while(now<=cnt&&d+T[i].t>R[now])
					++now;
				if(now>cnt)
					break;
				if(d<L[now])
				{
					d=L[now];
					continue;
				}
				ok=true;
				break;
			}
			if(!ok)
				break;
			if(d+T[i].t<T[i].l)
			{
				int nxt=S|(1<<i);
				if(d+T[i].t<dp[nxt])
				{
					dp[nxt]=d+T[i].t;
					pre[nxt]=i;
				}
			}
		}
	}
	if(P==1)
	{
		if(dp[U]==INT_MAX)
		{
			puts("NO");
			return 0;
		}
		int S=U;
		while(S)
		{
			int k=pre[S];
			ans[T[k].id]=dp[S]-T[k].t;
			type[T[k].id]=1;
			S^=1<<k;
		}
	}
	else
	{
		bool ok=false;
		for(int S=0;(S<<1)<=U;++S)
		{
			if(dp[S]!=INT_MAX&&dp[S^U]!=INT_MAX)
			{
				ok=true;
				int old_S=S;
				while(S)
				{
					int k=pre[S];
					ans[T[k].id]=dp[S]-T[k].t;
					type[T[k].id]=1;
					S^=1<<k;
				}
				S=old_S^U;
				while(S)
				{
					int k=pre[S];
					ans[T[k].id]=dp[S]-T[k].t;
					type[T[k].id]=2;
					S^=1<<k;
				}
				break;
			}
		}
		if(!ok)
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	for(int i=0;i<N;++i)
		printf("%d %d\n",type[i],ans[i]);
	return 0;
}