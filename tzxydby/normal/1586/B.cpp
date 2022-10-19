#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,v[N];
void sol()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		v[i]=0;
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		v[b]=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(!v[i])
		{
			for(int j=1;j<=n;j++)
				if(i!=j)
					printf("%d %d\n",i,j);
			break;
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}