#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,m,c,v[N],x[N],y[N],z[N],p;
char s[N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%s",&n,&m,s+1);
		c=n*m;
		for(int i=1;i<=c;i++)
			v[i]=s[i]-'0',z[i]=0;
		z[0]=0;
		p=0;
		for(int i=1;i<=c;i++)
		{
			v[i]+=v[i-1];
			if(i<=m)
				x[i]=v[i]>0;
			else
				x[i]=x[i-m]+(v[i]>v[i-m]);
		}
		for(int i=1;i<=c;i++)
		{
			if(v[i]-v[i-1]&&z[i%m]==0)
			{
				p++;
				z[i%m]=1;
			}
			y[i]=p;
		}
		for(int i=1;i<=c;i++)
			printf("%d ",x[i]+y[i]);
		puts("");
	}
	return 0;
}