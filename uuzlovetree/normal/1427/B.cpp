#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int T,n,k;
char s[maxn];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		int ans=0,W=0,L=0;
		priority_queue< int,vector<int>,greater<int> > q;
		int st=0;
		for(int i=1;i<=n;++i)if(s[i]=='W'){st=i;break;}
		if(!st)
		{
			printf("%d\n",max(0,2*min(n,k)-1));
			continue;
		}
		for(int i=st;i<=n;++i)
		{
			if(s[i]=='L')
			{
				L++;
				W=0;
			}
			else
			{
				if(L)
				{
					q.push(L);
					L=0;
				}
				if(!W)ans+=1;else ans+=2;
				W++;
			}
		}
		while(!q.empty())
		{
			int u=q.top();q.pop();
			if(k<u)
			{
				ans+=2*k;
				k=0;
			}
			else
			{
				ans+=2*u+1;
				k-=u;
			}
			if(!k)break;
		}
		if(k>0)ans=min(ans+2*k,2*n-1);
		printf("%d\n",ans);
	}
}