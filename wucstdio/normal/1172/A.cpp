#include<cstdio>
#include<algorithm>
#include<cstring>
#include<deque>
#include<queue>
using namespace std;
deque<int>q1;
priority_queue<int,vector<int>,greater<int> >q2;
int n,a[200005],b[200005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		q2.push(a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		q1.push_back(b[i]);
	}
	int p=n;
	while(b[p]!=1)p--;
	bool f=1;
	for(int i=p;i<=n;i++)
	{
		if(b[i]!=i-p+1)
		{
			f=0;
			break;
		}
	}
	if(f)
	{
		int now=b[n]+1;
		int rest=n-b[n];
		for(int i=1;i<=rest;i++)
		{
			if(q2.empty())
			{
				f=0;
				break;
			}
			int v=q2.top();
			q2.pop();
			if(v==0)
			{
				i--;
				continue;
			}
			if(v!=now)
			{
				f=0;
				break;
			}
			q1.push_back(v);
			int x=q1.front();
			q1.pop_front();
			q2.push(x);
			now++;
		}
		if(f)
		{
			printf("%d\n",rest);
			return 0;
		}
	}
	int ans=n;
	for(int i=1;i<=n;i++)
	{
		if(b[i]!=0)
		{
			ans=max(ans,i+n-b[i]+1);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i])
		{
			printf("%d\n",ans);
			return 0;
		}
	}
	ans=max(ans,n+1);
	printf("%d\n",ans);
	return 0;
}