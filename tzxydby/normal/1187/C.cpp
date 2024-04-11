#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int a[N],b[N];
vector<pair<int,int>>v;
inline void wa()
{
	puts("NO");
	exit(0);
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	while(m--)
	{
		int t,l,r;
		scanf("%d%d%d",&t,&l,&r);
		if(t==1)
			for(int i=l+1;i<=r;i++)
				a[i]=1;
		else
			v.push_back(make_pair(l,r));
	}
	for(int i=0;i<v.size();i++)
	{
		int l=v[i].first,r=v[i].second,flag=0;
		for(int j=l+1;j<=r;j++)
		{
			if(a[j]==-1)
			{
				flag=1;
				break;
			}
			if(!a[j])
			{
				flag=1;
				a[j]=-1;
				break;
			}
		}
		if(!flag)
			wa();
	}
	b[0]=10000;
	for(int i=1;i<=n;i++)
		b[i]=b[i-1]+a[i];
	puts("YES");
	for(int i=1;i<=n;i++)
		printf("%d ",b[i]);
	return 0;
}