#include<bits/stdc++.h>
using namespace std;
int f[400005];
int find(int x)
{
	return f[x]==0?x:f[x]=find(f[x]);
}
int main()
{
	int n,m,q,x,y,cnt;
	scanf("%d%d%d",&n,&m,&q);
	cnt=n+m-1;
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&x,&y);
		y+=n;
		x=find(x);
		y=find(y);
		if(x!=y)
		{
			cnt--;
			f[x]=y;
		}
	}
	printf("%d\n",cnt);
	return 0;
}