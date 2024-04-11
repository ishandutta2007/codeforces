#include<bits/stdc++.h>
using namespace std;
const int N=3005;
char s[N][N];
int le[N][N],ri[N][N],dia[N][N],n,m;
struct BIT
{
	int bit[N];
	void add(int x,int v)
	{
		while(x<N)
		{
			bit[x]+=v;
			x+=x&-x;
		}
	}
	int sum(int x)
	{
		int ret=0;
		while(x>0)
		{
			ret+=bit[x];
			x-=x&-x;
		}
		return ret;
	}
}b;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; 
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			if(s[i][j]=='z')
				le[i][j]=le[i][j-1]+1;
		for(int j=m;j>=1;j--)
			if(s[i][j]=='z')
				ri[i][j]=ri[i][j+1]+1;
	}
	long long ans=0;
	for(int j=1;j<=m;j++)
	{
		while(!pq.empty())
			pq.pop();
		memset(b.bit,0,sizeof(b.bit));
		for(int i=1;i<=n&&j-i+1>=1;i++)
		{
			if(s[i][j-i+1]=='z')
			{
				dia[i][j-i+1]=dia[i-1][j-i+2]+1;
				while(!pq.empty()&&pq.top().first<i)
				{
					b.add(n+1-pq.top().second,-1);
					pq.pop();
				}
				b.add(n+1-i,1);
				pq.push(make_pair(i+le[i][j-i+1]-1,i));
				ans+=b.sum(n-i+min(ri[i][j-i+1],dia[i][j-i+1]));
			}
		}
	}
	for(int i=2;i<=n;i++)
	{
		while(!pq.empty())
			pq.pop();
		memset(b.bit,0,sizeof(b.bit));
		for(int j=m;j>=1&&i+(m-j)<=n;j--)
		{
			if(s[i+m-j][j]=='z')
			{
				dia[i+(m-j)][j]=dia[i+m-j-1][j+1]+1;
				while(!pq.empty()&&pq.top().first<i+m-j)
				{
					b.add(n+1-pq.top().second,-1);
					pq.pop();
				}
				b.add(n+1-(i+m-j),1);
				pq.push(make_pair(i+m-j+le[i+m-j][j]-1,i+m-j));
				ans+=b.sum(n-(i+m-j)+min(ri[i+m-j][j],dia[i+m-j][j]));
			}
		}
	}
	printf("%I64d\n",ans);
	return 0;
}