#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n;
int tp[maxn*2],val[maxn*2];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n*2;++i)
	{
		char opt[2];
		scanf("%s",opt);
		if(opt[0]=='+')
		{
			tp[i]=0;
		}
		else
		{
			tp[i]=1;
			int x;
			scanf("%d",&x);
			val[i]=x;
		}
	}
	int cnt=0;
	for(int i=1;i<=n*2;++i)
	{
		if(tp[i]==0)cnt++;
		else cnt--;
		if(cnt<0)
		{
			puts("NO");
			return 0;
		}
	}
	stack<int> stk;
	for(int i=n*2;i>=1;--i)
	{
		if(tp[i]==1)stk.push(val[i]);
		else val[i]=stk.top(),stk.pop();
	}
	priority_queue<int,vector<int>,greater<int> > q;
	for(int i=1;i<=n*2;++i)
	{
		if(tp[i]==0)q.push(val[i]);
		else
		{
			if(val[i]!=q.top())
			{
				puts("NO");
				return 0;
			}
			q.pop();
		}
	}
	puts("YES");
	for(int i=1;i<=n*2;++i)if(tp[i]==0)printf("%d ",val[i]);
}