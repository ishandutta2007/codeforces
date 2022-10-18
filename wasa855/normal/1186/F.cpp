#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	int ans=0;
	while(isdigit(ch))
	{
		ans=ans*10+ch-48;
		ch=getchar();
	}
	return ans;
}
#define N 1000005
int dgr[N];
int x[N],y[N];
bool res[N];
int t[N];
int tmp[N];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		x[i]=read();
		y[i]=read();
		dgr[x[i]]++;
		dgr[y[i]]++;
	}
	for(int i=1;i<=m;i++) t[i]=i;
	while(1)
	{
		for(int i=1;i<=n;i++)
		{
			tmp[i]=dgr[i]/2;
		}
		int ans=0;
		for(int i=1;i<=m;i++)
		{
			if(tmp[x[t[i]]]>0&&tmp[y[t[i]]]>0)
			{
				tmp[x[t[i]]]--,tmp[y[t[i]]]--;
			}
			else
			{
				res[t[i]]=true;
				ans++;
			}
		}
		if(ans<=(n+m+1)/2)
		{
			cout<<ans<<endl;
			for(int i=1;i<=m;i++)
			{
				if(res[i]==true)
				{
					printf("%d %d\n",x[i],y[i]);
				}
			}
			return 0;
		}
		memset(res,0,sizeof(res));
		random_shuffle(t+1,t+m+1);
	}
	return 0;
}