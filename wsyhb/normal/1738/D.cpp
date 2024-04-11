#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
int a[max_n],b[max_n];
vector<int> pos[max_n];
bool vis[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",b+i);
			pos[b[i]].push_back(i);
		}
		assert(int(pos[0].empty())+int(pos[n+1].empty())==1);
		int l=0,r=n,cnt=0,k,len;
		vector<int> val;
		for(int i=1;i<=n;++i)
		{
			if(!pos[i].empty())
			{
				val.push_back(i);
				++cnt;
				vis[i]=true;
			}
		}
		if(!pos[0].empty())
		{
			for(int v:pos[0])
				r=min(r,v-1);
			for(int i=0;i<cnt/2;++i)
			{
				int v=val[i];
				l=max(l,v);
				for(int p:pos[v])
					r=min(r,p-1);
			}
			for(int i=cnt/2;i<cnt;++i)
			{
				int v=val[i];
				r=min(r,v-1);
				for(int p:pos[v])
					l=max(l,p);
			}
			assert(l>=0&&l<=n&&l==r);
			k=l,len=0;
			for(int v:pos[0])
				a[++len]=v;
			int L=1,R=len,nxt=-1;
			for(int v:pos[0])
			{
				if(vis[v])
				{
					assert(nxt==-1);
					nxt=v;
				}
			}
			for(int t=1;t<=cnt;++t)
			{
				assert(nxt!=-1);
				for(int i=L;i<=R-1;++i)
				{
					if(a[i]==nxt)
					{
						swap(a[i],a[R]);
						break;
					}
				}
				for(int v:pos[nxt])
					a[++len]=v;
				int now=nxt;
				L=R+1,R=len,nxt=-1;
				for(int v:pos[now])
				{
					if(vis[v])
					{
						assert(nxt==-1);
						nxt=v;
					}
				}
			}
		}
		else
		{
			for(int v:pos[n+1])
				l=max(l,v);
			for(int i=0;i<(cnt+1)/2;++i)
			{
				int v=val[i];
				l=max(l,v);
				for(int p:pos[v])
					r=min(r,p-1);
			}
			for(int i=(cnt+1)/2;i<cnt;++i)
			{
				int v=val[i];
				r=min(r,v-1);
				for(int p:pos[v])
					l=max(l,p);
			}
			assert(l>=0&&l<=n&&l==r);
			k=l,len=0;
			for(int v:pos[n+1])
				a[++len]=v;
			int L=1,R=len,nxt=-1;
			for(int v:pos[n+1])
			{
				if(vis[v])
				{
					assert(nxt==-1);
					nxt=v;
				}
			}
			for(int t=1;t<=cnt;++t)
			{
				assert(nxt!=-1);
				for(int i=L;i<=R-1;++i)
				{
					if(a[i]==nxt)
					{
						swap(a[i],a[R]);
						break;
					}
				}
				for(int v:pos[nxt])
					a[++len]=v;
				int now=nxt;
				L=R+1,R=len,nxt=-1;
				for(int v:pos[now])
				{
					if(vis[v])
					{
						assert(nxt==-1);
						nxt=v;
					}
				}
			}
		}
		printf("%d\n",k);
		for(int i=1;i<=n;++i)
			printf("%d%c",a[i]," \n"[i==n]);
		for(int i=0;i<=n+1;++i)
			pos[i].clear();
		for(int i=1;i<=n;++i)
			vis[i]=false;
	}
	return 0;
}