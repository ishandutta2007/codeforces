#include<bits/stdc++.h>
using namespace std;
const int max_R=1e6+5;
bool mark_p[max_R];
int prime[max_R],tot,pf[max_R];
inline void init(int R)
{
	for(int i=2;i<=R;++i)
		mark_p[i]=true;
	for(int i=2;i<=R;++i)
	{
		if(mark_p[i])
		{
			prime[++tot]=i;
			pf[i]=i;
		}
		for(int j=1;j<=tot&&i*prime[j]<=R;++j)
		{
			mark_p[i*prime[j]]=false;
			pf[i*prime[j]]=prime[j];
			if(i%prime[j]==0)
				break;
		}
	}
}
const int max_n=1e5+5;
int a[max_n];
bool chosen[max_n];
typedef pair<int,int> P;
vector<P> f[max_n];
inline int query(int x,int p)
{
	for(int i=0;i<int(f[x].size());++i)
	{
		if(f[x][i].first==p)
			return f[x][i].second;
	}
	return 0;
}
const int max_len=14+5;
int id[max_len];
int main()
{
	int n;
	scanf("%d",&n);
	int R=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		R=max(R,a[i]);
	}
	init(R);
	for(int i=1;i<=n;++i)
	{
		int x=a[i];
		while(x>1)
		{
			int p=pf[x];
			int expo=0;
			while(x%p==0)
				x/=p,++expo;
			f[i].push_back(P(p,expo));
		}
	}
	int len=0;
	for(int i=0;i<int(f[1].size());++i)
	{
		int p=f[1][i].first;
		int mn=1e9,best=-1;
		for(int j=1;j<=n;++j)
		{
			int now=query(j,p);
			if(now<mn)
			{
				mn=now;
				best=j;
			}
		}
		bool flag=false;
		for(int j=1;j<=n;++j)
		{
			if(chosen[j]&&query(j,p)==mn)
			{
				flag=true;
				break;
			}
		}
		if(!flag)
		{
			chosen[best]=true;
			id[++len]=best;
		}
	}
	if(len<7&&!chosen[1])
	{
		chosen[1]=true;
		id[++len]=1;
	}
	vector<int> rem;
	for(int i=1;i<=n;++i)
	{
		if(!chosen[i])
			rem.push_back(i);
	}
	if(!rem.empty())
	{
		int old_len=len;
		int x=rem[0];
		for(int i=0;i<int(f[x].size());++i)
		{
			int p=f[x][i].first;
			int mn=1e9,best=-1;
			for(vector<int>::iterator it=rem.begin();it!=rem.end();++it)
			{
				int j=*it;
				int now=query(j,p);
				if(now<mn)
				{
					mn=now;
					best=j;
				}
			}
			bool flag=false;
			for(vector<int>::iterator it=rem.begin();it!=rem.end();++it)
			{
				int j=*it;
				if(chosen[j]&&query(j,p)==mn)
				{
					flag=true;
					break;
				}
			}
			if(!flag)
			{
				chosen[best]=true;
				id[++len]=best;
			}
		}
		if(len-old_len<7&&!chosen[x])
		{
			chosen[x]=true;
			id[++len]=x;
		}
	}
	sort(id+1,id+len+1);
	for(int i=0;i<len;++i)
		id[i]=id[i+1];
	int tot=0;
	for(int S=1;S<(1<<len);++S)
	{
		int sz=0;
		for(int i=0;i<len;++i)
			sz+=S>>i&1;
		tot+=max(sz-2,2-sz);
	}
	printf("%d\n",tot);
	for(int S=1;S<(1<<len);++S)
	{
		vector<int> now;
		for(int i=0;i<len;++i)
		{
			if(S>>i&1)
				now.push_back(id[i]);
		}
		int sz=now.size();
		if(sz>=2)
		{
			int type=sz&1;
			for(int t=1;t<=sz-2;++t)
			{
				printf("%d %d",type,sz);
				for(int i=0;i<sz;++i)
					printf(" %d",now[i]);
				printf("\n");
			}
		}
		else
		{
			printf("0 %d",sz);
			for(int i=0;i<sz;++i)
				printf(" %d",now[i]);
			printf("\n");
		}
	}
	return 0;
}