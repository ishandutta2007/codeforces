#include<bits/stdc++.h>
using namespace std;
void sol()
{
	int u,v,a[50],b[50],n=0,m=0;
	scanf("%d%d",&u,&v);
	for(int i=0;i<50;i++)
		a[i]=b[i]=0;
	if(u>v)
	{
		puts("NO");
		return;
	}
	while(u)
	{
		a[++n]=(u&1);
		u>>=1;
	}
	while(v)
	{
		b[++m]=(v&1);
		v>>=1;
	}
	int sa=0,sb=0;
	for(int i=1;i<=m;i++)
	{
		sa+=a[i];
		sb+=b[i];
		if(sa<sb)
		{
			puts("NO");
			return;
		}
	}
	puts("YES");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}