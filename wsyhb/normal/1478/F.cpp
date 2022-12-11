#include<bits/stdc++.h>
using namespace std;
const int max_n=5e3+5;
int x[max_n],y[max_n];
inline long long get_dis(int a,int b,int c,int d)
{
	return 1ll*(a-c)*(a-c)+1ll*(b-d)*(b-d);
}
int p[max_n];
bool vis[max_n];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d",x+i,y+i);
	p[1]=1;
	vis[1]=true;
	for(int i=2;i<=n;++i)
	{
		long long dis=0;
		for(int j=1;j<=n;++j)
		{
			if(!vis[j])
			{
				long long d=get_dis(x[p[i-1]],y[p[i-1]],x[j],y[j]);
				if(d>dis)
				{
					dis=d;
					p[i]=j;
				}
			}
		}
		vis[p[i]]=true;
	}
	for(int i=1;i<=n;++i)
		printf("%d%c",p[i],i<n?' ':'\n');
    return 0;
}