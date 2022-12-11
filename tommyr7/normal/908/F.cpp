#include <bits/stdc++.h>
#define Maxn 300007
using namespace std;
int n,x,tp;
long long ans;
int pos[Maxn],dis[Maxn];
char op[10];
int main()
{
	scanf("%d",&n);
	ans=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%d%s",&x,op);
		if (op[0]=='R') tp=1;
		else if (op[0]=='B') tp=2;
		else tp=3;
		if (tp==3)
		{
			for (int j=1;j<=2;j++)
				if (pos[j]>0)
				{
					ans+=x-pos[j];
					dis[j]=max(dis[j],x-pos[j]);
					pos[j]=0;
				}
			if (pos[3]>0&&(dis[1]==0||dis[2]==0||dis[1]+dis[2]>x-pos[3])) ans+=x-pos[3]-dis[1]-dis[2];
			dis[1]=0,dis[2]=0,pos[3]=x;
		}
		else
		{
			int del=0;
			if (pos[tp]>0) del=x-pos[tp];
			else if (pos[3]>0) del=x-pos[3];
			ans+=del;
			dis[tp]=max(dis[tp],del);
			pos[tp]=x;
		}
	}
	printf("%lld\n",ans);
	return 0;
}