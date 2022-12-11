#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
vector<int> edge[max_n];
int q[max_n],_head,_tail;
int dep[max_n],l[max_n],r[max_n];
vector<int> id[max_n];
int cnt[max_n];
bool dp[max_n];
int k[max_n],v[max_n],c[max_n];
char ans[max_n];
int main()
{
	int n,cnt_a,cnt_b;
	scanf("%d%d",&n,&cnt_a);
	cnt_b=n-cnt_a;
	for(int i=2;i<=n;++i)
	{
		int p;
		scanf("%d",&p);
		edge[p].push_back(i);
	}
	dep[1]=1;
	_head=1,_tail=0;
	q[++_tail]=1;
	while(_head<=_tail)
	{
		int x=q[_head++];
		for(int i=0;i<int(edge[x].size());++i)
		{
			int y=edge[x][i];
			dep[y]=dep[x]+1;
			q[++_tail]=y;
		}
	}
	for(int i=1;i<=n;++i)
	{
		int x=dep[q[i]];
		if(!l[x])
			l[x]=i;
		r[x]=i;
	}
	int d=dep[q[n]];
	for(int i=1;i<=d;++i)
	{
		id[r[i]-l[i]+1].push_back(i);
		++cnt[r[i]-l[i]+1];
	}
	dp[0]=true;
	for(int i=1;i<=n;++i)
	{
		if(cnt[i]>0)
		{
			for(int j=0;j<i;++j)
			{
				if(dp[j])
					k[j]=0;
				else
					k[j]=1e9;
			}
			for(int j=i;j<=n;++j)
			{
				if(dp[j])
					k[j]=0;
				else
				{
					k[j]=k[j-i]+1;
					if(k[j]<=cnt[i])
					{
						dp[j]=true;
						v[j]=i;
						c[j]=k[j];
					}
				}
			}
		}
	}
	if(dp[cnt_a])
	{
		int now=cnt_a;
		while(now)
		{
			for(int i=0;i<c[now];++i)
			{
				int x=id[v[now]][i];
				for(int j=l[x];j<=r[x];++j)
					ans[q[j]]='a';
			}
			now-=v[now]*c[now];
		}
		for(int i=1;i<=n;++i)
		{
			if(ans[i]!='a')
				ans[i]='b';
		}
		ans[n+1]='\0';
		printf("%d\n%s\n",d,ans+1);
		return 0;
	}
	for(int i=1;i<=d;++i)
	{
		int sz=r[i]-l[i]+1;
		if(cnt_a>=sz)
		{
			for(int j=l[i];j<=r[i];++j)
				ans[q[j]]='a';
			cnt_a-=sz;
		}
		else if(cnt_b>=sz)
		{
			for(int j=l[i];j<=r[i];++j)
				ans[q[j]]='b';
			cnt_b-=sz;
		}
		else
		{
			if(cnt_a>=cnt_b)
			{
				for(int j=l[i];j<=r[i];++j)
				{
					if(edge[q[j]].size())
					{
						ans[q[j]]='a';
						--cnt_a;
					}
				}
				for(int j=l[i];j<=r[i];++j)
				{
					if(edge[q[j]].empty())
					{
						if(cnt_a>0)
						{
							ans[q[j]]='a';
							--cnt_a;
						}
						else
						{
							ans[q[j]]='b';
							--cnt_b;
						}
					}
				}
				for(int j=r[i]+1;j<=n;++j)
				{
					ans[q[j]]='b';
					--cnt_b;
				}
			}
			else
			{
				for(int j=l[i];j<=r[i];++j)
				{
					if(edge[q[j]].size())
					{
						ans[q[j]]='b';
						--cnt_b;
					}
				}
				for(int j=l[i];j<=r[i];++j)
				{
					if(edge[q[j]].empty())
					{
						if(cnt_b>0)
						{
							ans[q[j]]='b';
							--cnt_b;
						}
						else
						{
							ans[q[j]]='a';
							--cnt_a;
						}
					}
				}
				for(int j=r[i]+1;j<=n;++j)
				{
					ans[q[j]]='a';
					--cnt_a;
				}
			}
			break;
		}
	}
	assert(cnt_a==0&&cnt_b==0);
	ans[n+1]='\0';
	printf("%d\n%s\n",d+1,ans+1);
	return 0;
}