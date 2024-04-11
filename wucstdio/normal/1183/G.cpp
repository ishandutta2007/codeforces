#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int t,n,cnt0[200005],cnt1[200005],sa[200005];
priority_queue<int>q;
bool cmp(int a,int b)
{
	return cnt0[a]+cnt1[a]>cnt0[b]+cnt1[b]||(cnt0[a]+cnt1[a]==cnt0[b]+cnt1[b]&&cnt0[a]>cnt0[b]);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if(y)cnt0[x]++;
			else cnt1[x]++;
			sa[i]=i;
		}
		while(!q.empty())q.pop();
		sort(sa+1,sa+n+1,cmp);
		int now=1,ans=0,num=0;
		for(int i=n;i>=1;i--)
		{
			while(cnt0[sa[now]]+cnt1[sa[now]]>=i)
			{
				q.push(cnt0[sa[now]]);
				now++;
			}
			if(q.empty())continue;
			int v=q.top();
			q.pop();
			ans+=i;
			num+=min(v,i);
		}
		printf("%d %d\n",ans,num);
		for(int i=1;i<=n;i++)cnt0[i]=cnt1[i]=0;
	}
	return 0;
}